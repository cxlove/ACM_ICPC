#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a , b)
#define lowbit(x) (x & (-x))
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const int N = 205;
int n , a[N];
double p[N];
char ope[N][5];
double dp[N][20];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t , cas = 0;
    while (scanf ("%d" , &n) != EOF) {
        for (int i = 0 ; i <= n ; i ++)
            scanf ("%d" , &a[i]);
        for (int i = 1 ; i <= n ; i ++)
            scanf ("%s" , ope[i]);
        for (int i = 1 ; i <= n ; i ++)
            scanf ("%lf" , &p[i]);
        memset (dp , 0 , sizeof(dp));
        for (int j = 0 ; j < 20 ; j ++)
            if ((1 << j) & a[0])
                dp[0][j] = 1.0;
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 0 ; j < 20 ; j ++) {
                if (ope[i][0] == '|') {
                    dp[i][j] += dp[i - 1][j];
                    if ((1 << j) & a[i]) dp[i][j] += (1 - dp[i - 1][j]) * (1 - p[i]); 
                }
                else if (ope[i][0] == '&') {
                    dp[i][j] += dp[i - 1][j] * p[i];
                    if ((1 << j) & a[i]) dp[i][j] += dp[i - 1][j] * (1 - p[i]);
                }
                else {
                    dp[i][j] += dp[i - 1][j] * p[i];
                    if ((1 << j) & a[i]) dp[i][j] += (1 - dp[i - 1][j]) * (1 - p[i]);
                    else dp[i][j] += dp[i - 1][j] * (1 - p[i]);
                }
            }
        }
        double ans = 0;
        for (int i = 0 ; i < 20 ; i ++) {
            ans += dp[n][i] * (1 << i);
        }
        printf ("Case %d:\n%.6f\n" , ++cas , ans);
    }
    return 0;
}