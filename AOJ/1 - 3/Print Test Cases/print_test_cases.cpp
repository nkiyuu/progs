#include "iostream"
using namespace std;

int main(){
	int x, count = 1;
	while(true){
		cin >> x ;
		if (x == 0){
			break;
		}
		cout << "Case " << count << ": " << x << endl ;
		count++ ;
	}
	return 0;
}