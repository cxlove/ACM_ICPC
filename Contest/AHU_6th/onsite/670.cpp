#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int MOD = 1000000007;
const int N = 1025;
int n , m;
int c[N][N] , a[N] , b[N] , d[N];
int main () {
#ifndef ONLINE_JUDGE 
    // freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t;scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &n , &m);
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                scanf ("%d" , &c[i][j]);
            }
        }
        int ok = 1;
        for (int i = 1 ; i < n ; i ++) {
            // check a[i - 1] xor a[i]
            int tmp = c[i - 1][0] ^ c[i][0];
            for (int j = 1 ; j < m ; j ++) {
                if (tmp != (c[i - 1][j] ^ c[i][j]))
                    tmp = -1;
            }
            if (tmp == -1) {
                ok = 0;
            }
            d[i] = tmp;
        }
        if (!ok) puts ("I bet Tyrion made a mistake.");
        else {
            a[0] = 0;
            for (int i = 1 ; i < n ; i ++) {
                a[i] = d[i] ^ a[i - 1];
            }
            for (int i = 0 ; i < n ; i ++)
                printf ("%d%c" , a[i] , i == n - 1 ? '\n' : ' ');
            for (int i = 0 ; i < m ; i ++)
                printf ("%d%c" , c[0][i] , i == m - 1 ? '\n' : ' ');
        }
    }
    return 0;
}