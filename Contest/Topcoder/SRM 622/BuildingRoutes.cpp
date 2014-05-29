// BEGIN CUT HERE

// END CUT HERE
#line 5 "BuildingRoutes.cpp"
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
const int N = 55;
int a[N][N] , b[N][N];
class BuildingRoutes {
    public:
    int build(vector <string> dist, int T) {
    	int n = dist.size ();
    	for (int i = 0 ; i < n ; i ++) {
    		for (int j = 0 ; j < n ; j ++) {
    			b[i][j] = a[i][j] = dist[i][j] - '0';
    		}
    	}
    	for (int k = 0 ; k < n ; k ++) {
    		for (int i = 0 ; i < n ; i ++) {
    			for (int j = 0 ; j < n ; j ++) {
    				b[i][j] = min (b[i][j] , b[i][k] + b[k][j]);
    			}
    		}
    	}
    	int ans = 0;
    	for (int i = 0 ; i < n ; i ++) {
    		for (int j = 0 ; j < n ; j ++) {
    			if (i == j) continue;
    			int ok = 0;
    			for (int x = 0 ; x < n ; x ++) {
    				for (int y = 0 ; y < n ; y ++) {
    					if (b[x][y] == a[i][j] + b[x][i] + b[j][y]) {
    						ok ++;
    					}
    				}
    			}
    			if (ok >= T) ans += a[i][j];
    		}
    	}
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"011",
 "101",
 "110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 6; verify_case(0, Arg2, build(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"033",
 "309",
 "390"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 12; verify_case(1, Arg2, build(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"0123",
 "1023",
 "1203",
 "1230"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 5; verify_case(2, Arg2, build(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"05789654",
 "10347583",
 "65085479",
 "55602398",
 "76590934",
 "57939045",
 "12345608",
 "68647640"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 40; verify_case(3, Arg2, build(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    BuildingRoutes ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
