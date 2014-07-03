#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
typedef long long LL;
int t , dp[1 << 16];
char str[20];
bool is[1 << 16];
int DP (int n) {
    if (dp[n] != -1) return dp[n];
    dp[n] = 1 << 20;
    for (int sub = n ; sub ; sub = (sub - 1) & n) {
        if (is[sub])
            dp[n] = min (dp[n] , DP(n - sub) + 1);
    }
    return dp[n];
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    scanf ("%d" , &t);
    while (t --) {
        memset (dp , -1 , sizeof(dp));
        dp[0] = 0;
        scanf ("%s" , str);
        int l = strlen(str);
        for (int i = 1 ; i < (1 << l) ; i ++) {
            char s[100];int len = 0;
            for (int j = 0 ; j < l ; j ++) {
                if ((1 << j) & i) {
                    s[len ++] = str[j];
                }
            }
            bool ok = true;
            for (int j = 0 , k = len - 1 ; j <= k ; j ++ , k --) {
                if (s[j] != s[k])
                    ok = false;
            }
            is[i] = ok;
        }
        printf ("%d\n" , DP((1 << l) - 1));
    }
    return 0;
}