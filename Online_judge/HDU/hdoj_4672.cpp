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
const int N = 105;
int dp[N * N];
int n , k , a[100005] , b[N];
char first[N] , second[N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d %d" , &n , &k) != EOF) {
        scanf ("%s %s" , first , second);
        for (int i = 0 ; i < n ; i ++)
            scanf ("%d" , &a[i]);
        int mn = 1 << 20 , mx = 0;
        for (int i = 0 ; i < k ; i ++) {
            scanf ("%d" , &b[i]);
            mn = min (mn , b[i]);
            mx = max (mx , b[i]);
        }
        memset (dp , -1 , sizeof(dp));
        dp[0] = 0;
        for (int i = 0 ; i < mx * mx ; i ++) {
            if (dp[i] == -1) continue;
            for (int j = 0 ; j < k ; j ++) {
                dp[i + b[j]] = max (dp[i + b[j]] , dp[i] + 1);
            }
        }
        bool cannot = false;
        int ans = 0;
        for (int i = 0 ; i < n ; i ++) {
            int cnt = max((a[i] - mx * mx + mn - 1) / mn , 0);
            if (dp[a[i] - cnt * mn] == -1) {
                cannot = true;
                break;
            }
            ans = ans ^ (cnt + dp[a[i] - cnt * mn]);
        }
        if (cannot) puts (second);
        else puts (ans ? first : second);
    }
    return 0;
}