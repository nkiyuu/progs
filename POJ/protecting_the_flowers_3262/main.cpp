#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long int64;

struct cow{
    int64 T, D;
};

bool comp(const cow& left, const cow& right){
    return -left.D*right.T < -right.D*left.T;
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    int64 total_D = 0;
    cin >> N;
    vector<cow>  cows;
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> cows[i].T >> cows[i].D;
        total_D += cows[i].D;
    }

    sort(cows.begin(), cows.end(), comp);

    int64 ans = 0;
    int reduce_cost = 0;
    for (int i = 0; i < N; i++) {
        total_D -= cows[i].D;
        ans += 2*cows[i].T*total_D;
    }

    cout << ans << endl;
//    for (int i = 0; i  < N; i++ ) {
//        cout << cows[i][0] << " " << cows[i][1] << " " << cows[i][2] << endl;
//    }

    return 0;
}