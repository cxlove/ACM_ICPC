#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long LL;
const int N = 100005;
int n , q;
LL a[N] , b[N] , c[N];
void add (LL *r , int x , LL w) {
    for (int i = x ; i <= n ; i += lowbit (i))
        r[i] += w;
}
LL ask (LL *r , int x) {
    LL ret = 0;
    for (int i = x ; i > 0 ; i -= lowbit (i))
        ret += r[i];
    return ret;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%d %d" , &n , &q) != EOF) {
        a[0] = 0;
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%lld" , &a[i]);
            a[i] += a[i - 1];
            b[i] = c[i] = 0LL;
        }
        while (q --) {
            char str[5];
            scanf ("%s" , str);
            if (str[0] == 'C') {
                int l , r , w;
                scanf ("%d %d %d" , &l , &r , &w);
                add (b , l , w); add (b , r + 1 , -w);
                add (c , l , l * w); add (c , r + 1 , -w * (r + 1));
            }
            else {
                int l , r;
                scanf ("%d %d" , &l , &r);
                printf ("%lld\n" , a[r] - a[l - 1] + (r + 1) * ask (b , r) - l * ask (b , l - 1) - ask (c , r) + ask (c , l - 1));
            }
        }
    }    
    return 0;
}       

