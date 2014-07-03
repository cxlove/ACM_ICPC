#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long long LL ;
const int N = 1005;
const int MOD = 10007;
char str[N];
int dp[N][N];
int main () {
    // freopen("input.txt" , "r" ,stdin);
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%s" , str);
        int l = strlen(str);
        memset (dp , 0 , sizeof(dp));
        for (int i = 0 ; i < l ; i ++) {
            dp[i][i] = 1;
        }
        for (int i = 1 ; i < l  ; i ++) {
            for (int j = 0 ; j + i < l ; j ++) {
                dp[j][j + i] = (dp[j + 1][j + i] + dp[j][j + i - 1]) % MOD;
                if (str[j] == str[j + i]) {
                    if (i == 1) dp[j][j + i] = (dp[j][j + i] + 1) % MOD;
                    else dp[j][j + i] = (dp[j][j + i] + dp[j + 1][j + i - 1] + 1) % MOD;
                }
                if (i > 1)
                    dp[j][j + i] = (dp[j][j + i] - dp[j + 1][j + i - 1] + MOD) % MOD;
                //cout << j << " " << j + i << " " << dp[j][j + i] << endl;
            }
        }
        printf("Case %d: %d\n" , ++cas , dp[0][l - 1]);
    }
    return 0;
}        

