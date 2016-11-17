#include <iostream>
#include <vector>
#include<math.h>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

// bool check(int xH, int yH, int xT, int yT, double time, int xM, int yM, vector<P> cristals){
//   //cout << "\n" <<"now place(" << xH << ", " << yH << ")" << "\n" ;
//   if(sqrt(pow(xH - xT, 2) + pow(yH - yT, 2)) + time < sqrt(pow(xM - xT, 2) + pow(yM - yT, 2))){
//     if(cristals.size() == 1) return true;
//     for(int i = 0; i < cristals.size(); i++){
//       P alt = cristals[i];
//       cristals.erase(cristals.begin() + i );
//       // for(int j = 0; j < cristals.size(); j++){
//       //   cout << "(" << cristals[j].first << ", " << cristals[j].second << ")";
//       // }
//       if(check(xT, yT, cristals[i].first, cristals[i].second, sqrt(pow(xH - xT, 2) + pow(yH - yT, 2)) + time, xM, yM, cristals)){
//         return true;
//       }
//       cristals.insert(cristals.begin() + i, alt);
//     }
//   }
//   return false;
// }
//

int main(){
  int n, hx, hy, dx, dy, cx, cy;
  vector<pair<double, P>> dDist_pos;
  while(1){
    int flag = 0;
    dDist_pos.clear();
    cin >> n >> hx >> hy >> dx >> dy;
    if(n == 0 && hx == 0 && hy == 0 && dx == 0 && dy==0) break;
    for(int i = 0; i < n; i++){
      cin >> cx >> cy ;
      double dd = sqrt(pow(cx - dx, 2) + pow(cy - dy,2));
      dDist_pos.push_back(make_pair(dd, P(cx, cy)));
    }
    sort(dDist_pos.begin(), dDist_pos.end());
    double dTime = 0, hTime = 0;
    int hxN = hx, hyN = hy;
    for(int i = 0; i < dDist_pos.size(); i++){
      int nextCx = dDist_pos[i].second.first;
      int nextCy = dDist_pos[i].second.second;
      hTime += sqrt(pow(hxN - nextCx, 2) + pow(hyN - nextCy, 2));
      dTime = dDist_pos[i].first;
      if(dTime <= hTime){
        flag = 1;
        break;
      }
      hxN = nextCx;
      hyN = nextCy;
    }
    if(flag) printf("NO\n") ;
    else printf("YES\n");
    // if(check(hx, hy, cristals[0].first, cristals[0].second, 0, dx, dy, cristals)) printf("YES\n");
    // else printf("NO\n");
  }
  return 0;
}
