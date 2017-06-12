#include <iostream>

using namespace std;
int main() {
    int r,g,b;
    cin >> r >> g >> b;
    int num = 100 * r + 10 * g + b;
    cout << (num % 4 == 0 ? "YES" : "NO") << endl;
    return 0;
}