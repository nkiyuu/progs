# -*- coding: utf-8 -*-

#左下(0, 0)とし，右上に行くに従って増加する座標(x, y)となるような2次元座標クラス

class Array2d
  attr_accessor :ary
  def initialize(width, height, e = nil)
    @ary = Array.new(height){[e]*width}
  end
  def initialize_copy(rhs)
    @ary = Marshal.load(Marshal.dump(rhs.ary))
  end

  def _trans(x, y) return x, @ary.size-y-1 end
  def []=(x, y, e)
    x, y = _trans(x, y)
    @ary[y][x] = e
  end
  def [](x, y)
    x, y = _trans(x, y)
    return @ary[y][x]
  end
  def row(r)
    c, r = _trans(0, r)
    return @ary[r]
  end
  def each(&block)
    @ary.size.times{|y|
      @ary[y].size.times{|x|
        block.call(x, y, self[x, y])
      }
    }
  end
end
