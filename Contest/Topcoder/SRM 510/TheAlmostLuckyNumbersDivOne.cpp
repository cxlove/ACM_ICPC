// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheAlmostLuckyNumbersDivOne.cpp"
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
const int N  = 25;
long long dp[N][2][2];
int bit[N] , len;
class TheAlmostLuckyNumbersDivOne {
    public:
    long long dfs (int len , int f , int zero , int lim) {
    	if (len == 0) {
    		return 1;
    	}
    	if (!lim && dp[len][f][zero] != -1) return dp[len][f][zero];
    	int up = lim ? bit[len] : 9;
    	long long ret = 0;
    	for (int i = 0 ; i <= up ; i ++) {
    		int ff = f , z = zero;
    		if (i != 4 && i != 7) {
    			if (i == 0 && zero) ff = 0;
    			else {
    				if (f) continue;
    				ff = 1;
    			}
    		}
    		if (i) z = 0;
    		ret += dfs (len - 1 , ff , z , lim && i == up);
    	}
    	if (!lim) dp[len][f][zero] = ret;
    	return ret;
    }
    long long gao (long long n) {
    	len = 0;
    	while (n) {
    		bit[++ len] = n % 10;
    		n /= 10;
    	}
    	memset (dp , -1 , sizeof (dp));
    	return dfs (len , 0 , 1 , 1);
    }
    long long find(long long a, long long b) {
    	return gao (b) - gao (a - 1);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 4LL; long long Arg1 = 7LL; long long Arg2 = 4LL; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 8LL; long long Arg1 = 19LL; long long Arg2 = 4LL; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 28LL; long long Arg1 = 33LL; long long Arg2 = 0LL; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { long long Arg0 = 12345678900LL; long long Arg1 = 98765432100LL; long long Arg2 = 91136LL; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TheAlmostLuckyNumbersDivOne ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
