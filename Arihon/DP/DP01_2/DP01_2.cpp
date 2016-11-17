#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//入力
int N = 4, W = 5;
vector<int> w{ 2, 1, 3, 2 }, v{ 3, 2, 4, 2 };

//DP用のテーブル
vector<vector <int> > dp(N + 1, vector<int>(W + 1, -1));


int rec(int i, int j) {
	if (dp[i][j] >= 0) {
		return dp[i][j];
	}
	int res;
	if (i == N) {
		res = 0;
	}
	else if (j < w[i]) {
		res = rec(i + 1, j);
	}
	else {
		res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
	}
	return dp[i][j] = res;
}

int main() {
	cout << rec(0, W) << "\n";
	for (int i = 0; i < dp.size(); i++) {
		for (int j = 0; j < dp[i].size(); j++) {
			cout << dp[i][j] << ":";
		}
		cout << "\n";
	}
}