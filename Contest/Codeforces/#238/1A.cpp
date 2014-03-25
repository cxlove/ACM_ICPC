#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
const int N = 1005;
int n, a[N][N] , b[N];
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	scanf ("%d" , &n);
	for (int i = 1 ; i <= n ; i ++) {
		for (int j = 1 ; j <= n ; j ++)
			scanf ("%d" , &a[i][j]);
		b[i] = a[i][i];
	}
	int ans = 0;
	for (int i = 1 ; i <= n ; i ++) {
		ans ^= b[i];
	} 
	int q;scanf ("%d" , &q);
	while (q --) {
		int k;scanf ("%d" , &k);
		if (k == 3) {
			printf ("%d" , ans);
		}
		else {
			int r;scanf ("%d" , &r);
			ans ^= 1;
		}
	}
	return 0;
}