#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int N = 18;
typedef long long LL;
LL c[N][N] , fac[N];
LL A (int n , int m) {
	return fac[n] / fac[n - m];
}
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	for (int i = 0 ; i < N ; i ++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1 ; j < i ; j ++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	fac[0] = 1;
	for (int i = 1 ; i < N ; i ++)
		fac[i] = fac[i - 1] * i;
	int t;scanf ("%d" , &t);
	while (t --) {
		int id , n , k;
		scanf ("%d %d %d" , &id , &n , &k);
		LL ans = A (n , k);
		for (int i = 1 ; i <= k ; i ++) {
			LL ret = c[k][i] * A (n - i , k - i);
			if (i & 1) ans = ans - ret;
			else ans += ret;
		}
		printf ("%d %lld\n" , id , ans * fac[n - k ]);
	}
	return 0;
}