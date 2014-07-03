#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const int MOD = 51123987;
const int N = 405;
int n , a[N][N] , dp[N][N];
pair <int , int> path[N][N];
int way[8][2] = {1 , 2 , 1 , -2 , -1 , 2 , -1 , -2 , 2 , 1 , 2 , -1 , -2 , 1 , -2 , -1};
void update (int x , int y , int u , int v , int d) {
    if (d > dp[x][y]) {
        dp[x][y] = d;
        path[x][y] = make_pair (u , v);
    }
    else if (d == dp[x][y] && a[u][v] < a[path[x][y].first][path[x][y].second]) {
        dp[x][y] = d;
        path[x][y] = make_pair (u , v);
    }
}
int dfs (int x , int y) {
    if (dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 1;
    path[x][y] = make_pair (0 , 0);
    for (int i = 0 ; i < 8 ; i ++) {
        int xx = x + way[i][0];
        int yy = y + way[i][1];
        if (xx >= 1 && yy >= 1 && xx <= n && yy <= n && a[xx][yy] > a[x][y]) {
            int t = dfs (xx , yy);
            // cout << x << " " << y << " " << xx << " " << yy << " " << t << endl;
            update (x , y , xx , yy , t + 1);
        }
    }
    // cout << x << " " << y << " " << dp[x][y] << endl;
    return dp[x][y];
}
void out (int x , int y , int d) {
    if (d == 0) return ;
    printf ("%d\n" , a[x][y]);
    out (path[x][y].first , path[x][y].second , d - 1);
}
int main () { 
    // #ifndef ONLINE_JUDGE
    //     freopen ("input.txt" , "r" , stdin);
    //     // freopen ("output.txt" , "w" , stdout);
    // #endif
    while (scanf ("%d" , &n) != EOF) {
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= n ; j ++) {
                scanf ("%d" , &a[i][j]);
            }
        }
        int ans = 0 , x = 0 , y = 0;
        memset (dp , -1 , sizeof(dp));
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= n ; j ++) {
                dp[i][j] = dfs (i , j);
                if (dp[i][j] > ans) {
                    ans = dp[i][j];
                    x = i ; y = j;
                }
                else if (dp[i][j] == ans && a[i][j] < a[x][y]) {
                    ans = dp[i][j];
                    x = i ; y = j;
                }
            }
        }
        printf ("%d\n" , ans);
        out (x , y , ans);
    }
    return 0;
}