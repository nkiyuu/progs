#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int N;
    int total_D = 0;
    cin >> N;
    vector<vector<int> > cows;
    cows.resize(N);
    for (int i = 0; i < N; i++) {
        cows[i].resize(3);
        cin >> cows[i][1] >> cows[i][2];
        total_D += cows[i][2];
    }

    for (int i = 0; i < N; i++) {
        cows[i][0] = total_D * 2 * cows[i][1] - 2 * cows[i][1] * cows[i][2];
    }

    sort(cows.begin(), cows.end());

    int ans = 0;
    int reduce_cost = 0;
    for (int i = 0; i < N; i++) {
        reduce_cost += cows[i][2];
        ans += (2*cows[i][1]*total_D - 2*cows[i][1]*reduce_cost);
    }

    cout << ans << endl;
//    for (int i = 0; i  < N; i++ ) {
//        cout << cows[i][0] << " " << cows[i][1] << " " << cows[i][2] << endl;
//    }


    return 0;
}