#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
using namespace std;
typedef long long LL;
const int N = 100005;
double a , b , c[N] , d[N];
int n , m;
double sqr (double d) {
    return d * d;
}
double dist (double c , double d) {
    return sqrt (sqr (a - b) + sqr (c - d));
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%lf %lf" , &a , &b);
        scanf ("%d %d" , &n , &m);
        for (int i = 0 ; i < n ; i ++)
            scanf ("%lf" , &c[i]);
        for (int i = 0 ; i < m ; i ++)
            scanf ("%lf" , &d[i]);
        if (n == 1 && m == 1) {
            printf ("Case #%d: 0.00\n" , ++cas);
            continue;
        }
        double ans = dist (c[0] , d[0]);
        int l = 0 , r = 0;
        while (l + 1 < n || r + 1 < m) {
            double d1 = 1e9 , d2 = 1e9;
            if (l + 1 < n) d1 = dist (c[l + 1] , d[r]);
            if (r + 1 < m) d2 = dist (c[l] , d[r + 1]);
            if (d1 < d2) ans += d1 , l ++;
            else ans += d2 , r ++;
        }
        printf ("Case #%d: %.2f\n" , ++cas , ans);
    }
    return 0;
}       

