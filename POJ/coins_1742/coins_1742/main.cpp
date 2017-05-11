#include <iostream>
#include <vector>

using namespace std;

int main() {
	int coin_num, max_value;
	
	while (true) {
		cin >> coin_num >> max_value;
		if (coin_num == 0 && max_value == 0) {
			break;
		}
		int coin;
		vector<int> coins(100000);
		fill(coins.begin(), coins.end(), 0);
		for (int i = 0; i < coin_num; ++i) {
			cin >> coin;
			coins[coin] += 1;
		}
		
		for (int i = 0; i < 5; ++i) {
			cout << coins[i] << ",";
		}
	}
	

	return 0;
}