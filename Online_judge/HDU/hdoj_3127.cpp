#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
using namespace std;
const int N = 1005;
int dp[N][N] , X , Y , x[N] , y[N] , c[N] , n;
int DP (int a , int b) {
    if (a > b) swap (a , b);
    if (a * b == 0) return dp[a][b] = 0;
    if (dp[a][b] != -1) return dp[a][b];
    int ret = 0;
    for (int i = 0 ; i < n ; i ++) {
        if (a >= x[i] && b >= y[i]) {
            ret = max (ret , c[i] + DP (x[i] , b - y[i]) + DP (a - x[i] , b));
            ret = max (ret , c[i] + DP (y[i] , a - x[i]) + DP (a , b - y[i]));
        }
        if (a >= y[i] && b >= x[i]) {
            ret = max (ret , c[i] + DP (y[i] , b - x[i]) + DP (a - y[i] , b));
            ret = max (ret , c[i] + DP (x[i] , a - y[i]) + DP (b - x[i] , a));
        }
    }
    return dp[a][b] = ret;
}
int main () {
    int t ;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d %d" , &n , &X , &Y);
        memset (dp , -1 , sizeof(dp));
        for (int i = 0 ; i < n ; i ++)
            scanf ("%d %d %d" , &x[i] , &y[i] , &c[i]);
        if (X > Y) swap (X , Y);
        printf ("%d\n" , DP (X , Y));
    }
    return 0;
}    