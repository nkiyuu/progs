#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
#define PB push_back
#define MP make_pair
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

char grid[1000][1000];

int bfs(int sr, int sc, int gr, int gc){
    queue<P> q;
    q.push(MP(sr, sc));
    grid[sr][sc] = '0';
    int nr, nc;
    while(!q.empty()){
        nr = q.front().first;
        nc = q.front().second;
        REP(i, 4){
           if(grid[nr+dy[i]][nc+dx[i]] == '.'){
               grid[nr+dy[i]][nc+dx[i]] = (char);
            }
        }
    }
}
int main(){
    REP(i, 1000){
        REP(j, 1000){
            grid[i][j] = '#';
        }
    }
    int r, c, n, pr, pc;
    cin >> r >> c >> n;
    vector<P> cheese;
    cheese.resize(n);
    string line;
    REP(i, r){
        cin >> line;
        REP(j, c) {
            grid[i + 1][j + 1] = line[j];
            if (line[j] == 'S') {
                pr = i + 1;
                pc = j + 1;
            }
            if (line[j] > '0' && line[j] <= '9') {
                int m = line[j] - '0';
                cheese[m - 1].first = i + 1;
                cheese[m - 1].second = j + 1;
            }
        }
    }
    return 0;
}