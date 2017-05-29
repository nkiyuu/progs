#include <iostream>
#include <math.h>


using namespace std;

pair<int, int> blocks(int r, int c, float size) {
	pair<int, int> output;
	float diff = 100000.0;
	int all_block = r * c;
	for (int i = 1; i < r + 1; ++i) {
		if (diff > fabs(size*all_block - i*c)) {
			diff = fabs(size*all_block - i*c);
			output.second= i;
			output.first = c;
		}
	}
	for (int i = 1; i < c + 1; ++i) {
		if (diff > fabs(size*all_block - i*r)) {
			diff = fabs(size*all_block - i*r);
			output.first = i;
			output.second = r;
		}
	}
	return output;
}

int main() {

	int x, y;
	cin >> x >> y;
	pair<int, int> first = blocks(x, y, 0.3333333);
	int second_num_r, second_num_c;
	if (x - first.first == 0) {
		second_num_r = x;
	}
	else {
		second_num_r = first.first;
	}
	if (y - first.second == 0) {
		second_num_c = y;
	}
	else {
		second_num_c = first.second;
	}
	pair<int, int> secound = blocks(x - second_num_r, y - second_num_c, 0.5);
	int firstb = first.first * first.second;
	int scoundb = secound.first * secound.second;
	int thirdb = x * y - firstb - scoundb;

	cout << firstb << " " << scoundb << " " << thirdb <<  endl;
	return 0;
}

