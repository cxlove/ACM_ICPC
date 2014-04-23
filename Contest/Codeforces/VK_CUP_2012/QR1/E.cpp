#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
using namespace std;
const int N = 4005;
const int inf = N * 10;
int dp[N][N] , n , k;
pair <int , int> a[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i].first >> a[i].second;
    }
    memset (dp , 0x11 , sizeof (dp));
    dp[0][0] = 0;
    int ans = 0;
    sort (a , a + n);
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j <= k ; j ++) {
            if (dp[i][j] == 0x11111111) continue;
            if (a[i].first > dp[i][j]) {
                ans = max (ans , a[i].first - dp[i][j] - 1);
            }
            int st = max (a[i].first , dp[i][j] + 1);
            dp[i + 1][j] = min (dp[i + 1][j] , st + a[i].second - 1);
            dp[i + 1][j + 1] = min (dp[i + 1][j + 1] , dp[i][j]);
        }
    }
    for (int i = 0 ; i <= k ; i ++) {
        ans = max (ans , 86400 - dp[n][i]);
    }
    cout << ans << endl;
    return 0;
}