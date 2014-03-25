#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int N = 10005;
const int inf = 1000000007;
char str[N];
int n , w , flag[1005];
vector <string> v;
inline string get (int n) {
	string ans = "";
	while (n) {
		ans = ((char)('0' + n % 10)) + ans;
		n /= 10;
	}
	return ans;
}
int update (int can , int now) {
	if (now > can)
	flag[now - can - 1] = 1;
	int cnt = 0;
	for (int i = 0 ; i < w ; i ++) {
		if (flag[i]) cnt ++;
		else break;
	}
	for (int i = 0 ; i < 1005 ; i ++) {
		flag[i] = ((i + cnt) >=  1005) ? 0 : flag[i + cnt];
	}
	return can + cnt;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
	// freopen ("output.txt" , "w" , stdout);
#endif
	int t , cas = 0;scanf ("%d" , &t);
	while (t --) {
		memset (flag , 0 , sizeof (flag));
		scanf ("%d %d" , &n , &w);
		getchar ();
		int can = 0 , best = 0;
		for (int o = 0 ; o < n ; o ++) {
			gets (str);
			v.clear ();
			string s = "";
			for (int j = 0 ; str[j] ; j ++) {
				if (str[j] >= '0' && str[j] <= '9') {
					s = s + str[j];
				}
				else {
					if (s != "") v.push_back (s);
					s = "";
				}
			}
			if (s != "") v.push_back (s);
			int sz = v.size();
			for (int i = can + 1 ; i <= can + w ; i ++) {
				string p = get (i);
				int find = 0;
				for (int j = 0 ; j < sz ; j ++) {
					if (v[j].find (p) != string::npos) {
						find = 1;
						break;
					}
				}
				if (find) {
					best = max (best , i);
					can = update (can , i);
				}
			} 
		}		
		printf ("Case %d: %d %d\n" , ++ cas , can , best);
	}
	return 0;
}