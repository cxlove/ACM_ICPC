// BEGIN CUT HERE

// END CUT HERE
#line 5 "PerfectMemory.cpp"
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
const int N = 1255;
double dp[N][N];  // 还剩i对，已知j个
class PerfectMemory {
    public:
    double binom (int n , int m) {
    	return n * (n - 1) / 2.0;
    }
    double dfs (int i , int j) {
    	if (dp[i][j] >= 0.0) return dp[i][j];
    	if (i == 0 && j == 0) return dp[i][j] = 0.0;
    	if (i == 1 && j == 0) return dp[i][j] = 1.0;
    	// if (i == 2 && j == 2) return dp[i][j] = 2.0;
    	double q = 2 * i - j , p1 = j / (2.0 * i - j) , p0 = 1 - p1;
    	double ret = 0.0;
    	double p00 = p0 * 1.0 / (q - 1) , p02 = p00 * j , p01 = p0 - p00 - p02;
    	// 第一个未知的是已知的
    	if (j) {
    		ret += (dfs (i - 1 , j - 1) + 1.0) * p1;
    	}
    	// 第一个未知，第二个也未知 , 两个刚好一样
    	if (i - j) {
    		ret += (dfs (i - 1 , j) + 1.0) * p00;
    	}
    	// 第一个未知，第二个也未知 , 两个不一样
    	if (i - j >= 2) {
    		ret += (dfs (i , j + 2) + 1.0) * p01;
    	}
    	// 第一个未知，第二个已知
    	if (i - j && j) {
    		ret += (dfs (i - 1 , j) + 2.0) * p02;
    	}
    	return dp[i][j] = ret;
    }
    double getExpectation(int R, int C) {
    	int n = R * C / 2;
    	for (int i = 0 ; i <= n ; i ++)
    		for (int j = 0 ; j <= n ; j ++)
    			dp[i][j] = -1.0;
    	return dfs (n , 0);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 2; double Arg2 = 1.0; verify_case(0, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 2; double Arg2 = 2.6666666666666665; verify_case(1, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; double Arg2 = 4.333333333333334; verify_case(2, Arg2, getExpectation(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 4; double Arg2 = 12.392984792984793; verify_case(3, Arg2, getExpectation(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    PerfectMemory ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
