#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//“ü—Í
int N = 4, W = 5;
vector<int> w{ 2, 1, 3, 2 }, v{ 3, 2, 4, 2 };

int rec(int i, int j) {
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
	return res;
}

int main() {
	cout << rec(0, W) << "\n";
	return 0;
}