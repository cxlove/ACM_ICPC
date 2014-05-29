// BEGIN CUT HERE

// END CUT HERE
#line 5 "Ethernet.cpp"
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
class Ethernet {
    public:
    int ans , n , lim;
    vector <pair <int , int> > e[N];
    int dfs (int u , int pre) {
        vector <int> son;
        for (int i = 0 ; i < e[u].size() ; i ++) {
            int v = e[u][i].first , w = e[u][i].second;
            if (v == pre) continue;
            int t = dfs (v , u);
            if (t + w > lim) {
                ans ++;
            }
            else {
                son.push_back (t + w);
            }
        }
        sort (son.rbegin () , son.rend ());
        int m = 0;
        while (m < (int)son.size() - 1) {
            if (son[m] + son[m + 1] > lim) {
                ans ++;
                m ++;
            }
            else break;
        }
        if (m < son.size ()) {
            return son[m];
        }
        return 0;
    }
    int connect(vector <int> parent, vector <int> dist, int maxDist) {
    	n = parent.size () + 1;
        for (int i = 0 ; i < n ; i ++)
            e[i].clear ();
        for (int i = 0 ; i < n - 1 ; i ++) {
            e[parent[i]].push_back (make_pair (i + 1 , dist[i]));
            e[i + 1].push_back (make_pair (parent[i] , dist[i]));
        }
        lim = maxDist;
        ans = 1;
        dfs (0 , -1);
    	return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 1; verify_case(0, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {0,0,0,0,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6,7}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; int Arg3 = 4; verify_case(1, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {0,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,2,3,4,5,6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 6; int Arg3 = 3; verify_case(2, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {0,0,0,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1,1,1,1,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 2; verify_case(3, Arg3, connect(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0,1,0,3,0,5,0,6,0,6,0,6,4,6,9,4,5,5,2,5,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {93,42,104,105,59,73,161,130,30,81,62,93,131,133,139,5,13,34,25,111,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 162; int Arg3 = 11; verify_case(4, Arg3, connect(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    Ethernet ___test;
    ___test.run_test(-1);
    return 0;
}
// END CUT HERE
