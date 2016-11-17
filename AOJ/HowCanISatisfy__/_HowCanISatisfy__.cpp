#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <algorithm>
#include <sstream>

using namespace std;

string toRPN(string input){
  stack<string> tmp;
  string rpn;
  for(int i = 0; i < input.size(); i++){
    string st = input.substr(i, 1) ;
    if(st == "P" || st == "Q" || st == "R") rpn += st ;
    else if(st == "-") tmp.push(st);
    else if(st == "+" || st == "*"){
      while(tmp.top() == "-"){
        rpn += tmp.top(); tmp.pop();
      }
      tmp.push((st));
    }
    else if(st == "(") tmp.push(st);
    else if(st == ")"){
      while(tmp.top() != "(" ){
        rpn += tmp.top(); tmp.pop() ;
      }
      tmp.pop() ;
    }
    else rpn += st;
  }
  while(!tmp.empty()){
    rpn += tmp.top(); tmp.pop();
  }
  return rpn;
}

int deny(int val){
  return 2 - val;
}

int pl(int val1, int val2){
  return max(val1, val2);
}

int multi(int val1, int val2){
  return min(val1, val2);
}

int solve(string rpn){
  stack<int> st;
  int count = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        for(int l = 0; l < rpn.size(); l++){
          if(rpn.substr(l, 1) == "P") st.push(i);
          else if(rpn.substr(l, 1) == "Q") st.push(j);
          else if(rpn.substr(l, 1) == "R") st.push(k);
          else if(rpn.substr(l, 1) == "-"){
            int tmp = st.top();st.pop();
            st.push(deny(tmp));
          }
          else if(rpn.substr(l, 1) == "+"){
            int tmp = st.top(); st.pop();
            int tmp1 = st.top(); st.pop();
            st.push(pl(tmp1, tmp));
          }
          else if(rpn.substr(l, 1) == "*"){
            int tmp = st.top(); st.pop();
            int tmp1 = st.top(); st.pop();
            st.push(multi(tmp1, tmp));
          }
          else{
              stringstream ss;
              ss.clear();ss.str("");
              int is;
              ss << rpn.substr(l, 1); ss >> is;
              st.push(is);
          }
        }
        if(st.top() == 2) count++;
        st.pop();
      }
    }
  }
  return count;
}

int main(){
  string input = "";
  while(1){
    cin >> input;
    if(input == ".") break;
    cout << solve(toRPN(input)) << "\n";
  }
  return 0;
}
