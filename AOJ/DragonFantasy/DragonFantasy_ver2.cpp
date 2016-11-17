#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

typedef pair<int, int> P;

int n, hx, hy, dx, dy, cx, cy;
vector<P> cristals;

// bool check(int xH, int yH, int xT, int yT, double time, int xM, int yM, vector<P> cristals){
//   if(sqrt(pow(xH - xT, 2) + pow(yH - yT, 2)) + time < sqrt(pow(xM - xT, 2) + pow(yM - yT, 2))){
//     if(cristals.size() == 1) return true;
//     for(int i = 0; i < cristals.size(); i++){
//       P alt = cristals[i];
//       cristals.erase(cristals.begin() + i );
//       if(check(xT, yT, cristals[i].first, cristals[i].second, sqrt(pow(xH - xT, 2) + pow(yH - yT, 2)) + time, xM, yM, cristals)){
//         return true;
//       }
//       cristals.insert(cristals.begin() + i, alt);
//     }
//   }
//   return false;
// }

bool check(int hxN, int hyN, double time, vector<P> cristalsRem){
  if(!cristalsRem.size()) return true;
  for(int i = 0; i < cristalsRem.size(); i++){
    if(time + hypot(hxN - cristalsRem[i].first ,hyN - cristalsRem[i].second) >= hypot(dx - cristalsRem[i].first, dy - cristalsRem[i].second)) return false;
  }
  for(int i = 0; i < cristalsRem.size(); i++){
    P alt = cristalsRem[i];
    cristalsRem.erase(cristalsRem.begin() + i);
    if(check(alt.first, alt.second, time + hypot(hxN - alt.first ,hyN - alt.second), cristalsRem)) return true;
    cristalsRem.insert(cristalsRem.begin() + i, alt);
  }
  return false;
}

int main(){

  while(1){
    cristals.clear();
    cin >> n >> hx >> hy >> dx >> dy;
    if(n == 0 && hx == 0 && hy == 0 && dx == 0 && dy==0) break;
    for(int i = 0; i < n; i++){
      cin >> cx >> cy ;
      cristals.push_back(P(cx,cy));
    }
    if(check(hx, hy, 0, cristals)) printf("YES\n");
    else printf("NO\n");
  }
}
