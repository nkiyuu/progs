#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <complex>
using namespace std;
#define rep(i,n) for (int i=0; i < (n); i++)
typedef double D;
typedef complex<D> P;
typedef pair<P, P> L;
typedef vector<P> VP;
const D EPS = 1e-9;
#define X real()
#define Y imag()
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n,m) ((n) + EPS > (m))
#define EQ(n,m) (abs((n) - (m)) < EPS)

// 内積　dot(a,b) = |a||b|cosθ
D dot(P a, P b) {
  return (conj(a)*b).X;
}

// 外積　cross(a,b) = |a||b|sinθ
D cross(P a, P b) {
  return (conj(a)*b).Y;
}

// 点の進行方向
int ccw(P a, P b, P c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 線分と点
bool isecSP(P a1, P a2, P b) {
  return !ccw(a1, a2, b);
}



P proj(P a1, P a2, P p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

D distSP(P a1, P a2, P p) {
  P r = proj(a1, a2, p);
  if (isecSP(a1, a2, r)) return abs(r-p);
  return min(abs(a1-p), abs(a2-p));
}

D distLC(P a1, P a2, P c, D r){
  D dSqr1 = norm(c-a1), dSqr2 = norm(c-a2);
  if (dSqr1 < r*r ^ dSqr2 < r*r) return 0;
  if( dSqr1 < r*r & dSqr2 < r*r) return r -sqrt(max(dSqr1, dSqr2));
  return max(distSP(a1, a2, c) - r, 0.0);
}

//２円の接線．点は接点
vector<L> tangentLines(P a, D ar, P b, D br){
  vector<L> ls;
  D d = abs(b - a);
  rep(i,2){
    D sin = (ar - (1-i*2)*br) / d;
    if ( !LE(sin*sin,1)) break;
    D cos = sqrt(max(1 - sin*sin, 0.0));
    rep(j,2){
      P n = (b-a) * P(sin, (1-j*2)*cos) / d ;
      ls.push_back(L(a + ar*n, b + (1 - i*2)*br*n));
      if(cos < EPS) break;
    }
  }
  return ls;
}
