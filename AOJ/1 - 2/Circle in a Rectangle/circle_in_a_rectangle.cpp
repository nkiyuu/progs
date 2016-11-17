#include "iostream"
using namespace std;

int main(){
	int w, h, x, y, r ;
	//w = 5; h = 4 ; x = 2; y = 2; r = 1;
	cin >> w >> h >> x >> y >> r;
	if (0 <= x - r && x + r <= w && 0 <= y - r && y + r <= h){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}