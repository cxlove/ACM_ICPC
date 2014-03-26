#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 55;
const int INF = 100000007;
int n , a[N];
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
	int t;scanf ("%d" , &t);
	while (t --) {
		int id;scanf ("%d" , &id);
		int cnt = 0;
		for (int i = 1 ; i <= 15 ; i ++) {
			scanf ("%d" , &a[i]);
		}
		for (int l = 2 ; l <= 15 ; l ++) {
			for (int r = l ; r < 15 ; r ++) {
				if (a[l] == a[r]) {
					if (a[l - 1] < a[l] && a[r + 1] < a[r]) {
						int ok = 1;
						for (int j = l + 1 ; j < r ; j ++) {
							if (a[j] < a[l]) {
								ok = 0;
							}
						}
						if (ok) cnt ++;
					}
				}
			}
		}
		printf ("%d %d\n" , id , cnt);
	}
	return 0;
}