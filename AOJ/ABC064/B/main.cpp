#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> houses;
    int n, m;
    cin >> n;
    for(int i =0; i < n; ++i){
        cin >> m;
        houses.push_back(m);
    }
    sort(houses.begin(), houses.end());
    cout << houses[n - 1] - houses[0] << endl;
    return 0;
}