#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class RangeEncoding{
public:
    int minRanges(vector<int> arr){
        int answer = 1 ;
        for(int i = 0; i < arr.size() - 1; ++i){
            if(arr[i+1] - arr[i] > 1){
                answer++;
            }
        }
        return answer;
    }

};
