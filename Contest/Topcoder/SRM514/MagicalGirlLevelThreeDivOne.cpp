// BEGIN CUT HERE

// END CUT HERE
#line 5 "MagicalGirlLevelThreeDivOne.cpp"
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

class MagicalGirlLevelThreeDivOne {
    public:
    long long theMaxPower(vector <string> first, int n, long long lo, long long hi) {

    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"111", "011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; long long Arg2 = 2LL; long long Arg3 = 7LL; long long Arg4 = 4LL; verify_case(0, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { string Arr0[] = {"1", "11", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 123456789; long long Arg2 = 123456789LL; long long Arg3 = 123456789012345LL; long long Arg4 = 123456665555557LL; verify_case(1, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { string Arr0[] = {"0", "00", "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 987654321; long long Arg2 = 987654321LL; long long Arg3 = 987654321054321LL; long long Arg4 = 0LL; verify_case(2, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { string Arr0[] = {"1110", "11", "11111", "111", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 314159265; long long Arg2 = 271828182845904LL; long long Arg3 = 314159265358979LL; long long Arg4 = 15LL; verify_case(3, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { string Arr0[] = {"10000", "011011001011000001101000010100000111000110110", 
"000001010001011000001101110", "100100000110100001010000", 
"011011010", "01100000010101101110000011100011001000",
"0001010", "010011000", "000101001", "00", "1"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000000000; long long Arg2 = 1000000000000000LL; long long Arg3 = 1000000000000000LL; long long Arg4 = 1LL; verify_case(4, Arg4, theMaxPower(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MagicalGirlLevelThreeDivOne ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
