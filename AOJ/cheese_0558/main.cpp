#include <iostream>
#include <queue>
#include <vector>


using namespace std;

const int MAX_H = 1002;
const int MAX_W = 1002;
vector<vector <int> > map;
vector<vector <int> > map_copy;

int INF = 100000;
int main() {

    int h, w, n;
    queue<vector<int>> q;

    cin >> h >> w >> n;

    map.resize(h+2);
    map_copy.resize(h+2);

    for (int i = 0; i < h + 2; i++) {
        map[i].resize(w+2);
        map_copy[i].resize(w+2);
    }
    for(int i = 0; i < h + 2; i++){
        for (int j = 0; j < w + 2; j++) {
            map[i][j] = -1;
        }
    }

    char input_chr;
    for (int i = 1; i < h + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            cin >> input_chr;
            switch (input_chr){
                case 'S':
                    q.push({i, j, 0});
                    map[i][j] = 0;
                    break;
                case '.':
                    map[i][j] = 0;
                    break;
                case 'X':
                    map[i][j] = -1;
                    break;
                default:
                    map[i][j] = int(input_chr - '0');
            }
        }
    }

    int mh[4] = {1,0,0,-1};
    int mw[4] = {0,1,-1,0};

    vector<int> h_w_count;
    h_w_count.resize(3);
    map_copy = map;

    for(int i = 1; i < n+1; i++){
        while(!q.empty()) {
            h_w_count = q.front();
            q.pop();
            if(map[h_w_count[0]][h_w_count[1]] == i){
                while (!q.empty()) q.pop();
                q.push({h_w_count[0], h_w_count[1], h_w_count[2]});
                map = map_copy;
                break;
            }
            map[h_w_count[0]][h_w_count[1]] = -1;
            for (int j = 0; j < 4; j++) {
                if(map[h_w_count[0] + mh[j]][h_w_count[1] + mw[j]] >= 0){
                    q.push({h_w_count[0]+mh[j], h_w_count[1]+mw[j], h_w_count[2] + 1});
                    if(map[h_w_count[0] + mh[j]][h_w_count[1] + mw[j]] == 0){
                        map[h_w_count[0] + mh[j]][h_w_count[1] + mw[j]] = -1;
                    }
                }
            }
        }
    }
    cout << h_w_count[2] << endl;
    return 0;
}

