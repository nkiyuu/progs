#include "iostream"
using namespace std;

int main(){
	int x, y, alt;
	while(true){
		cin >> x >> y;
		if (x == 0 && y == 0){
			break ;
		}
		if(x > y){
			alt = x;
			x = y;
			y = alt;
		}
		cout << x << " " << y << endl;
	}
}