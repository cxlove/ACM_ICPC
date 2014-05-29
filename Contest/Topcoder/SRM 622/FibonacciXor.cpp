// BEGIN CUT HERE

// END CUT HERE
#line 5 "FibonacciXor.cpp"
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
const int MOD = 1000000007;
const int N = 100;
map <LL , bitset <75> > mymap;
class FibonacciXor {
    public:
    LL fib[N];
    bitset <75> gao (LL n) {
    	if (mymap.find (n) != mymap.end ()) {
    		bitset <75> ans = mymap[n];
    		return ans;
    	}
    	bitset <75> ans;
    	ans.reset ();
    	LL m = n;
    	for (int i = 74 ; i >= 0 ; i --) {
    		if (m >= fib[i]) {
    			LL cnt = m - fib[i] + 1;
    			if (cnt & 1) ans[i] = ans[i] ^ 1;
    			ans = ans ^ gao (cnt - 1);
    			m = fib[i] - 1;
    		}
    	}
    	mymap[n] = ans;
    	return ans;
    }
    int find(long long A, long long B) {
    	fib[0] = 1;fib[1] = 2;
    	for (int i = 2 ; i < N ; i ++)
    		fib[i] = fib[i - 1] + fib[i - 2];
    	bitset <75> ret = gao (B) ^ gao (A - 1);
    	LL ans = 0;
    	for (int i = 0 ; i < 75 ; i ++) {
    		if (ret[i]) {
    			LL ret = 1;
    			for (int j = 0 ; j < i ; j ++) {
    				ret = ret * 2LL % MOD;
    			}
    			ans = (ans + ret) % MOD;
    		}
    	}
    	return ans % MOD;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 2LL; int Arg2 = 3; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 10LL; int Arg2 = 25; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { long long Arg0 = 1LL; long long Arg1 = 1000000000000000LL; int Arg2 = 780431495; verify_case(2, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    FibonacciXor ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
