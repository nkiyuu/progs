#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>
#include <string>
#include <map>
#include <math.h>
#include <typeinfo>
#include <cstdlib>


using namespace std;

string s = "0123456789ABCDEFGHIJ" ;

class BaseMystery {
    public:
    vector<int> getBase(string equation) {
        string calc_left, calc_right, answer;
        int calc_pos = 0;
        char calc  = '+';
        vector<int> j;

        //separate
        for(int i = 0; i < equation.size(); i++){
            if(equation[i] == '+' || equation[i] == '-'){
                calc_left = equation.substr(0, i);
                calc = equation[i];
                calc_pos = i ;
            }
            if(equation[i] == '='){
                calc_right = equation.substr(calc_pos + 1, i - calc_pos - 1);
                answer = equation.substr(i + 1);
            }
        }

        for(int i = 2; i < 21; i++)
            if(check(calc_left, calc, calc_right, answer, i)){
                j.push_back(i);
            }

        return j;
    }

    bool check(string left, char mark, string right, string answer, int dec){
        stringstream ss;
     	int ans;
     	ss.clear(); ss.str("");
     	string ans_s ;
        if(mark == '+') ans = to(left, dec) + to(right, dec) ;
        else ans = to(left, dec) - to(right, dec) ;
     	ss.clear(); ss.str("");
     	ss << ans;
     	ss >> ans_s ;
        ans_s = reverse(ans_s, dec) ;
     	if(ans_s == answer) return true ;
     	else return false ;
    }

    //対象の進数からに10進数にする関数
    int to(string num, int dec){
        double out = 0.0 ;
        for(int i = 0; i < num.length(); i++){
        	for(int j = 0; j <= dec; j++){
        		if(num[i] == s[j]) out = out + j * pow(dec, num.length() - 1 - i);
            }
        }

        return (int)out ;
    }

    //10進数から対象の進数にする
    string reverse(string num_s, int dec){
    	string out = "", pre;
    	stringstream ss;
    	int num ;
        ss.clear(); ss.str("");
        ss << num_s;
        ss >> num ;
    	while(num >= dec){
    		for(int j = 0; j < 20; j++){
    			if(num % dec == j)  out = s[j] + out;
    		}
    		num = num / dec ;
    	}
    	for(int j = 0; j < 20; j++){
    			if(num % dec == j) out =  s[j] + out;
    		}
    	return out;
    }
};




// CUT begin
ifstream data("BaseMystery.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(string equation, vector<int> __expected) {
    time_t startClock = clock();
    BaseMystery *instance = new BaseMystery();
    vector<int> __result = instance->getBase(equation);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string equation;
        from_stream(equation);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(equation, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1461646497;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "BaseMystery (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
