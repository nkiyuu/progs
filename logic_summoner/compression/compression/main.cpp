#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	// 自分の得意な言語で
	// Let's チャレンジ！！
	string str;
	getline(cin, str);
	char prev_br = 'b';
	vector<vector <int>> ans;
	vector<int> tmp(0);
	for (int i = 0; i < str.size(); ++i) {
		if (prev_br != str[i]) {
			prev_br = str[i];
			ans.push_back(tmp);
			tmp.clear();
			tmp.push_back(1);
		}
		else {
			tmp.push_back(1);
		}
		if (i == str.size() - 1) {
			ans.push_back(tmp);
		}
	}
	for (int i = 0;i < ans.size();++i) {
		if (i != ans.size() - 1) {
			cout << ans[i].size() << " ";
		}
		else {
			cout << ans[i].size() << endl;
		}
	}
	return 0;
}
