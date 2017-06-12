#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define PB push_back
#define MP make_pair
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

static const int INF  = 1e9;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

int r, c, n;
P cheese[11];

string grid[1002];
int ans = 0;
int d[1002][1002] ;

int bfs(){

    REP(i, n) {
        int sr = cheese[i].first, sc = cheese[i].second;
        int gr= cheese[i+1].first, gc = cheese[i+1].second;
        REP(i, r + 2) {
            REP(j, c + 2) {
                d[i][j] = INF;
            }
        }
        d[sr][sc] = 0;
        queue<P> q;
        q.push(MP(sr, sc));
        int nr, nc;
        while (!q.empty()) {
            P now = q.front();
            nr = now.first;
            nc = now.second;
            q.pop();
            if (nr == gr && nc == gc){
                ans += d[nr][nc];
                break;
            }
            REP(i, 4) {
                int mr = nr+dy[i], mc = nc+dx[i];
                if (grid[mr][mc] != 'X') {
                    if(d[mr][mc] == INF){
                        d[mr][mc] = d[nr][nc] + 1;
                        q.push(MP(mr, mc));
                    }
                }
            }
        }
    }
    return 0;
}

int main(){

    cin >> r >> c >> n;
    grid[0] = string (c+2, 'X');
    REP(i, r){
        string line;
        cin >> line;
        line = "X" + line + "X";
        grid[i + 1] = line;
    }
    grid[r + 1] = string (c+2, 'X');
    REP(i, r + 2){
        REP(j, c + 1){
            char c = grid[i][j];
            if(c == 'S'){
                cheese[0].first = i;
                cheese[0].second = j;
            }
            if(c > '0' && c <= '9'){
                int t = (int)c - '0';
                cheese[t].first = i;
                cheese[t].second = j;
            }
        }
    }
    bfs();
    cout << ans << endl;
    return 0;
}