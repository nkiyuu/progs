#include<iostream>
#include<string>

using namespace std;

class ThePalindrome {
public:
	int find(string s) {
		int shift = 0;
		string sRev = "";

		for (int i = s.size() - 1; i >= 0; i--) {
			sRev += s[i] ;
		}

		for (int i = 0; i < s.size() - shift; i++) {
			if (s.substr(i, s.size() - i) == sRev.substr(0, s.size() - i)) {
				return s.size() + i;
			}
		}
		return 2 * s.size();

	}
};


int main() {
	ThePalindrome t;
	cout << t.find("abdfhdyrbdbsdfghjkllkjhgfds");
	return 0;
}
