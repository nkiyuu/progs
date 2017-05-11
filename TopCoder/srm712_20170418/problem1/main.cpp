#include <iostream>

using namespace std;

int main() {
    long int x1,x2,k1,k2;
    string sx1,sx2,sk1,sk2;
    cin >> x1 >> k1 >> x2 >> k2;
    sx1 = to_string(x1);
    sx2 = to_string(x2);
    char ans = 'e';

    string sv1 = "";
    for(int i = 0; i < k1; i++){
        sv1 += sx1;
    }
    string sv2 = "";
    for(int i = 0; i < k2; i++){
        sv2 += sx2;
    }

    if(sv1.size() < sv2.size()){
        ans='l';
    }
    else if(sv1.size() > sv2.size()){
        ans='g';
    }
    else{
        for(int i=(int)sv1.size(); i >= 0; --i) {
            if ((int) (sv1[i] - '0') > (int) (sv2[i] - '0')) {
                ans = 'g';
            } else if ((int) (sv1[i] - '0') < (int) (sv2[i] - '0')) {
                ans = 'l';
            }
        }
    }
    switch (ans){
        case 'g':
            cout << "Greater" << endl;
            break;
        case 'l':
            cout << "Less" << endl;
            break;
        case 'e':
            cout << "Equal" << endl;
    }
    return 0;
}