//#include <bits/stdc++.h>
#include <iostream>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)

using namespace std;

char t[22][22];
int ans = 1;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int full_search(int x, int y){
    REP(i, 4){
        if(t[y+dy[i]][x+dx[i]] == '.'){
            t[y+dy[i]][x+dx[i]] = '#';
            ans += 1;
            full_search(x+dx[i], y+dy[i]);
        }
    }
    return 0;
}

int main() {
    int sx, sy, px, py;
    while(1) {
        cin >> sx >> sy;
        if(sx == 0 or sy == 0){
            break;
        }
        ans = 1;
        string line;
        REP(i, 22) {
            REP(j, 22) {
                t[i][j] = '#';
            }
        }
        REP(i, sy) {
            cin >> line;
            REP(j, sx) {
                t[i + 1][j + 1] = line[j];
                if (line[j] == '@') {
                    t[i + 1][j + 1] = '#';
                    px = j + 1;
                    py = i + 1;
                }
            }
        }
        full_search(px, py);
        cout << ans << endl;
    }
    return 0;
}

