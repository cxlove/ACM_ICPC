#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
#include <ctime>
#include <map>
#include <stack>
#include <cmath>
using namespace std;
const int N = 105;
const int MOD = 1000000007;
int n , m , a[N];
long long dp[N][N];
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &n , &m);
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d" , &a[i]);
        }
        sort (a + 1 , a + 1 + n);
        memset (dp , 0x11 , sizeof (dp));
        dp[0][0] = 0;
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                for (int k = 0 ; k < i ; k ++) {
                    dp[i][j] = min (dp[i][j] , dp[k][j - 1] + a[i] - a[k + 1]);
                }
            }
        }
        printf ("Case #%d: %lld\n" , ++ cas , dp[n][m]);
    }
    return 0;
}