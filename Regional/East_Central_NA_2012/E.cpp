#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int N = 10;
const int inf = 1000000007;
char ope[N] , str[N];
int a[N] , id[N];
int cal (int a , char ope , int b) {
	if (ope == '+') return a + b;
	if (ope == '-') return a - b;
	return a * b;
}
int dfs (char *ope , int *val , int remain , int who , int pre) {
	int newval[N];char newope[N];
	for (int i = 0 ; i < pre ; i ++) {
		newval[i] = val[i];
		newope[i] = ope[i];
	}
	newval[pre] = cal (val[pre] , ope[pre] , val[pre + 1]);
	for (int i = pre + 1 ; i <= remain ; i ++) {
		newval[i] = val[i + 1];
		newope[i - 1] = ope[i];
	}
	// for (int i = 0 ; i < remain ; i ++) {
	// 	printf ("%d %c " , newval[i] , ope[i]);
	// }
	// printf ("%d\n" , newval[remain]);
	if (remain == 0) {
		return newval[0];
	}
	int ret;
	if (who) ret = inf;
	else ret = -inf;
	for (int i = 0 ; i < remain ; i ++) {
		int value = dfs (newope , newval , remain - 1 , who ^ 1 , i);
		if (who) ret = min (ret , value);
		else ret = max (ret , value);
	}
	return ret;
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	int t , cas = 0;
	scanf ("%d" , &t);
	while (t --) {
		int n;
		scanf ("%d" , &n);
		for (int i = 0 ; i < 2 * n + 1 ; i ++) {
			if (i & 1) {
				scanf ("%s" , str);
				ope[i / 2] = str[0];
			}
			else scanf ("%d" , &a[i / 2]);
		}
		// ope[n] = '\0';puts (ope);
		printf ("Case %d:\n" , ++ cas);
		int mx = -inf , first;
		for (int i = 0 ; i < n ; i ++) {
			int tmp = dfs (ope , a , n - 1 , 1 , i);
			if (tmp > mx) {
				mx = tmp;
				first = i;
			}
		}
		printf ("Player 1 (%d%c%d) leads to %d\n" , a[first] , ope[first] , a[first + 1] , mx);
		int mn = inf , second;
		for (int i = 0 ; i < n ; i ++) {
			int tmp = dfs (ope , a , n - 1, 0 , i);
			if (tmp < mn) {
				mn = tmp;
				second = i;
			}
		}
		printf ("Player 2 (%d%c%d) leads to %d\n" , a[second] , ope[second] , a[second + 1] , mn);
		if (mx > -mn) puts ("Player 1 wins");
		else if (mx == -mn) puts ("Tie");
		else puts ("Player 2 wins");
	}
	return 0;
}