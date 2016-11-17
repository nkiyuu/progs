#include <iostream>
#include <math.h>

using namespace std;


class CuttingBitString{
public:
    int getmin(string s){
        int stLoc = 0, count = 0;
        while(s.length() > stLoc){
            flag = 0;
            for(int i = 1; i < s.length() - stLoc + 1; i++){
                cout << s.substr(stLoc, i) << "\n";
                if(to(s.substr(stLoc, i), 2) % 5 == 0) {
                    stLoc += i;
                    flag = 1;
                    count++;
                    break;
                }
            }
            if(flag == 0) return -1;
        }
        return count;
    }

    //対象の進数からに10進数にする関数
    int to(string num, int dec){
        string s = "0123456789" ;
        double out = 0.0 ;
        for(int i = 0; i < num.length(); i++){
            for(int j = 0; j <= dec; j++){
                if(num[i] == s[j]) out = out + j * pow(dec, num.length() - 1 - i);
            }
        }
        return (int)out;
    }
};

int main() {
    CuttingBitString t;
    cout << t.getmin("1111101") ;
    cout << t.to("1111", 2) ;
    return 0;
}
