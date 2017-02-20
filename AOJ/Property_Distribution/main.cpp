#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;
typedef stringstream ss;

vector< vector<string> > map;
int lot_num;
int main() {
    int row, col;
    cin >> row >> col;
    lot_num = row * col;
    string input;
    int input_num = 0;
    ss input_tmp;

    while(getline(cin, input)){
        if(input[0] == '0'){
            break;
        }
        map.push_back({});
        map[input_num].push_back("$");
        for(int i = 0; i < input.size(); i++){
            input_tmp << input[i];
            map[input_num].push_back(input_tmp.str());
            input_tmp.str("");
            input_tmp.clear();
        }
        cout << endl;
        map[input_num].push_back("$");
        input_num++;
    }
    vector<string> last_row(col + 2, "$");
    map.push_back(last_row);


    return 0;
}
