# -*- coding: utf-8 -*-

module BlockType
  [:EMPTY, :I, :O, :S, :Z, :J, :L, :T].each_with_index{|s, i|
    self.const_set(s, i)
  }
end
module Status
  [:WAIT, :SPAWN, :INPUT, :CHECK, :GAMEOVER].each_with_index{
    |s, i| self.const_set(s, i)
  }
end

MAX_NEXT_NUM = 5

DISPLAY_LINES = 20
MINO_POP_POSITION_X = 4
MINO_POP_POSITION_Y = 19

AI_TIMEOUT_LIMIT = 0.01
