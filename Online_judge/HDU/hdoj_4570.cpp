#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <vector>
#define mp(a , b) make_pair(a , b)
using namespace std;
typedef long long LL;
int n;
LL a[100];
LL dp[100];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t;
    scanf ("%d" , &t);
    while (t --) {
        LL tot = 0;
        scanf ("%d" , &n);
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%lld" , &a[i]);
            tot += a[i] * 2;
        }
        memset (dp , 0x11 , sizeof(dp));
        dp[0] = 0;
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = max (1 , i - 19) ; j <= i ; j ++) {
                dp[i] = min (dp[i] , dp[j - 1] + a[j] * (1LL << (i - j + 1)));
            }
        }
        printf ("%lld\n" , dp[n]);
    }
    return 0;
}