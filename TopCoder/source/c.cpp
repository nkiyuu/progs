#include<iostream>
#include<vector>
using namespace std;

class PrefixFreeSets{
public:
    int maxElements(vector <string> words);
};

int PrefixFreeSets::maxElements(vector <string> words){
	string alt ;
	vector<int> v;

	for(int i = 0; i < words.size(); i++){
		for(int j = i; j < words.size(); j++){
			if(words[i].size() > words[j].size()){
				alt = words[i] ;
				words[i] = words[j];
				words[j] = alt ;
			}
		}
	}

	for(int i = 0; i < words.size(); i++){
		for(int j = i + 1 ; j < words.size(); j++){
			if(words[i] == words[j].substr(0, words[i].size())){
                v.push_back(i) ;
                break ;
            }
            //cout << words[i] << ":" << words[j].substr(0, words[i].size()) << "-" ;
		}
   	}
	return words.size() - v.size();
}