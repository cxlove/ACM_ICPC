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
typedef long long LL;
const int N = 1005;
const int HASH = 1000000007;
pair <int , int> p[N];
int dp[55][505] , n , w , h;
int main() {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        int H = 0;
        scanf ("%d %d %d" , &n , &h , &w);
        for (int i = 0 ; i < n ; i ++) {
            cin >> p[i].first >> p[i].second;
            H = max (H , p[i].second);
        }
        sort (p , p + n);
        memset (dp , 0x11 , sizeof (dp));
        if (p[0].second <= h) {
            dp[0][p[0].first] = 0;
            for (int i = 1 ; i <= 500 ; i ++) {
                if (p[0].second != H) {
                    dp[0][i] = abs(i - p[0].first) * p[0].second;
                }
            }
        }
        for (int i = 1 ; i < n ; i ++) {
            if (p[i].second <= h) {
                dp[i][p[i].first] = 0;
                for (int j = 1 ; j <= 500 ; j ++) {
                    if (p[i].second != H)
                        dp[i][j] = min (dp[i][j] , abs(j - p[i].first) * p[i].second);
                }
            }
            for (int j = 1 ; j < p[i].first ; j ++) {
                if (abs (j - p[i].first) <= w && p[i].second <= p[i - 1].second + h) {
                    dp[i][p[i].first] = min (dp[i][p[i].first] , dp[i - 1][j]);
                }
            }
            if (p[i].second != H && p[i].second <= p[i - 1].second + h) {
                for (int j = 1 ; j <= 500 ; j ++) {
                    for (int k = j + 1 ; k <= 500 ; k ++) {
                        if (abs (k - j) <= w) {
                            dp[i][k] = min (dp[i][k] , dp[i - 1][j] + p[i].second * abs (k - p[i].first));
                        }
                    }
                }
            }
        }
        int ans = 0x11111111;
        for (int i = 0 ; i < n ; i ++) {
            if (p[i].second == H) {
                ans = min (ans , dp[i][p[i].first]);
            }
        }
        memset (dp , 0x11 , sizeof (dp));
        reverse (p , p + n);
        if (p[0].second <= h) {
            dp[0][p[0].first] = 0;
            for (int i = 1 ; i <= 500 ; i ++) {
                if (p[0].second != H) {
                    dp[0][i] = abs(i - p[0].first) * p[0].second;
                }
            }
        }
        for (int i = 1 ; i < n ; i ++) {
            if (p[i].second <= h) {
                dp[i][p[i].first] = 0;
                for (int j = 1 ; j <= 500 ; j ++) {
                    if (p[i].second != H)
                        dp[i][j] = min (dp[i][j] , abs(j - p[i].first) * p[i].second);
                }
            }
            for (int j = p[i].first + 1 ; j <= 500 ; j ++) {
                if (abs (j - p[i].first) <= w && p[i].second <= p[i - 1].second + h) {
                    dp[i][p[i].first] = min (dp[i][p[i].first] , dp[i - 1][j]);
                }
            }
            if (p[i].second != H && p[i].second <= p[i - 1].second + h) {
                for (int j = 1 ; j <= 500 ; j ++) {
                    for (int k = 1 ; k < j ; k ++) {
                        if (abs (k - j) <= w) {
                            dp[i][k] = min (dp[i][k] , dp[i - 1][j] + p[i].second * abs (k - p[i].first));
                        }
                    }
                }
            }
        }
        for (int i = 0 ; i < n ; i ++) {
            if (p[i].second == H) {
                ans = min (ans , dp[i][p[i].first]);
            }
        }
        if (ans == 0x11111111) ans = -1;
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}