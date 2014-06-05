// BEGIN CUT HERE

// END CUT HERE
#line 5 "CatchTheBeat.cpp"
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
const int N = 500005;
struct Node {
	int x , y , id;
	Node () {}
	Node (int _x , int _y , int _id) {
		x = _x;y = _y;id = _id;
	}
};
bool cmpy (Node n1 , Node n2) {
	return n1.y != n2.y ? n1.y < n2.y : n1.x < n2.x;
}
bool cmpx (Node n1 , Node n2) {
	return n1.x != n2.x ? n1.x < n2.x : n1.y < n2.y;
}
int id[N];
vector <Node> p , q;
struct Tree {
	int left , right;
	vector <int> xplusy , xsuby;
	vector <int> mxplus , mxsub;
}L[N << 2];
#define lson step << 1
#define rson step << 1 | 1
void build (int step , int l , int r) {
	L[step].left = l;
	L[step].right = r;
	L[step].xplusy.clear ();
	L[step].xsuby.clear ();
	L[step].mxsub.clear ();
	L[step].mxplus.clear ();

	if (l == r) {
		L[step].xplusy.push_back (p[l].x + p[l].y);
		L[step].xsuby.push_back (p[l].y - p[l].x);
		L[step].mxplus.push_back (-1);
		L[step].mxsub.push_back (-1);
		return ;
	}
	int m = (l + r) >> 1;
	build (lson , l , m);
	build (rson , m + 1 , r);
	for (int i = 0 ; i < L[lson].xplusy.size() ; i ++) {
		L[step].xplusy.push_back (L[lson].xplusy[i]);
		L[step].xsuby.push_back (L[lson].xsuby[i]);

		L[step].mxsub.push_back (L[lson].mxsub[i]);
		L[step].mxplus.push_back (L[lson].mxplus[i]);
	}
	for (int i = 0 ; i < L[rson].xplusy.size() ; i ++) {
		L[step].xplusy.push_back (L[rson].xplusy[i]);
		L[step].xsuby.push_back (L[rson].xsuby[i]);

		L[step].mxsub.push_back (L[rson].mxsub[i]);
		L[step].mxplus.push_back (L[rson].mxplus[i]);
	}
	sort (L[step].xplusy.begin () , L[step].xplusy.end ());
	sort (L[step].xsuby.begin () , L[step].xsuby.end ());
}
inline int lowbit (int x) {
	return x & (-x);
}
int sum (vector <int> &v , int x) {
	int ret = -1;
	for (int i = x + 1 ; i > 0 ; i -= lowbit (i)) {
		ret = max (ret , v[i - 1]);
	}
	return ret;
}
void add (vector <int> &v , int x , int val) {
	for (int i = x + 1 ; i <= v.size() ; i += lowbit (i)) {
		v[i - 1] = max (v[i - 1] , val);
	}
}
int ask1 (int step , int l , int r , int v) {
	if (l > r) return -1;
	if (L[step].left == l && L[step].right == r) {
		int pos = upper_bound (L[step].xsuby.begin () , L[step].xsuby.end () , v) - L[step].xsuby.begin () - 1;
		// cout << l << " " << r << " " << pos << " " << v << endl;
		if (pos >= 0) {
			return sum (L[step].mxsub , pos);
		}
		else return -1;
	}
	int m = (L[step].left + L[step].right) >> 1;
	if (r <= m) return ask1 (lson , l , r , v);
	else if (l > m) return ask1 (rson , l , r , v);
	else return max (ask1 (lson , l , m , v) , ask1 (rson , m + 1 , r , v));
}
int ask2 (int step , int l , int r , int v) {
	if (l > r) return -1;
	if (L[step].left == l && L[step].right == r) {
		int pos = upper_bound (L[step].xplusy.begin () , L[step].xplusy.end () , v) - L[step].xplusy.begin () - 1;
		if (pos >= 0) {
			return sum (L[step].mxplus , pos);
		}
		else return -1;
	}
	int m = (L[step].left + L[step].right) >> 1;
	if (r <= m) return ask2 (lson , l , r , v);
	else if (l > m) return ask2 (rson , l , r , v);
	else return max (ask2 (lson , l , m , v) , ask2 (rson , m + 1 , r , v));
}
void upd1 (int step , int pos , int val , int xy) {
	if (pos < L[step].left || pos > L[step].right) return;
	int p = lower_bound (L[step].xsuby.begin () , L[step].xsuby.end () , xy) - L[step].xsuby.begin ();
	add (L[step].mxsub , p , val);
	if (L[step].left == L[step].right) 
		return ;
	int m = (L[step].left + L[step].right) >> 1;
	if (pos <= m) upd1 (lson , pos , val , xy);
	else upd1 (rson , pos , val , xy);
}
void upd2 (int step , int pos , int val , int xy) {
	if (pos < L[step].left || pos > L[step].right) return;
	int p = lower_bound (L[step].xplusy.begin () , L[step].xplusy.end () , xy) - L[step].xplusy.begin ();
	add (L[step].mxplus , p , val);
	if (L[step].left == L[step].right) 
		return ;
	int m = (L[step].left + L[step].right) >> 1;
	if (pos <= m) upd2 (lson , pos , val , xy);
	else upd2 (rson , pos , val , xy);
}
class CatchTheBeat {
    public:
    int maxCatched(int n, int x0, int y0, int a, int b, int c, int d, int mod1, int mod2, int offset) {
        p.clear ();q.clear ();
        p.push_back (Node (x0 , y0 , 0));
        for (int i = 1 ; i < n ; i ++) {
        	x0 = (1LL * x0 * a + b) % mod1;
        	y0 = (1LL * y0 * c + d) % mod2;
        	p.push_back (Node (x0 , y0 , i));
        }
        for (int i = 0 ; i < n ; i ++) {
        	p[i].x -= offset;
        }
        q = p;
        sort (p.begin () , p.end () , cmpx);
        sort (q.begin () , q.end () , cmpy);
        for (int i = 0 ; i < n ; i ++) {
        	id[p[i].id] = i;
        } 
        build (1 , 0 , n - 1);
        int ans = 0;
        for (int i = 0 ; i < n ; i ++) {
        	int ret = 0;
        	if (q[i].y >= abs(q[i].x))
        		ret = 1;
        	int pos = id[q[i].id];
        	ret = max (ret , max (ask1 (1 , 0 , pos , q[i].y - q[i].x) , ask2 (1 , pos + 1 , n - 1 , q[i].y + q[i].x)) + 1);
        	if (ret > 0) upd1 (1 , pos , ret , q[i].y - q[i].x);
        	if (ret > 0) upd2 (1 , pos , ret , q[i].y + q[i].x);
        	ans = max (ans , ret);
        }
        return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 100; int Arg8 = 100; int Arg9 = 1; int Arg10 = 2; verify_case(0, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 1234; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 1000; int Arg10 = 1; verify_case(1, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 0; int Arg2 = 999; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 1000; int Arg10 = 0; verify_case(2, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_3() { int Arg0 = 100; int Arg1 = 0; int Arg2 = 0; int Arg3 = 1; int Arg4 = 1; int Arg5 = 1; int Arg6 = 1; int Arg7 = 3; int Arg8 = 58585858; int Arg9 = 1; int Arg10 = 66; verify_case(3, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_4() { int Arg0 = 500000; int Arg1 = 123456; int Arg2 = 0; int Arg3 = 1; int Arg4 = 0; int Arg5 = 1; int Arg6 = 1; int Arg7 = 1000000000; int Arg8 = 1000000000; int Arg9 = 0; int Arg10 = 376544; verify_case(4, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_5() { int Arg0 = 500000; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 0; int Arg5 = 0; int Arg6 = 0; int Arg7 = 1; int Arg8 = 1; int Arg9 = 0; int Arg10 = 500000; verify_case(5, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_6() { int Arg0 = 10; int Arg1 = 999999957; int Arg2 = 79; int Arg3 = 993948167; int Arg4 = 24597383; int Arg5 = 212151897; int Arg6 = 999940854; int Arg7 = 999999986; int Arg8 = 999940855; int Arg9 = 3404; int Arg10 = 3; verify_case(6, Arg10, maxCatched(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    CatchTheBeat ___test;
    ___test.run_test(6);
    return 0;
}
// END CUT HERE
