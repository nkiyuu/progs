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
            break;
        }
    }
    string rev_pali = "";
    for(int i = (int)palindrome.size(); i >= 0; --i){
        rev_pali += palindrome.substr(i, 1);
    }

    string ans1 = palindrome + plus_alpha + rev_pali;
    vector<string> ans_list;
    ans_list.push_back(ans1);
    for(int i=0; i < input_string.size();i++){
        if(input_string[i] != ""){
            ans_list.push_back(input_string[i]);
        }
    }
    for(int i = 0; i < ans_list.size(); i++){
        cout << ans_list[i] << endl;
    }
    return 0;
}