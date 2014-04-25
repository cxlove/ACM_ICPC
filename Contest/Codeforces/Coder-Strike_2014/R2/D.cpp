#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
const int N = 2005;
const int MOD = 1000000007;
int n , k , a[N] , p[N] , cnt[N];
int dp[N][1 << 12];
void add (int &a , int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    p[0] = 1;
    for (int i = 1 ; i < N ; i ++)
        p[i] = (p[i - 1] * 2) % MOD;
    cin >> n >> k;k --;
    for (int i = 1 ; i <= n ; i ++) {
        cin >> a[i - 1];
        a[i - 1] /= 2;
    }
    for (int i = n ; i >= 1 ; i --) {
        cnt[i] = cnt[i + 1] + (a[i - 1] == 0);
    }
    dp[0][0] = 1;
    int ans = 0;
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < 1 << k ; j ++) {
            if (dp[i][j] == 0) continue;
            // cout << i << " " << j << " " << dp[i][j] << endl;
            int newj = j;
            if (a[i]) {
                if (a[i] == 2 && (j & 1)) {
                    newj = 2;
                }
                else newj += a[i];
                add (dp[i + 1][newj] , dp[i][j]);
            }
            else {
                add (dp[i + 1][j + 1] , dp[i][j]);
                if ((j & 1))
                    add (dp[i + 1][2] , dp[i][j]);
                else add (dp[i + 1][j + 2] , dp[i][j]);
            }
        }
        for (int j = 1 << k ; j < (1 << (k + 1)) ; j ++)
            add (ans , 1LL * dp[i + 1][j] * p[cnt[i + 2]] % MOD);
    }
    cout << ans << endl;
    return 0;
}