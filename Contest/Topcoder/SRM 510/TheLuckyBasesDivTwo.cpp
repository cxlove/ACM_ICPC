// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheLuckyBasesDivTwo.cpp"
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
long long inf = 1000000000001LL;
class TheLuckyBasesDivTwo {
    public:
    long long gao (int l , int s , long long b) {
    	double ret = 0;
    	for (int i = 0 ; i < l ; i ++) {
    		ret = 1.0 * ret * b;
    		if ((1 << i) & s)
				ret += 7;
			else ret += 4;
			if (ret > inf) return inf;
    	}
    	long long ans = 0;
    	for (int i = 0 ; i < l ; i ++) {
    		ans = ans * b ;
    		if ((1 << i) & s)
				ans += 7;
			else ans += 4;
		}
    	return ans;
    }
    long long find(long long n) {
    	if (n == 4 || n == 7) return -1;
    	int ret = 0;
    	for (int l = 1 ; l <= 17 ; l ++) {
    		for (int i = 0 ; i < 1 << l ; i ++) {
    			long long low = 5 , high = n , mid , ans = -1;
    			while (low <= high) {
    				mid = (low + high) >> 1;
    				if (gao (l , i , mid) >= n) {
    					high = mid - 1;
    					ans = mid;
    				}
    				else low = mid + 1;
    			}
    			if (ans < 8 && i) continue;
    			if (ans != -1 && gao (l , i , ans) == n) {
    				ret ++;
    			}
    		}
    	}
    	return ret;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 854645986252LL; long long Arg1 = 1LL; verify_case(0, Arg1, find(Arg0)); }
	void test_case_1() { long long Arg0 = 854645986252LL;; long long Arg1 = -1LL; verify_case(1, Arg1, find(Arg0)); }
	void test_case_2() { long long Arg0 = 13LL; long long Arg1 = 0LL; verify_case(2, Arg1, find(Arg0)); }
	void test_case_3() { long long Arg0 = 60LL; long long Arg1 = 2LL; verify_case(3, Arg1, find(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TheLuckyBasesDivTwo ___test;
    ___test.run_test(1);
    return 0;
}
// END CUT HERE
