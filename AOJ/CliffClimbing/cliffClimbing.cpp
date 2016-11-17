#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> P;

//グラフ：　S -> 0, T -> 0, X -> INF

int width, height, INF = 1000000;
int x[9] = {1,1,2,1,2,3,1,2,1};  //右足なら-1をかける
int y[9] = {-2,-1,-1,0,0,0,1,1,2};
int leg[2] = {-1, 1};

int dijkstra(vector<vector<int>> graph){ //ダイクストラで求める
  // 条件
  // ・足が右足か左足か
  // ・どこからスタートするか
  vector<P> starts;
  vector<vector<int>> dijkstra;
  for(int i = 0; i < width; i++){
    if(graph[i][height - 1] == 0) starts.push_back(P(i, height - 1));
  }
  for(int i = 0; i < starts.size(); i++){ //スタートの数だけ行う
    for(int j = 0; j < 2; j++){ //スタート足のパターン
      int stLeg = leg[j];
      dijkstra[starts[i].first][starts[i].second] = 0;
    }  //ここまでで一つのグラフが完成
  } //ここまでですべてのパターンが列挙される
  return 0;
}
