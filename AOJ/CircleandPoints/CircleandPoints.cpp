#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <complex>
#include <iomanip>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)

typedef double D;      // 座標値の型。doubleかlong doubleを想定
typedef complex<D> P;  // Point
typedef pair<P, P> L;  // Line
typedef vector<P> VP;


// 点aと点bを通り、半径がrの円の中心を返す
VP circlesPointsRadius(P a, P b, D r) {
  VP cs;
  P abH = (b-a)*0.5;
  D d = abs(abH);
  if (d == 0 || d > r) return cs;  // 必要なら !LE(d,r) として円1つになる側へ丸める
  D dN = sqrt(r*r - d*d);          // 必要なら max(r*r - d*d, 0) とする
  P n = abH * P(0,1) * (dN / d);
  cs.push_back(a + abH + n);
  if (dN > 0) cs.push_back(a + abH - n);
  return cs;
}

int main(){
  int count, answer;
  float n, x, y;
  vector<P> points;
  vector<int> answers;
  while(1){
    answer = 1;
    points.clear();
    cin >> n ;
    if(n == 0) break;
    for(int i = 0; i < n; i++){
      cin >> x >> y ;
      points.push_back(P(x, y));
    }

    VP circlesCenter;
    for(int i = 0; i < points.size(); i++){
      for(int j = i + 1; j < points.size(); j++){
        circlesCenter = circlesPointsRadius(points[i], points[j], 1);
        for(int k = 0; k < circlesCenter.size(); k++){
          count = 0;
          for(int l = 0; l < points.size(); l++){
            if(pow(circlesCenter[k].real() - points[l].real(), 2) + pow(circlesCenter[k].imag() - points[l].imag(), 2) <= 1.00001) count++;
          }
          if(count > answer) answer = count ;
        }
      }
    }
    answers.push_back(answer) ;
  }
  if(answers.empty()) cout << 1 << "\n";
  else{
    for(int i = 0; i < answers.size(); i++){
      cout << answers[i] << "\n" ;
    }
  }
  return 0;
}
