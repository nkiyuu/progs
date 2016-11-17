#include <iostream>
#include <string>
#include <stack>

using namespace std;

string toRPN(char input){
  stack<char> tmp;
  char rpn;
  for(int i = 0; i < input.size(); i++){
    if(isdigit(input[i])) rpn += input[i];
    else if(input[i] == 'P' || input[i] == 'Q' || input[i] == 'R') rpn += input[i] ;
    else if(input[i] == '-') tmp.push(to_string(input[i]));
    else if(input[i] == '+' || input[i] == '*'){
      if(tmp.top() == "-"){
        rpn += tmp.top(); tmp.pop();
        tmp.push(to_string(input[i]));
      }
      else tmp.push(string(input[i]));
    }
    else if(input[i] == '(') tmp.push(to_string(input[i]));
    else if(input[i] == ')'){
      while(tmp.top() == to_string('(')){
        rpn += tmp.top(); tmp.pop() ;
      }
      tmp.pop();
    }
  }
  cout << rpn << "\n" ;

  while(!tmp.empty()){
    rpn += tmp.top();
    cout << tmp.top() << ":";
    tmp.pop();
  }
  cout << "\n" ;
  return rpn;
}

int main(){
  string input;
  string rpn;
  cin >> input;
  //if(input == '.') break;
  rpn = toRPN(input);
  cout << rpn .c_str() << "\n";
  return 0;
}
