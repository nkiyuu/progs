#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

const int MAX_ROW = 102;
const int MAX_COL = 102;
string map[MAX_ROW][MAX_COL];


void dfs(int row, int col, string mark){
    vector<int> mx = {1, 0, 0, -1};
    vector<int> my = {0, 1, -1, 0};
    map[row][col] = "$";
    for(int i = 0; i < 4; i++){
        if(mark == map[row+my[i]][col+mx[i]]){
            dfs(row+my[i],col + mx[i], mark);
        }
    }
    return;
}

int main() {
    while(true) {
        for (int i = 0; i < MAX_ROW; i++) {
            for (int j = 0; j < MAX_COL; j++) {
                map[i][j] = "$";
            }
        }
        int row, col;
        cin >> row >> col;
        if(row == 0){
            break;
        }
        stringstream ss;
        string input;

        for (int i = 1; i < row + 1; i++) {
            cin >> input;
            for (int j = 0; j < col; j++) {
                ss << input[j];
                map[i][j + 1] = ss.str();
                ss.str("");
                ss.clear();
            }
        }



//    for(int i = 0; i < row + 3; i++){
//        cout << i << ":";
//        for(int j = 0; j < col + 2; j++){
//            cout << map[i][j];
//        }
//        cout << endl;
//    }

        int count = 0;
        for (int i = 1; i < row + 1; i++) {
            for (int j = 1; j < col + 1; j++) {
                if (map[i][j] != "$") {
                    dfs(i, j, map[i][j]);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
