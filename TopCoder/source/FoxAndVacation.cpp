#include<vector>
#include<iostream>

using namespace std;

class FoxAndVacation {
public:
	int maxCities(int total, vector <int> d);
};

int FoxAndVacation::maxCities(int total, vector <int> d) {
	int alt, num = 0, count = 0;
	for (int i = 0; i < d.size() - 1; i++) {
		for (int j = i + 1; j < d.size(); j++) {
			if (d.at(i) > d.at(j)) {
				alt = d.at(j);
				d.at(j) = d.at(i);
				d.at(i) = alt;
			}
		}
	}

	for (int i = 0; i < d.size(); i++) {
		if (num + d.at(i) > total) break;
		num += d.at(i);
		count++;
	}
	return count;
}