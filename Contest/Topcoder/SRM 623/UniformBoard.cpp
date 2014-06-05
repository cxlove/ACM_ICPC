// BEGIN CUT HERE

// END CUT HERE
#line 5 "UniformBoard.cpp"
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
const int N = 25;
int a[N][N] , b[N][N];
class UniformBoard {
    public:
    int getBoard(vector <string> board, int K) {
    	int n = board.size() , m = board[0].size ();
    	int apple = 0 , space = 0;
    	for (int i = 0 ; i < n ; i ++)
    		for (int j = 0 ; j < m ; j ++) {
    			if (board[i][j] == 'A')
    				apple ++;
    			if (board[i][j] == '.')
    				space ++;
    		}
    	memset (a , 0 , sizeof (a));
    	memset (b , 0 , sizeof (b));
    	for (int i = 1 ; i <= n ; i ++) {
    		for (int j = 1 ; j <= m ; j ++) {
    			if (board[i - 1][j - 1] == 'A') a[i][j] = 1;
    			else if (board[i - 1][j - 1] == 'P') b[i][j] = 1;
    			a[i][j] = a[i][j] + a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    			b[i][j] = b[i][j] + b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    		}
    	}
    	int ans = 0;
    	for (int i = 0 ; i < n ; i ++) {
    		for (int j = i ; j < n ; j ++) {
    			for (int k = 0 ; k < m ; k ++) {
    				for (int r = k ; r < m ; r ++) {
    					if ((j - i + 1) * (r - k + 1) > apple) continue;
    					int all = (j - i + 1) * (r - k + 1);
    					int A = a[j + 1][r + 1] - a[j + 1][k] - a[i][r + 1] + a[i][k];
    					int B = b[j + 1][r + 1] - b[j + 1][k] - b[i][r + 1] + b[i][k];
    					if (!space) {
    						if (A == all)
    							ans = max (ans , all);
    						continue;
    					}
    					int need = B + (all - A);
    					if (need <= K)
    						ans = max (ans , all);
    				}
    			}
    		}
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"AP",
 ".A"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"PPP",
 "APA",
 "A.P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(2, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"AAA",
 "PPP",
 "AAA"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 3; verify_case(3, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1000; int Arg2 = 0; verify_case(4, Arg2, getBoard(Arg0, Arg1)); }
	void test_case_5() { string Arr0[] = {"PPAAPA..AP",
 "PPA.APAP..",
 "..P.AA.PPP",
 "P.P..APAA.",
 "P.P..P.APA",
 "PPA..AP.AA",
 "APP..AAPAA",
 "P.P.AP...P",
 ".P.A.PAPPA",
 "..PAPAP..P"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 15; verify_case(5, Arg2, getBoard(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    UniformBoard ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
