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
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
using namespace std;
typedef long long LL;
const int N = 4600;
const int M = 11;
int dp[M][N] = {0};
int t , cas = 0 , m  , n ;
void Init () {
    for (int i = 0 ; i < 10 ; i ++)
        dp[0][i] = 1;
    for (int i = 1 ; i < M ; i ++) {
        for (int j = 0 ; j < N ; j ++) {
            for (int k = 0 ; k < 10 ; k ++) {
                if (j >= (1 << i) * k)
                    dp[i][j] += dp[i - 1][j - k * (1 << i)];
            }
        }
    }
    for (int i = 0 ; i < M ; i ++) {
        for (int j = 1 ; j < N ; j ++)
            dp[i][j] += dp[i][j - 1];
    }
}
int cal (int n) {
    int bit[M] , len = 0 , sum = 0;
    while (n) {
        bit[len ++] = n % 10;
        n /= 10;
        sum += bit[len - 1] * (1 << (len - 1));
    }
    return sum;
}
int T , bit[20] , len;
int dfs(int i, int s, bool limit) {
    if (i == -1) return s <= T;
    if (!limit) return dp[i][T - s];
    int res = 0;
    int up = limit ? bit[i] : 9;
    for (int d = 0; d <= up && s + d * (1 << i) <= T; ++d)
        res += dfs(i-1, s + d * (1 << i), limit && d == up);
    return res;
}
int gao (int n , int m) {
    T = cal (m);
    len = 0;
    while (n) {
        bit[len ++] = n % 10;
        n /= 10;
    }
    return dfs (len - 1 , 0 , 1);
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    Init ();
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &m , &n);
        printf ("Case #%d: %d\n" , ++cas , gao (n , m));        
    }
    return 0;
}       

