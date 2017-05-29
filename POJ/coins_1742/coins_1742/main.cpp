#include <iostream>
#include <vector>

using namespace std;

int main() {
	int coins_num, max_value;

	while (true) {
		cin >> coins_num >> max_value;
		if (coins_num == 0 && max_value == 0) {
			break;
		}
		//ñ‚ëËÇì«Ç›çûÇﬁ
		int coin, total_coin = 0;
		vector<int> coin_values(coins_num), coin_num(coins_num), each_coin;
		fill(coin_values.begin(), coin_values.end(), 0);
		for (int i = 0; i < coins_num; ++i) {
			cin >> coin_values[i];
		}
		for (int i = 0; i < coins_num;++i) {
			cin >> coin_num[i];
			total_coin += coin_num[i];
		}
		for (int i = 0;i < coins_num;++i) {
			for (int j = 0; j < coin_num[i]; ++j) {
				each_coin.push_back(coin_values[i]);
			}
		}
		//dpÉeÅ[ÉuÉãÇÃèâä˙âª
		vector<vector<int> > dp(total_coin);
		for (int i = 0; i < total_coin; ++i) {
			dp[i].resize(100001);
			fill(dp[i].begin(), dp[i].end(), 0);
		}
		//ñ‚ëËÇâÇ≠
		dp[0][each_coin[0]] = 1;
		for (int i = 1; i < dp.size(); ++i){
			dp[i][0] = 1;
			for (int j = 0; j < dp[i].size(); ++j) {
				if (dp[i-1][j] == 1) {
					dp[i][j] = 1;
					if (j + each_coin[i] <= max_value) {
						dp[i][j + each_coin[i]] = 1;
					}
				}
			}
		}

		for (int i = 0; i < dp.size(); ++i) {
			for (int j = 0; j < 10; ++j) {
				cout << dp[i][j] << "|";
			}
			cout << "\n";
		}

		int answer = 0;
		for (int j = 0; j < 10; ++j) {
			answer += dp[dp.size()-1][j];
		}
		
		cout << answer << endl;
	}
	

	return 0;
}