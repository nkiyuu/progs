#include <iostream>
#include <stack>

using namespace std;



class RemovingParenthesis{
    int ans = 0;
public:
    int countWays(string s){
        string sub = s；
        sub = sub.substr(1);
        if (sub.size() == 1){
            return 1;
        }
        for(int i = 0; i < sub.size(); ++i){
            if(sub[i]==')') {
                cout << sub << endl;
                sub.erase(sub.begin() + i);
                cout << sub << endl;
                if (checkParenthesis(sub)) {
                    return ans + countWays(sub);
                }
            }
            sub = s;
        }
        return ans;
    };

    bool checkParenthesis(string s){
        stack<int> st;
        for(int i=0; i < s.size(); ++i){
            if(s[i]=='('){
                st.push(1);
            }
            else if(s[i]==')'){
                if(st.empty()){
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        return true;

    };
};