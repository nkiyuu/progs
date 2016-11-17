# -*- coding: utf-8 -*-
require './core.rb'
require './disp.rb'
require './ctrl.rb'
require './ai.rb'

world = TetrisWorld.new()
ai = AI.new()
display_init()


ex = 2
add_display_window(TetrisAreaWindow.new(2, ex, world))
add_display_window(BoardContentsWindow.new(2, 50, world))
add_display_window(NextWindow.new(2, ex+24, world))
add_display_window(InfoWindow.new(20, ex+24, world))


while true do
  timer = Thread.new{
    ai.update(TetrisWorldController.new(world))
    sleep(AI_TIMEOUT_LIMIT)
  }
  timer.join(AI_TIMEOUT_LIMIT)
  world.update()
  display_update()
end


display_end()
