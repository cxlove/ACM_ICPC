#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
typedef unsigned int ull;
const int N = 302;
const ull HASH = 1000000007;
ull fac[N] = {1};
ull l[N][N] , r[N][N] , u[N][N] , d[N][N];
int up[2][N][N] , lef[N][N];
int n , m , a[N][N];
int main () {
    #ifndef ONLINE_JUDGE
         freopen("input.txt","r",stdin);
    #endif
    int t ;
    scanf ("%d" , &t);
    for (int i = 1 ; i < N ; i ++) {
        fac[i] = fac[i - 1] * HASH;
    }
    while (t --) {
        scanf ("%d %d" , &n , &m);
        for (int i = 1 ; i <= n ; i ++) {
            for (int j = 1 ; j <= m ; j ++) {
                scanf ("%d", &a[i][j]);
            }
        }
        for (int i = 1 ; i <= n ; i ++) {
            l[i][0] = 0; r[i][m + 1] = 0;
            for (int j = 1 ; j <= m ; j ++) {
                l[i][j] = l[i][j - 1] * HASH + a[i][j];
            }
            for (int j = m ; j >= 1 ; j --) {
                r[i][j] = r[i][j + 1] * HASH + a[i][j];
            }
        }
        for (int j = 1 ; j <= m ; j ++) {
            d[0][j] = 0 ; u[n + 1][j] = 0;
            for (int i = 1 ; i <= n ; i ++) {
                d[i][j] = d[i - 1][j] * HASH + a[i][j];
            }
            for (int i = n ; i >= 1 ; i --) {
                u[i][j] = u[i + 1][j] * HASH + a[i][j];
            }
        }
        memset (up , 0 , sizeof(up));
        int ans = 1;
        for (int i = 1 ; i <= n ; i ++) {
            memset (lef, 0 , sizeof(lef));
            for (int j = 1 ; j <= m ; j ++) {
                for (int k  = j ; k <= m ; k ++) {
                    ull l_r = l[i][k] - l[i][j - 1] * fac[k - j + 1];
                    ull r_l = r[i][j] - r[i][k + 1] * fac[k - j + 1];
                    if (l_r == r_l) {
                        up[i & 1][j][k] = up[(i + 1) & 1][j][k] + 1;
                    }
                    else up[i & 1][j][k] = 0;
                    //cout << i << " " << j << " " << k << " " << up[i][j][k] << endl;
                }
             }
             for (int j = 1 ; j <= m ; j ++) {
                 for (int k = 1 ; k <= i ; k ++) {
                     // i - > j  j - > k  k - > i
                     ull u_d = d[i][j] - d[k - 1][j] * fac[i - k + 1];
                    ull d_u = u[k][j] - u[i + 1][j] * fac[i - k + 1];
                    if (u_d == d_u) {
                        lef[j][k] = lef[j - 1][k] + 1;
                    }
                    else lef[j][k] = 0;
                 }
             }
             for (int k = 1 ; k < i ; k ++) {
                 int l = i - k + 1;
                 for (int j = 1 ; j + l - 1 <= m ; j ++) {
                     if (up[i & 1][j][j + l - 1] >= l) {
                         if (lef[j + l - 1][k] >= l) 
                             ans = max (ans , l);
                     }
                  }
             }
        }
        printf ("%d\n" , ans);
    }
    return 0;
}    