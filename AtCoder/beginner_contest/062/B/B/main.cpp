#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int r, c;
	cin >> r >> c;
	vector<string> inputs(r + 2);
	for (int i = 0; i < c + 2; ++i) {
		inputs[0] += "#";
	}
	for (int i = 1; i < r+1; ++i) {
		cin >> inputs[i];
		inputs[i] = "#" + inputs[i] + "#";
	}
	for (int i = 0; i < c + 2; ++i) {
		inputs[r+1] += "#";
	}
	for (int i = 0; i < r+2; ++i) {
		cout << inputs[i] << endl;
	}
	getchar();
	getchar();
	return 0;
}