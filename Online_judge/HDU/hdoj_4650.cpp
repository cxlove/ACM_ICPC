#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson step << 1
#define rson step << 1 | 1
using namespace std;
typedef long long LL;
const int N = 105;
const int inf = 1000000009;
int n , m , vis[N][N];
double ans[N][N];
struct Matrix {
    int d[N][N];
    Matrix operator * (const Matrix &m) const {
        Matrix ans ;
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                ans.d[i][j] = inf;
                for (int k = 0 ; k < n ; k ++) {
                    ans.d[i][j] = min (d[i][k] + m.d[k][j] , ans.d[i][j]);
                }
            }
        }
        return ans;
    }
}a , b;
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%d %d" , &n , &m) != EOF) {
        memset (vis , 0 , sizeof(vis));
        for (int i = 0 ; i < n ; i ++)
            for (int j = 0 ; j < n ; j ++) 
                a.d[i][j] = inf , ans[i][j] = 1e9;
        for (int i = 0 ; i < m ; i ++) {
            int u , v , w;
            scanf ("%d %d %d" , &u , &v , &w);
            u --;v --;
            vis[u][v] = 1;
            a.d[u][v] = w;
        }
        for (int k = 0 ; k < n ; k ++) {
            for (int i = 0 ; i < n ; i ++) {
                for (int j = 0 ; j < n ; j ++) {
                    vis[i][j] |= vis[i][k] & vis[k][j];
                }
            }
        }
        b = a;
        for (int path = 1 ; path <= n ; path ++) {
            for (int i = 0 ; i < n ; i ++) {
                for (int j = 0 ; j < n ; j ++) {
                    if (b.d[i][j] < inf) {
                        ans[i][j] = min (ans[i][j] , b.d[i][j] * 1.0 / path);
                    }
                }
            }
            b = b * a;
        }
        for (int k = 0 ; k < n ; k ++) {
            for (int i = 0 ; i < n ; i ++) {
                for (int j = 0 ; j < n ; j ++) {
                    if (vis[i][k] && vis[k][j] && vis[k][k])
                        ans[i][j] = min (ans[i][j] , ans[k][k]);
                }
            }
        }
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                if (vis[i][j] == 0) printf("NO");
                else printf("%.3f" , ans[i][j]);
                printf("%c" , j == n - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}