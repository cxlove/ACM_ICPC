// BEGIN CUT HERE

// END CUT HERE
#line 5 "GameOfLifeDivOne.cpp"
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
int cnt[N][2][N][2] , s[N] ;
LL dp[N][2][N];
class GameOfLifeDivOne {
    public:
    long long theCount(string init, int T, int k) {
    	int n = init.size();
    	for (int i = 0 ; i <= 2 * n ; i ++) {
    		if (init[i % n] == '?') s[i] = -1;
    		else s[i] = init[i % n] - '0';
    	}
    	memset (cnt , -1 , sizeof (cnt));
    	for (int i = 0 ; i <= 2 * n ; i ++) {
    		for (int j = 0 ; j < 2 ; j ++) {
    			for (int x = i + 1 ; x <= 2 * n ; x ++) {
    				for (int y = 0 ; y < 2 ; y ++) {
    					if (j == y) {
    						if ((x - i + 1) & 1) continue;
    					}
    					else {
    						if ((x - i) & 1) continue;
    					}
    					int ok = 1;
    					for (int p = i , q = j ; p < x ; p ++ , q = 1 - q) {
    						if (s[p] != -1 && s[p] != q) ok = 0;
    					}
    					if (ok) {
    						if (j != y) cnt[i][j][x][y] = (x - i) / 2;
    						else {
    							if (j == 1) cnt[i][j][x][y] = min (x - i , (x - i + 1) / 2 + T);
    							else  cnt[i][j][x][y] = max (0 , (x - i) / 2 - T);
    						}
    					}
    				}
    			}
    		}
    	}
    	LL ans = 0;
    	if (n % 2 == 0 && k <= n / 2 && cnt[0][0][n][1] != -1) ans ++;
    	if (n % 2 == 0 && k <= n / 2 && cnt[0][1][n][0] != -1) ans ++;
    	for (int st = 0 ; st < n ; st ++) {
    		for (int st1 = 0 ; st1 < 2 ; st1 ++) {
    			memset (dp , 0 , sizeof (dp));
    			dp[st][st1][0] = 1;
    			for (int i = st ; i < n + st ; i ++) {
    				for (int i1 = 0 ; i1 < 2 ; i1 ++) {
    					for (int one = 0 ; one <= n ; one ++) {
    						LL pre = dp[i][i1][one];
    						if (!pre) continue;
    						for (int j = i + 1 ; j <= st + n ; j ++) {
    							if (j < n || (j == n + st && i < n)) {
    								for (int j1 = 0 ; j1 < 2 ; j1 ++) {
    									int get = cnt[i][i1][j][j1];
    									if (get != -1) {
    										int newone = one + get;
    										dp[j][j1][newone] += pre;
    									}
    								}
    							}
    						}
    					}
    				} 
    			}
    			for (int one = k ; one <= n ; one ++) {
    				ans += dp[st + n][st1][one];
    				// cout << st << " " << st1 << " " << one << " " << dp[st + n][st1][one] << endl;
    			}
    			// cout << ans << endl;
    		}
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "0?1"; int Arg1 = 1; int Arg2 = 1; long long Arg3 = 1LL; verify_case(0, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "?????????"; int Arg1 = 0; int Arg2 = 1; long long Arg3 = 511LL; verify_case(1, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "??0???????"; int Arg1 = 58; int Arg2 = 6; long long Arg3 = 151LL; verify_case(2, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "?????????1"; int Arg1 = 47; int Arg2 = 3; long long Arg3 = 453LL; verify_case(3, Arg3, theCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "?????????1???0???1??1??????0??????0??0????1???????"; int Arg1 = 12; int Arg2 = 40; long long Arg3 = 31577324313LL; verify_case(4, Arg3, theCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    GameOfLifeDivOne ___test;
    ___test.run_test(3);
    return 0;
}
// END CUT HERE
