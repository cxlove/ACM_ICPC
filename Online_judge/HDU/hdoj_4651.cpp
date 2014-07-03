#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100005;
const int MOD = 1000000007;
int dp[N];
void Init () {
    dp[0]=1;dp[1] = 1; dp[2] = 2;
    for (int i = 3 ; i < N ; i ++) {
        for (int j = 1 ; ; j ++) {
            int k;
            for (int r = 0 ; r < 2 ; r ++) {
                if (r % 2 == 0) k = (3 * j * j - j) / 2;
                else k = (3 * j * j + j) / 2;
                if (k > i) break;
                if (j & 1)
                dp[i] = (dp[i] + dp[i - k]) % MOD;
                else dp[i] = (dp[i] - dp[i - k] + MOD) % MOD;  
            }
            if (k > i) break;
        }
    }
}
int main () {
    int t , n;
    Init();
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        printf ("%d\n" , dp[n]);
    }
    return 0;
}        

