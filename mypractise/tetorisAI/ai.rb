# AIクラス（実装対象）
# AI.update(controller) を必ず実装する
require './core.rb'
require 'io/console'

class AI
  def initialize()
    @ctr = nil
    @counter = 0
    @input_thread = nil
    @move = []
    if @input_thread == nil
      @input_thread = Thread.new{
        self.input_move
      }
    end
    @fd_flag = false
    @command = nil
    @move = nil
    @rotate = nil
    #@input_thread.wakeup()
  end

  # 思考開始時に呼び出される
  def update(controller)
    # controllerはテトリス操作に必要なオブジェクト
    # const.rb内のAI_TIMEOUT_LIMIT時間内に処理が戻らなければ
    # 強制的に呼び出し元に戻る

    @ctr = controller # [move_left(), move_right(), rotate_cw(), fall_down(), get_board()]
    @nexts = @ctr.get_nexts() if @nexts == nil
    if !(@nexts == @ctr.get_nexts())
      @fd_flag = false
      @nexts = @ctr.get_nexts()
      @command = nil
      @move = nil
      @rotate = nil
    end
    s_board = self.get_strict_board(@ctr.get_board(), @ctr.get_cmino())
    if @ctr.get_cmino() != nil
      cmino = @ctr.get_cmino()
      temp_mino = Marshal.load(Marshal.dump(cmino))
      t = [1,0,1,1,3,3,3]
      t_ary = []
      t_rotate = t[temp_mino.block_type-1]
      for i in 0..t_rotate
        for x in 0..10-temp_mino.ary[0].size
          temp_mino.x = x
          touch = self.calc_touch_wall(s_board, temp_mino) # カウンターとy値
          if touch != nil
            t_ary << [touch[0], touch[1], i, x-cmino.x, cmino.block_type, touch[2], touch[3]]
          end
        end
        temp_mino.cw
      end
      if t_ary.size > 0
        wall = 23
        for tall in 0..23
          if s_board[tall] != [0,0,0,0,0,0,0,0,0,0]
            wall = tall
          end
        end
        if wall > 13
          t_ary.sort! do |a,b|
            (b[0] <=> a[0]).nonzero? || \
            (a[1] <=> b[1]) || \
            (a[6] <=> b[6]) || \
            (a[3] <=> b[3]) || \
            1
          end
        elsif wall <= 13
          t_ary.sort! do |a,b|
            (a[1] <=> b[1]) || \
            (a[6] <=> b[6]) || \
            (b[0] <=> a[0]).nonzero? || \
            (a[3] <=> b[3]) || \
            1
          end
        end
        @command = t_ary[0] if @command == nil
        p @command
        @move = 0 if @move == nil
        @rotate = 0 if @rotate == nil
        delaysize = 20
        if @command[2] - @rotate > 0
          @ctr.rotate_cw()
          @rotate += 1
        elsif @command[3] - @move > 0
          @ctr.move_right()
          @move += 1
        elsif @command[3] - @move < 0
          @ctr.move_left()
          @move -= 1
        elsif !@fd_flag
          @ctr.fall_down()
          @fd_flag = true
        end
      end
    end
  end
  def input_move
    while c = STDIN.getch
      exit if c == ?\C-c
      @move << c
      case c
        when "a"
          @ctr.move_left()
        when "d"
          @ctr.move_right()
        when "k"
          @ctr.rotate_cw()
        when"j"
          @ctr.rotate_ccw()
        when"o"
          @ctr.fall_down()
        else
      end
    end
  end
  def get_strict_board(board, mino) # 固定済みの盤面となる二次元配列を取得
    return nil if board == nil or mino == nil
    s_board = Marshal.load(Marshal.dump(board.ary))
    rev_mino = TETROMINOES[mino.block_type].reverse
    # minoは@block_typeと@x, @yにアクセス可能
    y_base = 24-mino.y-1
    x_base = mino.x
    for y in 0...rev_mino.length
      for x in 0...rev_mino[0].length
        if board.ary[y_base - y][x_base + x] == mino.block_type
          s_board[y_base - y][x_base + x] = 0
        end
      end
    end
    return s_board
  end
  def calc_touch_wall(s_board, temp_mino) # minoが接触する面の数を数える,AIスレッド外で動かすこと
    counter = 0
    burst = []
    return nil if s_board == nil or temp_mino == nil
    touch_area = []
    case temp_mino.block_type
      # ブロックの位置は左下を基点とする
      # minoの位置は決定されているとする
      # [mino.x + touch_area[0], mino.y + touch_area[1]]が0以外であれば接触
      #
      when 1 then # I
        if temp_mino.ary.size == 1 # 横向き
          touch_area = [[-1,0],[0,-1],[1,-1],[2,-1],[3,-1],[4,0],[3,1],[2,1],[1,1],[0,1]]
          foot_area = [[0,-1], [1,-1], [2,-1] ,[3,-1]]
        else # 縦向き
          touch_area = [[-1,0],[-1,1],[-1,2],[-1,3],[0,4],[1,3],[1,2],[1,1],[1,0],[0,-1]]
          foot_area =[[0,-1]]
        end
      when 2 then
        touch_area = [[-1,0],[-1,1],[0,2],[1,2],[2,1],[2,0],[1,-1],[0,-1]]
        foot_area = [[0,-1],[1,-1]]
      when 3 then
        if temp_mino.ary.size == 2 # Sの状態
          touch_area = [[-1,0],[0,1],[1,2],[2,2],[3,1],[2,0],[1,-1],[0,-1]]
          foot_area = [[0,-1],[1,-1],[2,0]]
        else # Sではない状態
          touch_area = [[-1,1],[0,0],[1,-1],[2,0],[2,1],[1,2],[0,3],[-1,2]]
          foot_area = [[1,-1],[0,0]]
        end
      when 4 then
        if temp_mino.ary.size == 2 # Zの状態
          touch_area = [[-1,1],[0,0],[1,-1],[2,-1],[3,0],[2,1],[1,2],[0,2]]
          foot_area = [[1,-1],[2,-1],[0,0]]
        else # Zではない状態
          touch_area = [[-1,0],[-1,1],[0,2],[1,3],[2,2],[2,1],[1,0],[0,-1]]
          foot_area = [[0,-1],[1,0]]
        end
      when 5 then
        if temp_mino.ary.size == 2 # 横長の場合
          if temp_mino.ary[1][0] == 0 # 基点にminoがない横長の場合
            touch_area = [[-1,1],[0,0],[1,0],[2,-1],[3,0],[3,1],[2,2],[1,2],[0,2]]
            foot_area = [[2,-1],[0,0],[1,0]]
          else
            touch_area = [[-1,0],[-1,1],[0,2],[1,1],[2,1],[3,0],[2,-1],[1,-1],[0,-1]]
            foot_area = [[0,-1],[1,-1],[2,-1]]
          end
        else # 縦長の場合
          if temp_mino.ary[0][0] == 0 # 左上にminoがない縦長の場合
            touch_area = [[-1, 0],[0,-1],[1,-1],[2,0],[2,1],[2,2],[1,3],[0,2],[0,1]]
            foot_area = [[0,-1],[1,-1]]
          else
            touch_area = [[-1, 0],[-1,1],[-1,2],[0,3],[1,3],[2,2],[1,1],[1,0],[0,-1]]
            foot_area = [[0,-1],[1,1]]
          end
        end
      when 6 then
        if temp_mino.ary.size == 2 # 横長の場合
          if temp_mino.ary[0][0] == 0 # 左上にminoがない横長の場合
            touch_area = [[-1,0],[0,-1],[1,-1],[2,-1],[3,0],[3,1],[2,2],[1,1],[0,1]]
            foot_area = [[0,-1],[1,-1],[2,-1]]
          else
            touch_area = [[-1,0],[-1,1],[0,2],[1,2],[2,2],[3,1],[2,0],[1,0],[0,-1]]
            foot_area = [[0,-1],[1,0],[2,0]]
          end
        else # 縦長の場合
          if temp_mino.ary[2][0] == 0 # 基点にminoがない縦長の場合
            touch_area = [[-1,2],[0,3],[1,3],[2,2],[2,1],[2,0],[1,-1],[0,1],[0,0]]
            foot_area = [[1,-1],[0,1]]
          else
            touch_area = [[-1,0],[0,-1],[1,-1],[2,0],[1,1],[1,2],[0,3],[-1,2],[-1,1]]
            foot_area = [[0,-1],[1,-1]]
          end
        end
      when 7 then
        if temp_mino.ary.size == 2 # 横長の場合
          if temp_mino.ary[0][0] == 0 #上に凸
            touch_area = [[-1,0],[0,-1],[1,-1],[2,-1],[3,0],[2,1],[1,2],[0,1]]
            foot_area = [[0,-1],[1,-1],[2,-1]]
          else # 下に凸
            touch_area = [[-1,1],[0,0],[1,-1],[2,0],[3,1],[2,2],[1,2],[0,2]]
            foot_area = [[1,-1],[0,0],[2,0]]
          end
        else # 縦長の場合
          if temp_mino.ary[0][0] == 0 # 左に凸
            touch_area = [[-1,1],[0,0],[1,-1],[2,0],[2,1],[2,2],[1,3],[0,2]]
            foot_area = [[1,-1],[0,0]]
          else
            touch_area = [[-1,0],[-1,1],[-1,2],[0,3],[1,2],[2,1],[1,0],[0,-1]]
            foot_area = [[0,-1],[1,0]]
          end
        end
      else
    end
    #p temp_mino.ary.size
    touch_array = []
    if foot_area != nil
      flag = false
      for i in 0...24
        if s_board != nil
          foot_area.each{|f_x, f_y|
            next if i-f_y < 0
            if i-f_y <= 23
              if s_board[i-f_y][f_x+temp_mino.x] != 0
                #p "on_stop #{temp_mino.x}, #{23-i}" # 落下して止まる座標(y軸は反転)
                touch_area.each{|t_x, t_y|
                  if t_x+temp_mino.x >= 0 and t_x + temp_mino.x < 10 and i-t_y <= 23
                    if s_board[i-t_y][t_x+temp_mino.x] != 0
                      counter += 1
                      burst << 1
                    else
                      burst << 0
                    end
                  elsif t_x+temp_mino.x < 0
                    counter += 1
                    burst << 1
                  elsif t_x + temp_mino.x >= 10 or i-t_y > 23
                    counter += 1
                    burst << 1
                  end
                }
                if temp_mino.block_type == 7 and temp_mino.ary.size != 2 # 縦長の場合
                  counter -= 0.5
                end
                flag = true
                break
              end
            else
              #p "gnd_stop #{temp_mino.x}, #{23-i}" # 落下して止まる座標(y軸は反転)
              touch_area.each{|t_x, t_y|
                if t_x+temp_mino.x >= 0 and t_x + temp_mino.x < 10 and i-t_y <= 23
                  if s_board[i-t_y][t_x+temp_mino.x] != 0
                    counter += 1
                    burst << 1
                  else
                    burst << 0
                  end
                elsif t_x+temp_mino.x < 0 or t_x + temp_mino.x >= 10
                  counter += 1
                  burst << 1
                elsif i-t_y > 23
                  counter += 1
                  burst << 1
                end
              }
              if temp_mino.block_type == 7 and temp_mino.ary.size != 2 # 縦長の場合
                counter -= 0.5
              end

              flag = true
              break
            end
          }
          if flag
            break
          end
        end
      end
    end
    last = nil
    burst_cnt = 0
    for b in 0..burst.size
      last = burst[b] if last == nil
      if burst[b] != last
        burst_cnt += 1
      end
      last = burst[b]
    end
    if i == nil or counter == 0
      return nil
    else
      return [counter, 23-i, burst, burst_cnt]
      #else
      #  p "test"
    end
  end
end