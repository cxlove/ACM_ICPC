#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const int N = 2005;
int a[N] , n;
int dp[N][N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int n ;
    while (scanf ("%d" , &n) != EOF && n) {
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d" , &a[i]);
            a[n + i] = a[i];
        }
        for (int i = 1 ; i <= 2 * n ; i ++)
            dp[i][i] = 1;
        for (int l = 2 ; l <= n ; l ++) {
            for (int i = 1 ; i <= 2 * n ; i ++) {
                int j = i + l - 1;
                if (j > 2 * n) break;
                dp[i][j] = max (max (dp[i + 1][j] , dp[i][j - 1]) , dp[i + 1][j - 1] + (a[i] == a[j] ? 2 : 0));
            }
        }
        int ans = 0;
        for (int i = 1 ; i <= n ; i ++)
            ans = max (ans , dp[i][i + n - 1]);
        for (int i = 1 ; i <= n ; i ++) 
            ans = max (ans , dp[i][i + n - 2] + 1);
        printf ("%d\n" , ans);
    }
    return 0;
}