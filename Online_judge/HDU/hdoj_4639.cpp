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
const int MOD = 10007;
const int N = 200005;
char str[N];
int dp[N][2] = {1};
bool check(int p) {
    if (str[p] == 'h' && str[p + 1] == 'e')
        return true;
    return false;
}
int main () {
    // freopen("input.txt" , "r" , stdin);
    int t , cas = 0;
    scanf ("%d" , &t);
    dp[0][0] = 1; dp[0][1] = 0;
    dp[1][0] = 1; dp[1][1] = 0;
    dp[2][0] = 1; dp[2][1] = 1;
    for (int i = 3 ; i < N ; i ++) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
        dp[i][1] = (dp[i - 2][1] + dp[i - 2][0]) % MOD; 
    }
    while (t --) {
        scanf ("%s" , str);
        int cnt = 0 , ans = 1;
        for (int i = 0 ; str[i] ;) {
            if (check(i)) {
                cnt ++ ;
                i += 2;
            }
            else {
                ans = (ans * (dp[cnt][0] + dp[cnt][1])) % MOD;
                cnt = 0;
                i ++;
            }
        }
        ans = (ans * (dp[cnt][0] + dp[cnt][1])) % MOD;
        printf ("Case %d: %d\n" , ++ cas , ans);
    }
    return 0;
}        