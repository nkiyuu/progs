#include "stdio.h"
#include "iostream"
using namespace std;

int main(){
	int a, b, c, alt;
	cin >> a >> b >> c ;
	//a = 3; b = 8 ; c = 1 ;
	if (a > b){
		alt = a;
		a = b ;
		b= alt;
	}
	if (a > c){
		alt = a;
		a = c ;
		c = alt;
	}
	if (b > c){
		alt = b;
		b = c ;
		c = alt;
	}
	cout << a << " " << b << " " << c << endl;
}