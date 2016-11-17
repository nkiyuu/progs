#include <iostream>
#include <string>

using namespace std;

class  IdentifyingWood{
public:
	 string check(string s, string t);
};

string IdentifyingWood::check(string s, string t){
	int count = 0
	for(int i = 0; i < s.size(); i++){
		if(s[i] = t[count]) count++ ;
	}
	if(count = t.size() - 1) return "Yep, it's wood.";
	else return "Nope.";
}