#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int row, col;
vector<vector <int> > osenbei_machine;
vector<vector <int> > osenbei_machine_copy;

int count_osenbei(vector<vector<int> > osenbei){
    int osenbei_num = 0;
    int output = 0;


    for (int i = 0; i < col; i++) {
        osenbei_num = 0;
        for (int j = 0; j < row; j++) {
            osenbei_num += osenbei[j][i];
        }
        if(2*osenbei_num >= row){
            output += osenbei_num;
        }
        else{
            output += row - osenbei_num;
        }
    }

    return output;
}

int dfs(int check_row, bool turn, vector<vector<int> > now_osenbei){
    osenbei_machine_copy = now_osenbei;
    if(turn) {
        for (int i = 0; i < col; i++) {
            now_osenbei[check_row][i] = 1 - now_osenbei[check_row][i];
        }
    }

//     // display osenbei machine (for debug)
//    for (int i = 0; i < row; i++) {
//        for (int j = 0; j < col; j++) {
//            cout << now_osenbei[i][j];
//        }
//        cout << endl;
//    }
//    cout << "-------------------------------------------------------------";
//    cout << endl;


    if(check_row == row-1){
        return count_osenbei(now_osenbei);
    }
    else{
        return max(dfs(check_row+1, false, osenbei_machine_copy), dfs(check_row+1, true, now_osenbei));
    }
}

int main() {
    int answer;
    while(true) {
        cin >> row >> col;
        if(row == 0){
            break;
        }
        osenbei_machine.resize(row);
        for (int i = 0; i < row; i++) {
            osenbei_machine[i].resize(col);
            for (int j = 0; j < col; j++) {
                cin >> osenbei_machine[i][j];
                osenbei_machine[i][j] = 1 - osenbei_machine[i][j];
            }
        }
        osenbei_machine_copy = osenbei_machine;
        answer = max(dfs(0, false, osenbei_machine), dfs(0,true, osenbei_machine));
        cout << answer << endl;



//        // display osenbei machine (for debug)
//        for (int i = 0; i < row; i++) {
//            for (int j = 0; j < col; j++) {
//                cout << osenbei_machine[i][j];
//            }
//            cout << endl;
//        }
    }

    return 0;
}



