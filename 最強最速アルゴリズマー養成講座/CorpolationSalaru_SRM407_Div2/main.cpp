#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<long long> salaries(50, 0);

//各個人の給料を求めていく
long long getSalary(int personNum, vector<string> problem){
    if(salaries[personNum] == 0) {
        long long salary = 0;
        for (int i = 0; i < problem.size(); i++) {
            if (problem[personNum][i] == 'Y') {
                salary += getSalary(i, problem);
            }
        }
        if (salary == 0) {
            salaries[personNum] = 1;
        } else {
            salaries[personNum] = salary;
        }
    }

    return salaries[personNum];
}

int main() {
    cout << "begin" << endl;
    // 問題の生成
    int problemNum = 4;
    vector<string> problem;
    if(problemNum == 1){
        problem = { "N"};
    }
    else if(problemNum == 2) {
        problem = {"NNNNNN",
                   "YNYNNY",
                   "YNNNNY",
                   "NNNNNN",
                   "YNYNNN",
                   "YNNYNN"};
    }
    else if(problemNum == 3){
        problem = {"NYNNYN",
                   "NNNNNN",
                   "NNNNNN",
                   "NNYNNN",
                   "NNNNNN",
                   "NNNYYN"
        };
    }else if(problemNum== 4){
        problem = {"NNYN",
                   "NNYN",
                   "NNNN",
                   "NYYN"
        };
    };
    
    // 問題を解きにかかる
    long long total = 0;
    for(int i = 0; i < problem.size(); i++){
        total += getSalary(i, problem);
    }
    cout << total << endl;
    return 0;
}
