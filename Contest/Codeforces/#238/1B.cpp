#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;
typedef long long LL;
const int N = 1000005;
int n , a[N] , b[N];
int ans[N] , m = 0 , c[N] , cnt = 0;
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	scanf ("%d" , &n);
	for (int i = 1 ; i <= n ; i ++) {
		scanf ("%d" , &a[i]);
		b[a[i]] = 1;
	}
	for (int i = 1 ; i <= 500000 ; i ++) {
		int j = 1000001 - i;
		if (b[i] && b[j] == 0) {
			ans[m ++] = j;
		}
		else if (b[j] && b[i] == 0) {
			ans[m ++] = i;
		}
		else if (!b[i] && !b[j]) {
			c[cnt ++] = i;c[cnt ++] = j;
		}
	}
	printf ("%d\n" , n);
	for (int i = 0 ; i < m ; i ++) {
		printf ("%d\n" , ans[i]);
	}
	for (int i = m ; i < n ; i ++) {
		printf ("%d\n" , c[i - m]);
	}
	return 0;
}