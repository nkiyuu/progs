#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dp(40, 0);


int getDonation(vector<int> donations){
    for(int i = 0; i < donations.size(); i++){
        if(i == 0){
            dp[0] = donations[0];
        }else if(i == 1){
            dp[1] = max(donations[0], donations[1]);
        }else if(i == donations.size() - 1){
            dp[i] = max(dp[i - 1], donations[i] + dp[i - 2] - dp[0]);
        }else{
            dp[i] = max(dp[i - 1], donations[i] + dp[i - 2]);
        }
    };
    return *max_element(dp.begin(), dp.end());
}

int main(){
    vector<int> problem, donOne, donTwo;
    problem = {94,40,49,65,21,21,106,80,92,81,679,4,61, 6,237,12,72,74,29,95,265,35,47,1,61,397, 52,72,37,51,1,81,45,435,7, 36,57,86,81,72};
    donOne = problem;
    donTwo = problem;
    donTwo.push_back(problem[0]);
    donTwo.erase(donTwo.begin());
    cout << max(getDonation(donOne), getDonation(donTwo)) << endl;
}
