#include <iostream>

using namespace std;

int main() {
    int times;
    int balls[10];
    int counter = 0;
    bool flag;
    cin >> times;

    while(counter < times) {
        /*
         * 標準入力受け取り
         */
        for (int i = 0; i < 10; i++) {
            cin >> balls[i];
        }
        /*
         * ボールを振り分ける
         */
        int r = 0, l = 0;
        flag = true;
        for (int i = 0; i < 10; i++) {
            if (r < balls[i]) {
                r = balls[i];
                continue;
            } else if (l < balls[i]) {
                l = balls[i];
                continue;
            } else {
                flag = false;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        counter++;
    }
    return 0;
}