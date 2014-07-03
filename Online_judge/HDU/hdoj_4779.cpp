#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const int N = 205;
int n , m , p , q;
LL c[N][N] , dp[N][N][N] , fac[N];
void Init () {
    for (int i = 0 ; i < N ; i ++) {
        c[i][0] = 1LL;
        for (int j = 1 ; j <= i ; j ++) 
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
    fac[0] = 1LL;
    for (int i = 1 ; i < N ; i ++)
        fac[i] = fac[i - 1] * i % MOD;
}
inline void add (LL &a , LL b) {
    a += b;if (a >= MOD) a -= MOD;
}
inline LL mut (LL a , LL b) {
    a %= MOD; b %= MOD;
    return 1LL * a * b % MOD;
}
LL gao (int i , int j , int k) {
    if (dp[i][j][k] != -1) return dp[i][j][k];
    if (k == 0) return dp[i][j][k] = 1;
    if (i * j == 0) return dp[i][j][k] = 0;
    LL ret = 0;
    add (ret , gao (i - 1 , j , k));
    add (ret , gao (i - 1 , j - 1 , k - 1) * c[j][1] % MOD);
    if (j >= 2 && k >= 2) add (ret , gao (i - 1 , j - 2 , k - 2) * c[j][2] % MOD);
    if (i >= 2 && k >= 2) add (ret , gao (i - 2 , j - 1 , k - 2) * c[j][1] * c[i - 1][1] % MOD);
    return dp[i][j][k] = ret;
}
int main () { 
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    Init ();
    int t;scanf ("%d" , &t);
    memset (dp , -1 , sizeof(dp));
    while (t --) {
        LL answer = 0LL;
        scanf ("%d %d %d %d" , &n , &m , &p , &q);
        for (int i = 0 ; i <= q && i <= n && i <= m ; i ++) {
            for (int j = 0 ; j <= p ; j ++) {
                if (i + j == 0) continue;
                add (answer , mut (mut (c[n][i] * c[m][i] % MOD , fac[i]) , gao (n - i , m - i , j)));
            }
        }
        printf ("%I64d\n" , answer); 
    }
    return 0;
}