#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 1005;
double dp[2][N << 1][N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t , id;
    scanf ("%d" , &t);
    while (t --) {
    	int n;
    	double l , r , non;
    	scanf ("%d %d %lf %lf" , &id , &n , &l , &r);
    	non = 1.0 - l - r;
    	dp[0][N][0] = 1.0;
    	for (int i = 0 ; i < n ; i ++) {
    		int pre = i & 1 , now = pre ^ 1;
     		for (int j = -(i + 1) ; j <= (i + 1) ; j ++)
    			for (int k = 0 ; k <= i + 1 ; k ++)
    				dp[now][j + N][k] = 0.0;
    		for (int j = -i ; j <= i ; j ++) {
    			for (int k = 0 ; k <= i ; k ++) {
    				// left
    				dp[now][j + N + 1][max (k , j + 1)] += dp[pre][j + N][k] * r;
    				// right
    				dp[now][j + N - 1][k] += dp[pre][j + N][k] * l;
    				// static
    				dp[now][j + N][k] += dp[pre][j + N][k] * non;
    				// cout << dp[pre][j + N][k] << endl;
    			}
    		}
    	}
    	double ans = 0.0;
    	for (int i = -n ; i <= n ; i ++) {
    		for (int j = 0 ; j <= n ; j ++) {
    			ans += dp[n & 1][i + N][j] * j;
    		}
    	}
    	printf ("%d %.4f\n" , id , ans);
    }
    return 0;
}