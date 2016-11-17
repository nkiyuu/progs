#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

//入力
int N = 3, W = 7;
vector<int> w{3, 4, 2 }, v{4, 5, 3 };

//DP用のテーブル
vector<vector <int> > dp(N + 1, vector<int>(W + 1, 0));

int rec() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= W; j++) {
			if (j < w[i]) dp[i + 1][j] = dp[i][j];
			else dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - w[i]] + v[i]);
		}
	}
	return dp[N][W];
};

int main() {
	cout << rec();
	return 0;
}