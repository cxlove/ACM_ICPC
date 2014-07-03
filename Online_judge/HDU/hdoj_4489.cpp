#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 20;
char str[N];
LL dp[1 << N][N][2];
LL ret[20] = {1,2,4,10,32,122,544,2770,15872,101042,707584,5405530,44736512,398721962,3807514624LL,38783024290LL,419730685952LL,4809759350882LL,58177770225664LL,740742376475050LL};
int main () {
    // #ifndef ONLINE_JUDGE
    //     freopen ("input.txt" , "r" , stdin);
    //     // freopen ("output.txt" , "w" , stdout);
    // #endif
    int t ;
    scanf ("%d" , &t);
    // printf ("ret[20] = {");
    // for (int n = 1 ; n <= 20 ; n ++) {
    //     for (int i = 0 ; i < 1 << n ; i ++)
    //         for (int j = 0 ; j < n ; j ++)
    //             for (int k = 0 ; k < 2 ; k ++)
    //                 dp[i][j][k] = 0;
    //     for (int i = 0 ; i < n ; i ++)
    //         dp[1 << i][i][0] = dp[1 << i][i][1] = 1;
    //     for (int i = 1 ; i < 1 << n ; i ++) {
    //         for (int j = 0 ; j < n ; j ++) {
    //             if (i & (1 << j)) {
    //                 for (int k = 0 ; k < 2 ; k ++) {
    //                     for (int r = 0 ; r < n ; r ++) {
    //                         if (i & (1 << r)) continue;
    //                         if (r > j && k) continue;
    //                         if (r < j && !k) continue;
    //                         dp[i | (1 << r)][r][!k] += dp[i][j][k];
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //     LL ans = 0;
    //     for (int i = 0 ; i < n ; i ++)
    //         for (int j = 0 ; j < 2 ; j ++)
    //             ans += dp[(1 << n) - 1][i][j];
    //     cout << ans << ",";
    // }
    while (t --) {
        int cas , n;
        scanf ("%d %d" , &cas , &n);
        printf ("%d %I64d\n" , cas , ret[n - 1]);
    }
    return 0;
}