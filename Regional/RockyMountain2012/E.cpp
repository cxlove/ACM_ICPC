#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int N = 18;
int n , dp[1 << N];
char str[N][N + 1];
vector <int> ans;
void gao (int m) {
    if (!m) return;
    int need = dp[m];
    for (int i = 0 ; i < n ; i ++) {
        if (m & (1 << i)) {
            int cost = 0;
            for (int j = 0 ; j < n ; j ++) {
                if (i == j || m & (1 << j)) continue;
                if (str[i][j] == '1') cost ++;
            }
            if (cost + dp[m ^ (1 << i)] == need) {
                ans.push_back (i);
                gao (m ^ (1 << i));
                return ;
            } 
        }
    }
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    while (scanf ("%d" , &n) != EOF && n) {
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%s" , str[i]);
        }
        memset (dp , 0x11 , sizeof (dp));
        dp[0] = 0;
        for (int i = 0 ; i < 1 << n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                if (i & (1 << j)) continue;
                int cost = 0;
                for (int k = 0 ; k < n ; k ++) {
                    if (j == k || i & (1 << k)) continue;
                    if (str[j][k] == '1') cost ++;
                }
                dp[i | (1 << j)] = min (dp[i | (1 << j)] , dp[i] + cost);
            }
        }
        ans.clear ();
        gao ((1 << n) - 1);
        for (int i = 0 ; i < n - 1 ; i ++)
            printf ("%d " , ans[i]);
        printf ("%d\n" , ans[n - 1]);
        printf ("%d\n" , dp[(1 << n) - 1]);
    }
    return 0;
}