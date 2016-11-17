#include<iostream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Quacking {
public:
	int quack(string s);
};

int Quacking::quack(string s) {
	int flag = 0, num_duck = 0;
    int check[5] = { 0, 0, 0, 0, 0 };

	while (1) {
		flag = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'q' && !check[0]) {
				s[i] = '#';
				check[0] = 1;
			}
			else if (s[i] == 'u' && check[0] && !check[1]) {
				s[i] = '#';
				check[1] = 1;
			}
			else if (s[i] == 'a' && check[1] && !check[2]) {
				s[i] = '#';
				check[2] = 1;
			}
			else if (s[i] == 'c' && check[2] && !check[3]) {
				s[i] = '#';
				check[3] = 1;
			}
			else if (s[i] == 'k' && check[3] && !check[4]) {
				s[i] = '#';
				check[4] = 1;
                flag = 1;
                for(int j = 0; j < 5; j++){
                    check[j] = 0;
                }
			}
		}
		if(check[0]){
			for(int j = 1; j < 5; j++){
				if(!check[j]) return -1 ;
			}
		}
		if (!flag) break;
        num_duck++;
	}
    for(int i = 0; i < s.size(); i++){
        if(s[i] != '#') return -1;
    }
	return num_duck;
}

