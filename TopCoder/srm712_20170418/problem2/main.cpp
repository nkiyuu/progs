#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input;
    cin >> input;
    string str;
    vector<string> input_string(1000);
    string palindrome = "";

    sort(input.begin(), input.end());
    for(int i = 0; i < input.size(); i++){
        str = input[i];
        input_string[i] = str;
    }

    for(int i = 0; i < input_string.size() - 1; i++){
        if(input_string[i] == input_string[i+1] && input_string[i + 1] != ""){
            palindrome += input_string[i];
            input_string[i] = "";
            input_string[i+1] = "";
        }
    }
    string plus_alpha = "";
    for(int i = 0; i < input_string.size(); i++){
        if(input_string[i] != ""){
            plus_alpha = input_string[i];
            input_string[i] = "";
        }
    }
    string rev_pali = "";
    for(int i = (int)palindrome.size(); i == 0; --i){
        rev_pali += palindrome[i];
    }

    string ans1 = palindrome + plus_alpha + rev_pali;
    cout << palindrome << ":" << plus_alpha << ":" << rev_pali << endl;
    cout << ans1 << endl;
    return 0;
}