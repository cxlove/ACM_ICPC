// BEGIN CUT HERE

// END CUT HERE
#line 5 "StringsNightmareAgain.cpp"
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
struct SAM  {  
    SAM *pre,*son[2];  
    int f,len;  
    LL cnt;  
}*root,*tail,que[N],*top[N];  
int tot ;
void add(int c,int l){  
    SAM *p=tail,*np=&que[tot++];  
    np->len=l;  
    while(p&&p->son[c]==NULL) p->son[c]=np,p=p->pre;  
    if(p==NULL) np->pre=root;  
    else{  
        SAM *q=p->son[c];  
        if(p->len+1==q->len) np->pre=q;  
        else{  
            SAM *nq=&que[tot++];  
            *nq=*q;  
            nq->len=p->len+1;  
            np->pre=q->pre=nq;  
            while(p&&p->son[c]==q) p->son[c]=nq,p=p->pre;  
        }  
    }  
    tail=np;  
} 
LL l[N] , r[N] , cnt[N];
class StringsNightmareAgain {
    public:
    long long UniqueSubstrings(int a, int b, int c, int d, int n) {
    	string s = "";
    	for (int i = 0 ; i < n ; i ++) {
    		s += "a";
    	}
    	for (int i = 0 ; i < a ; i ++) {
    		b = (1LL * b * c + d) % n;
    		s[b] = 'b';
    	}
    	cout << s << endl;
    	// build
    	tot = 0;
    	root = tail = &que[tot ++];
    	for (int i = 0 ; i < n ; i ++) {
    		add (s[i] - 'a' , i + 1);
    	}
    	// topsort
    	memset (cnt , 0 , sizeof (cnt));
    	for(int i=0;i<tot;i++) cnt[que[i].len]++;  
		for(int i=1;i<tot;i++) cnt[i]+=cnt[i-1];  
		for(int i=0;i<tot;i++) l[i]=n+10,r[i]=-1;
		for(int i=0;i<tot;i++) top[--cnt[que[i].len]]=&que[i];  

		// solve()
		for (int i = 0 ; ; i = que[i].son[s[que[i].len] - 'a'] - que) {
			l[i] = r[i] = que[i].len;
			if (que[i].len == n) break;
		}
		for (int i = tot - 1 ; i >= 0 ; i --) {
			int u = top[i] - que;
            if (que[u].pre == NULL) continue;
            int v = que[u].pre - que;
			l[v] = min (l[v] , l[u]);
			r[v] = max (r[v] , r[u]);
		};
		LL ans = 0;
		for (int i = 0 ; i < tot ; i ++) {
			if (que[i].pre == NULL) continue;
			int LEN = que[i].pre -> len;
			if (r[i] - l[i] > LEN) {
				LL pos = min (0LL + que[i].len  , r[i] - l[i]);
				ans += pos - LEN;
			}
		}
		return ans;
    }
    
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 0; int Arg1 = 0; int Arg2 = 0; int Arg3 = 0; int Arg4 = 4; long long Arg5 = 2LL; verify_case(0, Arg5, UniqueSubstrings(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; int Arg4 = 6; long long Arg5 = 3LL; verify_case(1, Arg5, UniqueSubstrings(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 1; int Arg3 = 1; int Arg4 = 6; long long Arg5 = 3LL; verify_case(2, Arg5, UniqueSubstrings(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 3; int Arg3 = 3; int Arg4 = 10; long long Arg5 = 5LL; verify_case(3, Arg5, UniqueSubstrings(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 3; int Arg2 = 2; int Arg3 = 3; int Arg4 = 11; long long Arg5 = 9LL; verify_case(4, Arg5, UniqueSubstrings(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_5() { int Arg0 = 10; int Arg1 = 1000000; int Arg2 = 1000000; int Arg3 = 1; int Arg4 = 51; long long Arg5 = 63LL; verify_case(5, Arg5, UniqueSubstrings(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
    StringsNightmareAgain ___test;
    ___test.run_test(5);
    return 0;
}
// END CUT HERE
