// BEGIN CUT HERE

// END CUT HERE
#line 5 "FiveHundredEleven.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
int dp[55][555];
class FiveHundredEleven {
    public:
    vector <int> a;
    int dfs (int x , int y) {
    	if (y == 511) return 1;
    	if (x == a.size()) return 0;
    	if (dp[x][y] != -1) return dp[x][y];
    	int cnt = 0 , ret = 0;
    	for (int i = 0 ; i < a.size() ; i ++) {
    		if ((a[i] | y) == y) cnt ++;
    		else {
    			if (dfs (x + 1 , y | a[i]) == 0)
    				ret = 1;
    		}
    	}
    	if (cnt != x) {
    		if (dfs (x + 1 , y) == 0)
    			ret = 1;
    	}
    	return dp[x][y] = ret;
    }
    string theWinner(vector <int> cards) {
    	memset (dp , -1 , sizeof (dp));
    	a = cards;
    	return dfs (0 , 0) ?  "Fox Ciel" : "Toastman";
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 5, 7, 9, 510}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Fox Ciel"; verify_case(0, Arg1, theWinner(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Toastman"; verify_case(1, Arg1, theWinner(Arg0)); }
	void test_case_2() { int Arr0[] = {511}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Toastman"; verify_case(2, Arg1, theWinner(Arg0)); }
	void test_case_3() { int Arr0[] = {5, 58, 192, 256}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "Fox Ciel"; verify_case(3, Arg1, theWinner(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FiveHundredEleven ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
