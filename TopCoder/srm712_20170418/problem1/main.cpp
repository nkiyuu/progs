#include <iostream>

using namespace std;

int main() {
    long int x1, x2,k1,k2;
    string sx1,sx2,sk1,sk2;
    cin >> x1 >> k1 >> x2 >> k2;
    sx1 = to_string(x1);
    sx2 = to_string(x2);


    string sv1 = "";
    for(int i = 0; i < k1; i++){
        sv1 += sx1;
    }
    string sv2 = "";
    for(int i = 0; i < k2; i++){
        sv2 += sx2;
    }

    long long int v1 = stoll(sv1);
    long long int v2 = stoll(sv2);

    if(v1 == v2){
        cout << "Equal" << endl;
    }
    else if(v1 > v2){
        cout << "Greater" << endl;
    }
    else{
        cout << "Less" << endl;
    }

    return 0;
}