// BEGIN CUT HERE

// END CUT HERE
#line 5 "TheLuckyGameDivOne.cpp"
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
const int inf = 1000000007;
class TheLuckyGameDivOne {
    public:
    vector <LL> lucky;
    int checkmax (LL l , LL r , LL d) {
    	int ans = inf;
    	ans = min (ans , checkmin (l , l + d - 1));
    	ans = min (ans , checkmin (r - d + 1 , r));
    	for (int i = 0 ; i < lucky.size() ; i ++) {
    		LL L , R;
    		L = lucky[i] - d;R = L + d - 1;
    		if (L >= l && R <= r)
    		ans = min (ans , checkmin (L , R));
    		L = lucky[i] + 1;R = L + d - 1;
    		if (L >= l && R <= r)
    		ans = min (ans , checkmin (L , R));
    	}
    	return ans;
    }
    int cal (LL n) {
    	return upper_bound (lucky.begin () , lucky.end () , n) - lucky.begin ();
    }
    int checkmin (LL l , LL r) {
    	return cal (r) - cal (l - 1);
    }
    int find(long long a, long long b, long long jLen, long long bLen) {
    	lucky.clear ();
    	for (int i = 1 ; i <= 10 ; i ++) {
    		for (int j = 0 ; j < (1 << i) ; j ++) {
    			long long ret = 0;
    			for (int k = 0 ; k < i ; k ++) {
    				ret = ret * 10 + (((1 << k) & j) ? 4 : 7);
    			}
    			if (ret >= a && ret <= b) 
    				lucky.push_back (ret);
    		}
    	}
    	if (lucky.size() == 0) return 0;
    	sort (lucky.begin () , lucky.end ());
    	int ans = 0;
    	ans = max (ans , checkmax (a , a + jLen - 1 , bLen));
    	ans = max (ans , checkmax (b - jLen + 1 , b , bLen));
    	for (int i = 0 ; i < lucky.size() ; i ++) {
    		LL l = lucky[i] - bLen + 1 , r = l + jLen - 1;
    		if (l >= a && r <= b) ans = max (ans , checkmax (l , r , bLen));
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 1LL; long long Arg1 = 10LL; long long Arg2 = 2LL; long long Arg3 = 1LL; int Arg4 = 0; verify_case(0, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { long long Arg0 = 1LL; long long Arg1 = 100LL; long long Arg2 = 100LL; long long Arg3 = 100LL; int Arg4 = 6; verify_case(1, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { long long Arg0 = 4LL; long long Arg1 = 8LL; long long Arg2 = 3LL; long long Arg3 = 2LL; int Arg4 = 1; verify_case(2, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { long long Arg0 = 1LL; long long Arg1 = 100LL; long long Arg2 = 75LL; long long Arg3 = 50LL; int Arg4 = 2; verify_case(3, Arg4, find(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    TheLuckyGameDivOne ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
