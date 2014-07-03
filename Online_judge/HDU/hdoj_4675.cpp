#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define lson step << 1
#define rson step << 1 | 1
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const int MOD = 1000000007;
const int N = 300005;
int n , m , k , a[N] , c[N];
LL fac[N] , inv[N] , dp[N];
LL INV (LL x) {
    return x <= 1 ? x : (MOD - MOD / x) * INV (MOD % x) % MOD;
}
LL PowMod (LL a , LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
LL Com (int n , int m) {
    return (fac[n] * inv[m] % MOD) * inv[n - m] % MOD;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    fac[0] = 1;inv[0] = INV (fac[0]);
    for (int i = 1 ; i < N ; i ++) {
        fac[i] = fac[i - 1 ] * i % MOD;
        inv[i] = INV (fac[i]);
    }
    while (scanf ("%d %d %d" , &n , &m , &k) != EOF) {
        memset (c , 0 , sizeof(c));
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d" , &a[i]);
            c[a[i]] ++;
        }
        for (int d = m ; d >= 1 ; d --) {
            int cnt = 0 , tot = 0;
            dp[d] = 0;
            for (int i = 1 ; i * d <= m ; i ++) {
                cnt += c[i * d];
                tot ++;
            }
            if (n - cnt > k) continue;
            dp[d] = PowMod (tot , n - cnt);
            if (cnt - (n - k)) {
                dp[d] = (dp[d] * Com (cnt , n - k) % MOD) * PowMod (tot - 1 , cnt - n + k) % MOD;
            }
            for (int i = 2 ; i * d <= m ; i ++) {
                dp[d] -= dp[i * d];
                dp[d] = (dp[d] % MOD + MOD) % MOD;
            }
        }
        for (int i = 1 ; i <= m ; i ++)
            printf ("%I64d%c" , dp[i] , i == m ? '\n' : ' ');
    }
    return 0;    
}