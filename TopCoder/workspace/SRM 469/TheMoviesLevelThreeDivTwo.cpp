/* problem


Problem Statement
    
John and Brus have received a box of new movies to review. There are N movies, numbered 0 to N-1, inclusive, and John and Brus each want to review every movie. John has proposed that they use a special device called a review queue. The device supports two operations: add a movie, and take a movie (if at least one exists in the queue). When taking a movie, the movie in the queue that was added earliest is removed from the queue. John and Brus each have their own review queue.  There are two phases to the review process. In the first phase, John distributes the movies between the two queues. He first takes movie 0 and adds it to either John's queue or Brus's queue, then he takes movie 1 and adds it to one of the queues, and so on, until each movie has been added to one of the queues.  In the second phase, John and Brus simultaneously start reviewing movies. Each of them will continuously repeat the following sequence of moves.
Take a movie from his own review queue. If this move is not successful because his queue is empty, he will quit completely (even if more movies will be added to his queue at a later time).
Review this movie.
Add this movie to the other person's review queue if he has not yet reviewed it.
Steps 1 and 3 take no time. If a queue receives an add and a take operation at the same time, the add operation is completed first. So, for example, if John's queue is empty and Brus attempts to add a movie to John's queue at the same time that John tries to take a movie from the same queue, the movie will get added and John will succeed in taking the movie from the queue.  The amount of time required for step 2 varies between John and Brus for each movie. When reviewing a movie, neither John nor Brus feel that it is always necessary to view the entire movie. It takes John timeJ[i] minutes to review movie i, and it takes Brus timeB[i] minutes.  In the first phase, since John has two choices for distributing each movie, there are 2^N ways to distribute the movies. A distribution is considered good if John and Brus each review every movie during the second phase before quitting. Return the total number of good ways to distribute the movies.
Definition
    
Class:
TheMoviesLevelThreeDivTwo
Method:
find
Parameters:
vector <int>, vector <int>
Returns:
int
Method signature:
int find(vector <int> timeJ, vector <int> timeB)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
timeJ will contain between 1 and 20 elements, inclusive.
-
timeJ and timeB will contain the same number of elements.
-
Each element of timeJ will be between 1 and 20, inclusive.
-
Each element of timeB will be between 1 and 20, inclusive.
Examples
0)

    
{4, 4}
{4, 4}
Returns: 2
We are interested in two distributions where John and Brus get one movie each.
1)

    
{1, 4}
{4, 2}
Returns: 1
Here the only possible distribution is where Brus gets the first movie and John gets the second one.
2)

    
{10, 10, 10, 10}
{1, 1, 1, 10}
Returns: 3
Brus must get all the movies except one of the first three during the distribution.
3)

    
{1, 2, 3, 4, 5, 6, 7}
{7, 6, 5, 4, 3, 2, 1}
Returns: 98

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/


/* メモ



*/


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

using namespace std;

class TheMoviesLevelThreeDivTwo {
    public:
    int find(vector<int> timeJ, vector<int> timeB) {
        return 0;
    }
};

// CUT begin
ifstream data("TheMoviesLevelThreeDivTwo.sample");

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

bool do_test(vector<int> timeJ, vector<int> timeB, int __expected) {
    time_t startClock = clock();
    TheMoviesLevelThreeDivTwo *instance = new TheMoviesLevelThreeDivTwo();
    int __result = instance->find(timeJ, timeB);
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
        vector<int> timeJ;
        from_stream(timeJ);
        vector<int> timeB;
        from_stream(timeB);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(timeJ, timeB, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1462200155;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 900 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TheMoviesLevelThreeDivTwo (900 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
