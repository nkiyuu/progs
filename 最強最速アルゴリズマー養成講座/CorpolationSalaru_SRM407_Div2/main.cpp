#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "begin" << endl;
    // 問題の生成
    int problemNum = 2;
    vector<string> problem;
    if(problemNum == 1){
        problem = {"N"};
    }
    else if(problemNum == 2) {
        problem = {"NNNNNN", "YNYNNY", "YNNNNY", "NNNNNN", "YNYNNN", "YNNYNN"};
    };

    // 問題を解きにかかる
    vector<vector<int>> table(problem.size(),vector<int>(problem[0].length(),0));
    for(int i = 0; i < problem.size(); i++){
        for(int j = 0; j < problem[0].length(); j++) {
            if (problem[i][j] == 'Y') {
                table[j][i] = 1;
            }
        }
    }

    for(int i = 0; i < table.size(); i++){
        int sum = count(table[i].begin(), table[i].end(), 1);
        if(sum == 0){
            table[i].push_back(1);
        }
        else{
            table[i].push_back(sum);
        }
    }
    // for debug
    for(int i = 0; i < table.size(); i++){
        for(int j = 0; j < table[i].size(); j++){
            cout << table[i][j] << ':' ;
        }
        cout << endl ;
    }


    int salary = 0;
    for(int i = 0; i < table.size(); i++){
        for(int j = 0; j < table[i].size() - 1; j++){
            if(table[i][j] == 1){
                salary += table[j][table[j].size() - 1];
            }
        }
        if(count(table[i].begin(), table[i].end(), 1) == 0){
            salary += 1;
        }
    }

    cout << salary << endl;
    return 0;
}