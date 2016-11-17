# -*- coding: utf-8 -*-
require './const.rb'
require './cmn.rb'

TETROMINOES = {
  BlockType::I => [[BlockType::I,BlockType::I,BlockType::I,BlockType::I]],
  BlockType::O => [
    [BlockType::O,BlockType::O],
    [BlockType::O,BlockType::O]
  ],
  BlockType::S => [
    [BlockType::EMPTY,BlockType::S,BlockType::S],
    [BlockType::S,BlockType::S,BlockType::EMPTY]
  ],
  BlockType::Z => [
    [BlockType::Z,BlockType::Z,BlockType::EMPTY],
    [BlockType::EMPTY,BlockType::Z,BlockType::Z]
  ],
  BlockType::J => [
    [BlockType::J,BlockType::EMPTY,BlockType::EMPTY],
    [BlockType::J,BlockType::J,BlockType::J]
  ],
  BlockType::L => [
    [BlockType::EMPTY,BlockType::EMPTY,BlockType::L],
    [BlockType::L,BlockType::L,BlockType::L]
  ],
  BlockType::T => [
    [BlockType::EMPTY,BlockType::T,BlockType::EMPTY],
    [BlockType::T,BlockType::T,BlockType::T]
  ],
}



class Tetromino < Array2d
  attr_reader :block_type

  def initialize(block_type)
    @block_type = block_type
    @ary = TETROMINOES[@block_type].map{|row| row.clone}
  end

  def hrev() @ary.each{|a| a.reverse!} end
  def vrev() @ary.reverse! end
  def ccw()  @ary=@ary.transpose; self.vrev() end
  def cw()   @ary=@ary.transpose; self.hrev() end

  def width() return @ary[0].size end
  def height() return @ary.size end
end

class CurrentMino < Tetromino
  attr_accessor :x, :y
  def initialize(x, y, block_type)
    super(block_type)
    @x, @y = x, y
  end
end

class TetrisBoard < Array2d
  WIDTH = 10
  HEIGHT = DISPLAY_LINES
  MAX_HEIGHT = DISPLAY_LINES + 4

  def initialize()
    super(WIDTH, MAX_HEIGHT, BlockType::EMPTY)
  end

  def _trans(x, y)
    return x, MAX_HEIGHT-y-1
  end

  def set(x, y, type)
    return if x<0 || x>=WIDTH || y<0 || y>=MAX_HEIGHT
    self[x, y] = type
  end
  def at(x, y)
    return nil if x<0 || x>=WIDTH || y<0 || y>=MAX_HEIGHT
    return self[x, y]
  end

  def placeable?(x, y, mino)
    mino.each{|u, v, bt|
      if bt != BlockType::EMPTY && at(x+u, y+v) != BlockType::EMPTY then
        return false
      end
    }
    return true
  end
  def filled_line?(line)
    return row(line).index(BlockType::EMPTY) == nil
  end
  def shrink_line(line)
    # 指定行を空にして，それより上の行を詰める
    (line..MAX_HEIGHT-2).each{|y|
      WIDTH.times{|i|
        row(y)[i] = row(y+1)[i]
      }
    }
  end
end

class TetrisWorld
  attr_reader :status, :past_count, :spawn_count, :line_count

  def initialize()
    @board = TetrisBoard.new()
    @nexts = []
    @cmino = nil
    @moved = false
    @status = Status::SPAWN
    @past_count = 0
    @spawn_count = 0
    @line_count = 0

    @state_func = {
      Status::WAIT => :state_wait,
      Status::SPAWN => :state_spawn,
      Status::INPUT => :state_input,
      Status::CHECK => :state_check, # ラインのチェックと消去を分けて時間差を出したい
      Status::GAMEOVER => :state_gameover
    }

    MAX_NEXT_NUM.times{push_random_mino_to_nexts}
  end

  def get_board() return @board.clone() end
  def get_cmino() return @cmino.clone() if !@cmino.nil? end
  def get_nexts() return @nexts.clone() end

  def operatable?()
    return false if @cmino == nil
    return false if @status != Status::INPUT
    return true
  end
  def move_cmino(dx, dy)  # return true if moved else false
    return false if !operatable?

    placeable = @board.placeable?(@cmino.x+dx, @cmino.y+dy, @cmino)
    if placeable then
      @cmino.x += dx
      @cmino.y += dy
      @moved = true
    end
    return placeable
  end
  def fastfall_cmino()
    return false if !operatable?
    while move_cmino(0, -1) do end
    @moved = true
    return true
  end
  def rot_cmino(direc)
    return false if !operatable?
    @cmino.send(direc)
    if @board.placeable?(@cmino.x, @cmino.y, @cmino) then
      @moved = true
    else
      # 回転後に重なるブロックがないように移動する
      d = [[1, 0], [-1, 0], [0, 1]].find{|diff|
        @board.placeable?(@cmino.x+diff[0], @cmino.y+diff[1], @cmino)
      }
      if d then
        move_cmino(d[0], d[1])
        @moved = true
      else
        # 左右上どこにも動けない時は回転しない(元に戻す)
        # この場合は入力したことにならない
        3.times{@cmino.send(direc)}
        return false
      end
    end
    return true
  end
  
  def update()
    self.send(@state_func[@status])
    @past_count += 1 if @status != Status::GAMEOVER
  end


  private

  def push_random_mino_to_nexts()
    @nexts.push(TETROMINOES.keys.sample)
  end
  def pop_from_nexts()
    @cmino = CurrentMino.new(0, 0, @nexts.shift)
    push_random_mino_to_nexts

    sx = (TetrisBoard::WIDTH-@cmino.width())/2
    sy = TetrisBoard::HEIGHT-@cmino.height()
    if !@board.placeable?(sx, sy, @cmino) then
      # (sx, sy)に置けないなら上にずらす
      sy += 1 while !@board.placeable?(sx, sy, @cmino)
    end
    @cmino.x = sx
    @cmino.y = sy
  end
  def fix_cmino()
    mino = @cmino
    mino.each{|u, v, bt|
      next if bt == BlockType::EMPTY
      @board.set(mino.x+u, mino.y+v, bt)
    }
  end


  def state_wait() end
  def state_spawn()
    # 新しいミノを出現させる
    pop_from_nexts()
    @spawn_count += 1
    @status = Status::INPUT

    # 新しいミノが完全にBoard外ならGame Over
    if @cmino.y >= TetrisBoard::HEIGHT then
      fix_cmino()
      @status = Status::GAMEOVER
    end
  end
  def state_input()
    @moved |= move_cmino(0, -1)
    if !@moved then
      fix_cmino()
      @status = Status::CHECK
    end

    @moved = false
  end
  def state_check()
    # ラインが埋まっているかチェックして，埋まってるなら消す
    c = 0
    Array.new(@cmino.height()){|i| @cmino.y+i}
      .select{|row| @board.filled_line?(row)}
      .each{|r| @board.shrink_line(r-c); c += 1}
    @line_count += c
    @cmino = nil
    @status = Status::SPAWN
  end
  def state_gameover()
    #~ @board.each{|x, y, bt|
      #~ @board[x, y] = BlockType::O
    #~ }
  end
end
