#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
using namespace std;
typedef long long LL;
int bit[25] , len;
LL dp[25][10];
LL A , B;
LL dfs (int l , int m , int limit) {
    if (l == 0) return m == 0 ? 1LL : 0LL;
    if (!limit && dp[l][m] != -1) return dp[l][m];
    int up = limit ? bit[l] : 9;
    LL ret = 0;
    for (int i = 0 ; i <= up ; i ++) {
        ret += dfs (l - 1 , (m + i) % 10 , limit && (i == up));
    }
    if (!limit) dp[l][m] = ret;
    return ret;
}
LL gao (LL n) {
    if (n < 0) return 0LL;
    len = 0;
    while (n) {
        bit[++ len] = n % 10;
        n /= 10;
    }
    return dfs (len , 0 , 1);
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    memset (dp , -1 , sizeof(dp));
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%I64d %I64d" , &A , &B);
        printf ("Case #%d: %I64d\n" , ++cas , gao (B) - gao (A - 1));
    }
    return 0;
}