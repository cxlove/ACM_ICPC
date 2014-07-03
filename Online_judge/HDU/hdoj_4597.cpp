#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int N = 22;

int n, dp[N][N][N][N], a[N], b[N], sa[N], sb[N];

int DP(int s1, int t1, int s2, int t2) {
    if (dp[s1][t1][s2][t2] != -1) return dp[s1][t1][s2][t2];

    int ret = 0, sum = sa[t1] - sa[s1 - 1] + sb[t2] - sb[s2 - 1], tmp;
    if (s1 <= t1) {
        tmp = sum - DP(s1 + 1, t1, s2, t2);
        ret = max(ret, tmp);
        tmp = sum - DP(s1, t1 - 1, s2, t2);
        ret = max(ret, tmp);
    }
    if (s2 <= t2) {
        tmp = sum - DP(s1, t1, s2 + 1, t2);
        ret = max(ret, tmp);
        tmp = sum - DP(s1, t1, s2, t2 - 1);
        ret = max(ret, tmp);
    }
    return dp[s1][t1][s2][t2] = ret;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);

        sa[0] = sb[0] = 0;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sa[i] = sa[i - 1] + a[i];
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]), sb[i] = sb[i - 1] + b[i];

        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= n; i++) dp[i][i][i][i] = max(a[i], b[i]);
        printf("%d\n", DP(1, n, 1, n));
    }
    return 0;
}

