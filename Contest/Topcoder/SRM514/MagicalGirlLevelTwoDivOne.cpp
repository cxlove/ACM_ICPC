// BEGIN CUT HERE

// END CUT HERE
#line 5 "MagicalGirlLevelTwoDivOne.cpp"
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
int a[55][55] , b[55][55];
int dp[11][1 << 10];
int powmod[6][10005];
class MagicalGirlLevelTwoDivOne {
    public:
    inline int add (int a , int b) {
    	return (((a + b) % MOD) + MOD) % MOD;
    }
    inline int mut (int a , int b) {
    	return 1LL * a * b % MOD;
    }
    int theCount(vector <string> palette, int n, int m) {
    	int r = palette.size() , c = palette[0].size ();
    	int ans = 1 ;
    	for (int i = 4 ; i <= 5 ; i ++) {
    		powmod[i][0] = 1;
    		for (int j = 1 ; j <= 10000 ; j ++) {
    			powmod[i][j] = mut (powmod[i][j - 1] , i);
    		}
    	}
    	for (int i = 0 ; i < r ; i ++) {
    		for (int j = 0 ; j < c ; j ++) {
    			if (palette[i][j] == '.') a[i][j] = -1;
    			else a[i][j] = (palette[i][j] - '0') & 1;
    			b[i][j] = 0;
    		}
    	}
    	for (int i = 0 ; i < r ; i ++) {
    		for (int j = 0 ; j < c ; j ++) {
    			if (i >= n || j >= m) {
    				int x = i % n , y = j % m;
    				if (a[i][j] != -1) {
    					if (a[x][y] == -1) {
    						a[x][y] = a[i][j];
    						ans = mut (ans , 4 + a[x][y]);
    					}
    					else {
    						if (a[i][j] != a[x][y])
    							return 0;
    					}
    				}
    			}
    		}
    	}
    	for (int i = 0 ; i < r ; i ++) {
    		for (int j = 0 ; j < c ; j ++) {
    			if (a[i][j] == -1) {
    				b[i % n][j % m] ++;
    			}
    		}
    	}
    	for (int i = 0 ; i < n ; i ++) {
    		for (int j = 0 ; j < m ; j ++) {
    			if (a[i][j] != -1) {
    				ans = mut (ans , powmod [4 + a[i][j]][b[i][j]]);
    			}
    		}
    	}
    	memset (dp , 0 , sizeof (dp));
    	dp[0][0] = 1;
    	for (int i = 0 ; i < n ; i ++) {
    		for (int j = 0 ; j < 1 << m ; j ++) {
    			if (!dp[i][j]) continue;
    			int c[15] , d[15] , cnt = 0;
    			int newj = j , row = 0;
    			for (int k = 0 ; k < m ; k ++) {
    				if (a[i][k] == -1) {
    					d[k] = cnt;
    					c[cnt ++] = k;
    				}
    				else {
    					newj ^= a[i][k] << k;
    					row ^= a[i][k];
    				}
    			}
    			for (int k = 0 ; k < 1 << cnt ; k ++) {
    				int nowj = newj , tot = 1 , nowr = row;
    				for (int r = 0 ; r < cnt ; r ++) {
    					int t = (k >> r) & 1;
    					nowr ^= t;
    					tot = mut (tot , powmod[4 + t][b[i][c[r]]]);
    					nowj ^= t << c[r];
    				}
    				if (!nowr) continue;
    				dp[i + 1][nowj] = add (dp[i + 1][nowj] , mut (tot , dp[i][j]));
    			}
    		}
    	}
    	return mut (ans , dp[n][(1 << m) - 1]);
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"12",
 "2."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 5; verify_case(0, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"21",
 "1."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 2; int Arg3 = 4; verify_case(1, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"...",
 "...",
 "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 1; int Arg3 = 1953125; verify_case(2, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"..58..",
 "..47.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; int Arg3 = 0; verify_case(3, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"...1.2.3",
 "4.5.6...",
 "...7.8.9",
 "1.2.3..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; int Arg2 = 4; int Arg3 = 886073030; verify_case(4, Arg3, theCount(Arg0, Arg1, Arg2)); }
	
	void test_case_5() { string Arr0[] = {"..7......19...9.3..5......7.....7..", ".......9.......5.7....5.97.....1...", ".7.7.1......7.7........73.......3.3", "....5......1..1..5.....7..9..1..9.7", "....9....1.3....7..3.....5......3..", "..7..........9......1....3.........", "......5......3......51....3........", ".5..7..71..7..9.79.....51.7.1....3.", ".7.....333....7..3..9...3.3......99", "...7..7.7.3.13...1..9.............1", "1..3..................3.335.7911..7", "...3..1..3..3.3.....3..3...........", ".........57..73.....7.59..151..9...", ".3...9751.....13.....7.............", ".5....71.......7..3..533.51...97...", ".....9.......1.33.....7.1...9.3..3.", "...1.71.5.55....1......5........91.", "........1.5........3..1....9..1..7.", "....3.............9571...3.........", "....5.5..37............7.5....7....", "..3............5.513.5...5.59.....5", "...1.7...93...1....9135..1......9..", "..1...........5..3..........5....75", "..7.7.3...............1........3...", ".1...5..1...19..37.19..........9...", "..3.1.1.1......3...................", ".3.........9..1..........5....3....", ".9..9.1.9..1......77...7...........", ".1..9........5......3........7..7.5", ".3..1.3..13....7..3......7.........", "........7....9.5......7.3.315......", ".5.7.......9..9........5.......33..", ".7....39......9.......37.......5...", "..3.977.51.......931.5....9..9....3", "..7...7..1..........5.7.7.9...5...5"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 7; int Arg3 = 48935924; verify_case(5, Arg3, theCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    MagicalGirlLevelTwoDivOne ___test;
    ___test.run_test(5);
    return 0;
}
// END CUT HERE
