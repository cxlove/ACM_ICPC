#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define pii pair<int,LL>
using namespace std;
typedef long long LL;
const int N = 1005;
int n , p , m;
int a[N][N] , b[N][N] , c[N][N] , sum[N] , tot[N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d %d %d" , &n , &p , &m) != EOF) {
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < p ; j ++)
                scanf ("%d" , &a[i][j]);
        }
        for (int i = 0 ; i < p ; i ++) {
            sum[i] = 0;
            for (int j = 0 ; j < m ; j ++) {
                scanf ("%d" , &b[i][j]);
                sum[i] += b[i][j];
            }
        }
        for (int i = 0 ; i < n ; i ++) {
            tot[i] = 0;
            for (int j = 0 ; j < m ; j ++) {
                scanf ("%d" , &c[i][j]);
                tot[i] += c[i][j];
            }
        } 
        int f = 0;
        for (int i = 0 ; i < n ; i ++) {
            int ret = 0;
            for (int j = 0 ; j < p ; j ++)
                ret += a[i][j] * sum[j];
            if (ret != tot[i]) {
                for (int j = 0 ; j < m ; j ++) {
                    int tmp = 0;
                    for (int k = 0 ; k < p ; k ++) {
                        tmp += a[i][k] * b[k][j];
                    }
                    if (tmp != c[i][j]) {
                        printf ("No\n%d %d\n%d\n" , i + 1 , j + 1 , tmp);
                        f = 1;
                        break;
                    }
                }
            }
        }
        if (!f) puts ("Yes");
    }
    return 0;
}       

