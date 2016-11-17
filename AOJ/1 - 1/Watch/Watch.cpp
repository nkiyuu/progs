#include "stdio.h"
#include "iostream"
using namespace std ;

int main(){
	int t, hours, minutes, seconds;
	 cin >> t;
	//t = 46979;
	hours = t / 3600;
	minutes = (t - 3600 * hours) / 60;
	seconds = t - 3600 * hours - 60 * minutes;
	cout << hours << ":" << minutes << ":" << seconds << endl ;
	return 0;
}