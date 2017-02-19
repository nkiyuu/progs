#include <iostream>
#include <vector>

using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    int lot_num = row * col;
    string input;
    vector<string> map;

    while(getline(cin, input)){
        map.push_back(input);
    }

    for(int i = 0; i <= row; i++){
        for(int j = 0; j < col; j++){
            if(i == row){
                if(map[i][j] == map[i][j+1]){
                    lot_num--;
                }
            }
            else {
                if (map[i][j] == map[i][j + 1] || map[i][j] == map[i + 1][j]) {
                    lot_num--;
                }
            }
        }
    }
    cout << lot_num << endl;
    return 0;
}