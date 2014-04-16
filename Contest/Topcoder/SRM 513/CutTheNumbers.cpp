// BEGIN CUT HERE

// END CUT HERE
#line 5 "CutTheNumbers.cpp"
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
const int N = 5;
int dp[N][N][N][N] , n , m;
vector <string> a;
class CutTheNumbers {
    public:
    int cao (int y , int x1 , int x2) {
    	int ret = 0;
    	for (int i = x1 ; i <= x2 ; i ++) {
    		ret = ret * 10 + a[i][y] - '0';
    	}
    	return ret;
    }
    int gao (int x , int y1 , int y2) {
    	int ret = 0;
    	for (int i = y1 ; i <= y2 ; i ++) {
    		ret = ret * 10 + a[x][i] - '0';
    	}
    	return ret;
    }
    int dfs (int u , int d , int l , int r) {
    	if (u > d || l > r) return 0; 
    	int &ret = dp[u][d][l][r];
    	if (ret != -1) return ret;
    	// cout << u << " " << d << " " << l << " " << r << endl; 
    	ret = max (ret , gao (u , l , r) + dfs (u + 1 , d , l , r));
    	ret = max (ret , gao (d , l , r) + dfs (u , d - 1 , l , r));
    	ret = max (ret , cao (l , u , d) + dfs (u , d , l + 1 , r));
    	ret = max (ret , cao (r , u , d) + dfs (u , d , l , r - 1));
    	return ret;
    }
    int maximumSum(vector <string> board) {
    	n = board.size();
    	m = board[0].size();
    	a = board;
    	memset (dp , -1 , sizeof (dp));
    	return dfs (0 , n - 1 , 0 , m - 1);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"123",
 "312"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 435; verify_case(0, Arg1, maximumSum(Arg0)); }
	void test_case_1() { string Arr0[] = {"99",
 "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 182; verify_case(1, Arg1, maximumSum(Arg0)); }
	void test_case_2() { string Arr0[] = {"001",
 "010",
 "111",
 "100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1131; verify_case(2, Arg1, maximumSum(Arg0)); }
	void test_case_3() { string Arr0[] = {"8"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 8; verify_case(3, Arg1, maximumSum(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CutTheNumbers ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
