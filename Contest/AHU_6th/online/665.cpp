#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2015;
const int MOD = 23333;
int n , dp[N][N] , sum[N][N] , ans[N];
inline int add (int a , int b) {
    a += b;if (a >= MOD) a -= MOD;
    return a;
}
int main () {
    dp[0][0] = sum[0][0] = 1;
    for (int i = 1 ; i < N ; i ++) {
        for (int j = 0 ; j < i ; j ++) {
            int k = max (0 , 2 * j - i);
            dp[i][j] = sum[j][k];
            sum[i][j] = add ((j == 0 ? 0 : sum[i][j - 1]) , dp[i][j]); 
        }
        ans[i] = ans[i - 1];
        for (int j = 0 ; j < i ; j ++)
            ans[i] = add (ans[i] , dp[i][j]);
    }
    int t;scanf ("%d" , &t);
    while (t --) {
        int n;scanf ("%d" , &n);
        printf ("%d\n" , ans[n]);
    }
    return 0;
}
