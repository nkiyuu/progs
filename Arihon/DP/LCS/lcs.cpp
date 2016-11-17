#include<iostream>
#include<string>


using namespace std;

//����
int n = 4;
int m = 4;
string s = "abcd", t = "becd";

int lca(string s, string t) {
	int dp[5][5];
	fill(dp[0],dp[5], 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i] == t[j]) {
				dp[i + 1][j + 1] = dp[i][s[j]] + 1;
			}
			else {
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
			}
		}
	}
	return dp[n][m];
}

int main() {
	cout << lca(s, t);
	return 0;
}
