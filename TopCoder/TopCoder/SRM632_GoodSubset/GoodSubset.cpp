#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

class GoodSubset {
public:
	int numberOfSubsets(int goodValue, vector<int> d) {
		map<int, int> dp;
		vector<int> inputDivisor;

		for (int i = 0; i < d.size(); i++) {
			if (goodValue % d[i] == 0) {
				inputDivisor.push_back(d[i]);
			}
		}

		sort(inputDivisor.begin(), inputDivisor.end());

		long long tmp;
		for (int i = 0; i < inputDivisor.size(); i++) {
			map<int, int> tmpMap;
			if (i == 0) dp[d[i]] = 1;
			else {
				for (auto itr = dp.begin(); itr != dp.end(); itr++){
					tmp = (long long)itr->first * inputDivisor[i];
					if (tmp >(long long)goodValue) break;
					if (goodValue % tmp == 0) {
						tmpMap[(int)tmp] += itr->second;
					}
				}
				for (auto itr = tmpMap.begin(); itr != tmpMap.end(); itr++) {
					dp[itr->first] += itr->second;
				}
				dp[inputDivisor[i]]++;
			}
			tmpMap.clear();
		}
		cout << dp[goodValue];
		return dp[goodValue];
	}
};
