#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int num_cow, end_day;
    cin >> num_cow >> end_day;

    vector<int> cow_term;
    cow_term.resize(2);
    vector<vector<int> > cows;
    cows.resize(num_cow);
    for (int i = 0; i < num_cow; i++) {
        cows[i].resize(2);
    }

    for (int i = 0; i < num_cow; i++) {
        cin >> cow_term[0] >> cow_term[1];
        cows[i][0] = cow_term[0]; cows[i][1] = cow_term[1];
    }
    sort(cows.begin(), cows.end());

    int start_day = 1;
    int finish_day = 0;
    int prev_finish_day;
    int counter = 0;
    int flag = 0;
    int cow_counter = 0;

    while(counter < num_cow){
        flag = 0;
        prev_finish_day = finish_day;
        while(counter < num_cow && start_day <= cows[counter][0] && cows[counter][0] <= prev_finish_day + 1){
            flag = 1;
            if(cows[counter][1] > finish_day){
                finish_day = cows[counter][1];
            }
            counter += 1;
        }
        if(!flag){
            cow_counter = -1;
            break;
        }
        cow_counter += 1;
        start_day = prev_finish_day + 1;
        cout << "finish day is " << finish_day << endl;
    }

    if(finish_day < end_day){
        cout << -1 << endl;
    }else {
        cout << cow_counter << endl;
    }
    return 0;
}

/*
 * 疑似コード
 *
 * 入力を受け取る
 *
 * 牛を開始日の早い順にソート
 * 開始日 = 1;
 * 終了日 = 1;
 * 前回の終了日
 * couter = 0;
 *
 * while(couter < 牛の数){
     * for each 前回の終了日以上終了日以前の牛{
     *     if(該当牛がいない){
     *         return -1;
     *     }
     *     if(終了日 <　現在見ている牛の終了日){
     *         終了日 = 現在見ている牛の終了日
     *     }
     *     counter += 1
     * }
     * 牛カウンター += 1
     * 前回の終了日 = 今の終了日
 * }
 */