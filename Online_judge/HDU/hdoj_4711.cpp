#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int n, m, w, wd[1005], way[1005][105];
double go[105][105], wp[105][105], dp[1005][105];

int main() {  
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &w);
        for (int i = 1; i <= n; i++) scanf("%d", &wd[i]);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++) {
                scanf("%lf", &go[i][j]);
                go[i][j] = log (go[i][j]);
            }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < w; j++) scanf("%lf", &wp[i][j]);
        for (int i = 0; i < m; i++) dp[n][i] = log(wp[i][wd[n]]);
        for (int d = n - 1; d >= 0; d--) {
            for (int i = 0; i < m; i++) {
                dp[d][i] = -(1 << 20);
                for (int j = 0; j < m; j++) {
                    double tmp = dp[d + 1][j] + go[i][j];
                    if (tmp > dp[d][i]) 
                        dp[d][i] = tmp, way[d][i] = j;
                }
                dp[d][i] += log(wp[i][wd[d]]);
            }
        }
        for (int i = way[0][0], d = 1; d <= n; d++) {
            printf("%d", i);
            if (d != n) printf(" "); else printf("\n");
            i = way[d][i];
        }
    }
    return 0;
}