# -*- coding: utf-8 -*-

class TetrisWorldController
  def initialize(world)
    @world = world
    @input_flag = false
  end

  def inputted?() return @input_flag end
  
  # 操作が成功したかどうかの真偽値を返す
  def rotate_cw()
    return if inputted?
    return @input_flag = @world.rot_cmino(:cw)
  end
  def rotate_ccw()
    return if inputted?
    return @input_flag = @world.rot_cmino(:ccw)
  end
  def move_left()
    return if inputted?
    return @input_flag = @world.move_cmino(-1, 0)
  end
  def move_right()
    return if inputted?
    return @input_flag = @world.move_cmino(1, 0)
  end
  def fall_down()
    return if inputted?
    return @input_flag = @world.fastfall_cmino()
  end
  
  # CurrentMinoを返す(core.rb)
  def get_cmino()
    return @world.get_cmino()
  end
  
  # TetrisBoardを返す(core.rb)
  def get_board()
    return @world.get_board()
  end
  
  # Tetrominoが要素（要素数5）の配列を返す(core.rb)
  def get_nexts()
    return @world.get_nexts()
  end
  
  # 消したライン数を変えす
  def get_clrline_num()
    return @world.line_count
  end
  
  # cminoの出現数を返す
  def get_spawn_num()
    return @world.spawn_count
  end
  
  # ループ回数を返す
  def get_time()
    return @world.past_count
  end
end
