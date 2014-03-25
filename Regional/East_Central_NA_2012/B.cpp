#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cctype>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef unsigned long long LL;
const int N = 1005;
int n , x[N] , y[N] , sx[N] , sy[N];
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif 
    int cas = 0;
    while (scanf ("%d" , &n) != EOF && n) {
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d %d" , &x[i] , &y[i]);
        }
        sort (x + 1 , x + 1 + n);
        sort (y + 1 , y + 1 + n);
        for (int i = 1 ; i <= n ; i ++) {
            sx[i] = sx[i - 1] + x[i];
            sy[i] = sy[i - 1] + y[i];
        }
        int tx = 1 << 30 , ty = 1 << 30;
        int ax , ay;
        for (int i = 1 ; i <= n ; i ++) {
            int t = i * x[i] - sx[i] + (sx[n] - sx[i]) - (n - i) * x[i];
            if (t < tx) tx = t , ax = x[i];
        }
        for (int i = 1 ; i <= n ; i ++) {
            int t = i * y[i] - sy[i] + (sy[n] - sy[i]) - (n - i) * y[i];
            if (t < ty) ty = t , ay = y[i];
        }
        printf ("Case %d: (%d,%d) %d\n" , ++ cas , ax , ay , tx + ty);
    }
    return 0;
}