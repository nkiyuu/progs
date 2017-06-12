#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    int t[9] = {0};
    int a = 0;
    for(int i = 0; i < n; ++i){
        cin >> m;
        if(m < 400){
            if(t[0] == 0) {
                t[0] = 1;
                a++;
            }
        }
        else if(m < 800){
            if(t[1] == 0) {
                t[1] = 1;
                a++;
            }
        }
        else if(m < 1200){
            if(t[2] == 0) {
                t[2] = 1;
                a++;
            }
        }
        else if(m < 1600){
            if(t[3] == 0) {
                t[3] = 1;
                a++;
            }
        }
        else if(m < 2000){
            if(t[4] == 0) {
                t[4] = 1;
                a++;
            }
        }
        else if(m < 2400){
            if(t[5] == 0) {
                t[5] = 1;
                a++;
            }
        }
        else if(m < 2800){
            if(t[6] == 0) {
                t[6] = 1;
                a++;
            }
        }
        else if(m < 3200){
            if(t[7] == 0) {
                t[7] = 1;
                a++;
            }
        }
        else {
            t[8] += 1;
        }
    }

    if(t[8] == 0){
        cout << a << " " << a << endl;
    }
    else{
        if(a == 0){
            cout << 1 << " " << t[8] << endl;
        }
        else{
            cout << a << " " << a + t[8] << endl;
        }
    }
    return 0;
}