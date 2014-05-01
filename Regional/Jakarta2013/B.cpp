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
#include <queue>
#include <map>
#include <stack>
#include <cmath>
using namespace std;
const int N = 500005;
const int MOD = 1000000009;
int dp[2][N];
int n , m , d , a[N] , b[N];
void add (int &a , int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d %d" , &n , &m , &d);
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d" , &a[i]);
        }
        for (int i = 1 ; i <= m ; i ++) {
            scanf ("%d" , &b[i]);
        }
        memset (dp , 0 , sizeof (dp));
        dp[0][0] = 1;
        int l = 0 , r = 0;
        int prel = 0 , prer = 0;
        for (int i = 1 ; i <= m ; i ++) {
            while (l < n && b[i] >= a[l + 1] + d) l ++;
            while (r < n && b[i] + d > a[r + 1]) r ++;
            int now = i & 1 , pre = now ^ 1;
            int ret = 0;
            for (int j = prel ; j <= prer && j <= l ; j ++) {
                add (ret , dp[pre][j]);
            }
            dp[now][l] = ret;
            for (int j = l + 1 ; j <= r ; j ++) {
                if (j >= prel && j <= prer) add (ret , dp[pre][j]);
                dp[now][j] = ret;
            }
            prel = l;prer = r;
        }
        int ans = 0;
        for (int i = prel ; i <= prer ; i ++) {
            add (ans , dp[m & 1][i]);
        }
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}