# -*- coding: utf-8 -*-
require 'curses'
require './const.rb'

DRAWSTACK = []

def display_init()
  Curses.init_screen
  Curses.start_color

  Curses.init_pair(BlockType::EMPTY, Curses::COLOR_WHITE, Curses::COLOR_BLACK)
  Curses.init_pair(BlockType::I, Curses::COLOR_BLACK, Curses::COLOR_CYAN)
  Curses.init_pair(BlockType::J, Curses::COLOR_BLACK, Curses::COLOR_BLUE)
  Curses.init_pair(BlockType::L, Curses::COLOR_BLACK, Curses::COLOR_WHITE)
  Curses.init_pair(BlockType::O, Curses::COLOR_BLACK, Curses::COLOR_YELLOW)
  Curses.init_pair(BlockType::S, Curses::COLOR_BLACK, Curses::COLOR_GREEN)
  Curses.init_pair(BlockType::T, Curses::COLOR_BLACK, Curses::COLOR_MAGENTA)
  Curses.init_pair(BlockType::Z, Curses::COLOR_WHITE, Curses::COLOR_RED)
end

def add_display_window(wnd)
  DRAWSTACK.push(wnd)
end

def display_update()
  DRAWSTACK.each{|wnd| wnd.draw()}
  Curses.refresh
end

def display_end()
  Curses.close_screen
end

class TetrisAreaWindow
  WIDTH_SCALE = 2
  WIDTH = 10*WIDTH_SCALE+2
  HEIGHT = DISPLAY_LINES+2
  def initialize(ox, oy, world)
    @win = Curses.stdscr.subwin(HEIGHT, WIDTH, ox, oy)
    @world = world
  end

  def draw()
    # board
    b = @world.get_board()
    DISPLAY_LINES.times{|y|
      b.row(y).each_with_index{|bt, x|
        @win.setpos(HEIGHT-2-y, 1+x*WIDTH_SCALE)
        @win.attrset(Curses.color_pair(bt))
        @win.addstr(" "*WIDTH_SCALE)
      }
    }
    
    # cmino
    c = @world.get_cmino()
    if !c.nil? then
      c.each{|u, v, bt|
        next if bt == BlockType::EMPTY
        x, y = c.x+u, c.y+v
        @win.setpos(HEIGHT-2-y, 1+x*WIDTH_SCALE)
        @win.attrset(Curses.color_pair(bt))
        @win.addstr(" "*WIDTH_SCALE)
      }
    end
    
    # frame
    @win.attrset(Curses.color_pair(3))
    @win.box(?|, ?-, ?+)
    
    @win.refresh
  end
end

class InfoWindow
  WIDTH = 20
  HEIGHT = 5
  STATUS_TEXTS = {
    Status::WAIT      => "Wait      ",
    Status::SPAWN     => "Spawn     ",
    Status::INPUT     => "Input     ",
    Status::CHECK     => "Check Line",
    Status::GAMEOVER  => "Game Over ",
  }
  def initialize(ox, oy, world)
    @win = Curses.stdscr.subwin(HEIGHT, WIDTH, ox, oy)
    @world = world
  end

  def draw()
    @win.attrset(Curses.color_pair(BlockType::EMPTY))
    HEIGHT.times{|y| @win.setpos(y, 0); @win.addstr(" "*WIDTH)}
    
    @win.setpos(0, 0)
    @win.addstr("Line   :#{@world.line_count}")
    @win.setpos(1, 0)
    @win.addstr("Spawn  :#{@world.spawn_count}")
    @win.setpos(2, 0)
    @win.addstr("Time   :#{@world.past_count}")
    @win.setpos(3, 0)
    @win.addstr("Status :#{STATUS_TEXTS[@world.status]}")
    @win.refresh
  end
end

class BoardContentsWindow
  HEIGHT = 24
  def initialize(ox, oy, world)
    @win = Curses.stdscr.subwin(HEIGHT, 20, ox, oy)
    @world = world
  end
  
  def draw()
    @world.get_board().each{|x, y, bt|
      @win.setpos(HEIGHT-1-y, x*2)
      @win.attrset(Curses.color_pair(bt))
      @win.addstr("#{bt},")
    }
    @win.refresh
  end
end

class NextWindow
  WIDTH = 12
  HEIGHT = MAX_NEXT_NUM*3+4
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
  def initialize(ox, oy, world)
    @win = Curses.stdscr.subwin(HEIGHT, WIDTH, ox, oy)
    @world = world
  end

  def draw()
    @win.attrset(Curses.color_pair(BlockType::EMPTY))
    HEIGHT.times{|y| @win.setpos(y, 0); @win.addstr(" "*WIDTH)}

    @win.setpos(0, 0)
    @win.addstr("Next")
    @world.get_nexts.each_with_index{|bt, i|
      TETROMINOES[bt].each_with_index{|row, y|
        row.each_with_index{|e, x|
          @win.setpos(2+3*i+y, x*2)
          @win.attrset(Curses.color_pair(e))
          @win.addstr(" "*2)
        }
      }
    }

    @win.refresh
  end
end
