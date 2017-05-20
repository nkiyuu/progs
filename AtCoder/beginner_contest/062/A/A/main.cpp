#include <iostream>

using namespace std;

int main() {
	int group_a[7] = { 1,3,5,7,8,10,12 };
	int group_b[4] = { 4,6,9,11 };
	int group_c[1] = { 2 };
	int x, y;
	cin >> x >> y;
	int gx, gy;
	for (int i = 0; i < 7 ;++i) {
		if (x == group_a[i]) {
			gx = 1;
		}
		if (y == group_a[i]) {
			gy = 1;
		}
	}
	for (int i = 0; i < 4;++i) {
		if (x == group_b[i]) {
			gx = 2;
		}
		if (y == group_b[i]) {
			gy = 2;
		}
	}
	for (int i = 0; i < 1;++i) {
		if (x == group_c[i]) {
			gx = 3;
		}
		if (y == group_c[i]) {
			gy = 3;
		}
	}
	if (gx == gy) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}