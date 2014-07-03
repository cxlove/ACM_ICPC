#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2005;
const int inf = 1000000007;
int n , m , w , dp[N][N];
int b[N] , s[N] , bl[N] , sl[N];
pair <int , int> que[N];
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
#endif
    int t;scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d %d" , &n , &m , &w);
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d %d %d %d" , b + i , s + i , bl + i , sl + i);
        }
        for (int i = 0 ; i <= n ; i ++) {
            for (int j = 0 ; j <= m ; j ++)
                dp[i][j] = -inf;
        }
        for (int i = 1 ; i <= n ; i ++) {
            dp[i][0] = 0;
            int lim = min (m , bl[i]);
            for (int j = 1 ; j <= lim ; j ++)
                dp[i][j] = -j * b[i];
        }
        for (int i = 2 ; i <= n ; i ++) {
            for (int j = 0 ; j <= m ; j ++) {
                dp[i][j] = max (dp[i - 1][j] , dp[i][j]);
            }
            int pre = i - w - 1;
            if (pre < 1) continue;
            int head = 0 , tail = 0;
            // buy
            for (int j = 0 ; j <= m ; j ++) {
                int tmp = dp[pre][j] + j * b[i];
                while (head < tail && que[tail - 1].first <= tmp) tail --;
                que[tail ++] = make_pair (tmp , j);
                while (head < tail && que[head].second + bl[i] < j) head ++;
                if (head < tail) dp[i][j] = max (dp[i][j] , que[head].first - j * b[i]);
            }
            head = 0;tail = 0;
            // sale
            for (int j = m ; j >= 0 ; j --) {
                int tmp = dp[pre][j] + j * s[i];
                while (head < tail && que[tail - 1].first <= tmp) tail --;
                que[tail ++] = make_pair (tmp , j);
                while (head < tail && que[head].second - sl[i] > j) head ++;
                if (head < tail) dp[i][j] = max (dp[i][j] , que[head].first - j * s[i]);
            }
        }
        int ans = -inf;
        for (int i = 0 ; i <= m ; i ++)
            ans = max (ans , dp[n][i]);
        printf ("%d\n" , ans);
    }
    return 0;
}