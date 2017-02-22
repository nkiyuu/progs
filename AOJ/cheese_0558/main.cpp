#include <iostream>
#include <queue>


using namespace std;

const int MAX_H = 1002;
const int MAX_W = 1002;
char map[MAX_H][MAX_W];

int main() {

    int h, w, n;
    queue< pair <pair<int, int>, pair<int, int> > >  q;

    cin >> h >> w >> n;

    for(int i = 0; i < MAX_H; i++){
        for (int j = 0; j < MAX_W; j++) {
            map[i][j] = 'X';
        }
    }

    for (int i = 1; i < h + 1; i++) {
        for (int j = 1; j < w + 1; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'S'){
                pair<int, int> start_pos;
                start_pos.first = i;
                start_pos.second = j;
                pair<int, int> init_counter_hp;
                init_counter_hp.first = 0;
                init_counter_hp.second = 1;
                q.push( pair<pair<int, int>, pair<int, int> >(start_pos, init_counter_hp));
            }
        }
    }

    int mh[4] = {1,0,0,-1};
    int mw[4] = {0,1,-1,0};

    pair<pair<int, int>, pair<int, int> > now_pos_counter;
    int cheese;

    while(!q.empty()){
        now_pos_counter = q.front();
        q.pop();
        if(map[now_pos_counter.first.first][now_pos_counter.first.second] != '.'){
            cheese = int(map[now_pos_counter.first.first][now_pos_counter.first.second] - '0');
            if(cheese <= now_pos_counter.second.second ){
                if(cheese == n) {
                    break;
                }
                now_pos_counter.second.second += 1;
                map[now_pos_counter.first.first][now_pos_counter.first.second] = '.';
                while(!q.empty()) q.pop();
                //現在地入れてcontinue;
            }
        }
        for (int i = 0; i < 4; i++) {
            if(map[now_pos_counter.first.first + mh[i]][now_pos_counter.first.second + mw[i]] != 'X'){
                pair<int, int> next_pos;
                next_pos.first = now_pos_counter.first.first + mh[i];
                next_pos.second = now_pos_counter.first.second + mw[i];
                pair<int ,int> next_counter_pos;
                next_counter_pos.first = now_pos_counter.second.first + 1;
                next_counter_pos.second = now_pos_counter.second.second;
                q.push(pair<pair<int, int>, pair<int,int> >(next_pos, next_counter_pos));

            }
        }
    }
    cout << now_pos_counter.second.first << endl;
    return 0;
}

//もう一個マップを持っておいてチーズ食べたら更新