#include <iostream>
#include <cstdio>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
typedef unsigned long long LL;
int main () {
#ifndef ONLINE_JUDGE
	freopen ("input.txt" , "r" , stdin);
#endif
    int t;scanf ("%d" , &t);
    while (t --) {
        int id , n;
        scanf ("%d %d" , &id , &n);
        int ans = 0;
        // a = b = c;
        if (n % 3 == 0) ans ++;
        // a = b < c
        for (int a = 1 ; a <= n / 3 ; a ++) {
            int c = n - 2 * a;
            if (a < c && a + a > c) {
                ans += 1;
            }
        }
        // a < b = c
        for (int c = 1 ; c <= n ; c ++) {
            int a = n - 2 * c;
            if (a > 0 && a < c) {
                ans += 1;
            }
        }
        // a < b < c
        for (int c = 1 ; c <= n ; c ++) {
            int s = n - c;   // a + b
            if (s > c) {
                int l = s - (c - 1);
                int r = min (c - 1 , s - 1);
                if (l <= r) {
                    int cnt = (r - l + 1);
                    if (s % 2 == 0 && s / 2 < c) {
                        cnt --;
                    }
                    cnt /= 2;
                    ans += cnt * 2;
                }
            }
        }
        printf ("%d %d\n" , id , ans);
    }
	return 0;
}