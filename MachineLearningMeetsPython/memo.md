## 前提
以下のものはインポートされてるものとする．

    import numpy as np
    import scipy as sp
    import sklearn

## numpy配列の基礎

### numpy と多重リストの違い(numpyリスト側から)
- 形状変更は全体の削除・再生成を必要とする．
  メモリの連続領域に確保されるため．
- 基本的に全て同じ型の要素で構成される．
- 各次元の要素数は全て等しい
- 多くの操作を多重リストより高速に計算可能

### NumPy配列の生成
arrayの作成

- np.array(object, dtype=None) : arrayの作成
- np.zeros(shape, dtype=None) : 要素が全て０の行列を作成
- np.ones(shape, dtype=None) : 要素が全て１の行列を作成
- np.empty(shape, dtype=None) : 要素が不定の行列の作成
- np.identity(n, dtype=None) : 単位行列の作成

同じサイズのarray の作成

- zeros_like(a, dtype=None) : aと同じサイズの０行列の作成
- ones_like(a, dtype=None) : aと同じサイズの１行列の作成
- empty_like(a, dtype=None) : aと同じサイズの要素未決定の行列の作成

