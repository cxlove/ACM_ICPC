// BEGIN CUT HERE

// END CUT HERE
#line 5 "MagicalGirlLevelThreeDivTwo.cpp"
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
const int N = 105;
double length[N];
class MagicalGirlLevelThreeDivTwo {
    public:
    vector <string> s;
    int k;
    int get (int n , LL p) {
    	if (n < k) {
    		return s[n][p] - '0';
    	}
    	for (int j = n - 1 ; j >= 0 ; j -= k) {
    		if (p < length[j]) {
    			return get (j , p);
    		}
    		p -= (LL)length[j];
    	}
    }
    int theCount(vector <string> first, int n, long long lo, long long hi) {
    	k = first.size();
    	for (int i = 0 ; i < k ; i ++) {
    		length[i] = first[i].length ();
    	}
    	for (int i = k ; i <= n ; i ++) {
    		length[i] = 0;
    		for (int j = i - 1 ; j >= 0 ; j -= k) {
    			length[i] += length[j];
    		}
    	}
    	s = first;
    	int ans = 0;
    	for (LL pos = lo ; pos <= hi ; pos ++) {
    		ans += get (n , pos);
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"101", "01"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 2LL; long long Arg3 = 5LL; int Arg4 = 2; verify_case(0, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"01", "10"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; long long Arg2 = 4LL; long long Arg3 = 5LL; int Arg4 = 1; verify_case(1, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"1", "11", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; long long Arg2 = 10000LL; long long Arg3 = 11000LL; int Arg4 = 1001; verify_case(2, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"0", "00", "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 46; long long Arg2 = 10000LL; long long Arg3 = 11000LL; int Arg4 = 0; verify_case(3, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"00110110101101001111101101001011010011111011010010"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; long long Arg2 = 999999999999915LL; long long Arg3 = 1000000000000000LL; int Arg4 = 50; verify_case(4, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { string Arr0[] = {"10000", "011011001011000001101000010100000111000110110", 
"000001010001011000001101110", "100100000110100001010000", 
"011011010", "01100000010101101110000011100011001000",
"0001010", "010011000", "000101001", "00", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 91; long long Arg2 = 123456LL; long long Arg3 = 123654LL; int Arg4 = 76; verify_case(5, Arg4, theCount(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MagicalGirlLevelThreeDivTwo ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
