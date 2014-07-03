#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a , b)
#define lowbit(x) (x & (-x))
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const int N = 100005;
double powmod (double a , int b) {
    double ret = 1.0;
    while (b) {
        if (b & 1) ret = ret * a * 1.0;
        a = a * a * 1.0;
        b >>= 1;
    }
    return ret;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t;
    while (scanf ("%d" , &t) != EOF) {
        while (t --) {
            int k , n , m;
            scanf ("%d %d %d" , &k , &m , &n);
            if (k == 0) {
                printf ("%.9f\n" , (powmod (m , n) - 1.0) / (m - 1.0));
            }
            else {
                double ans = 0.0 , d = 1.0;
                for (int i = 1 ; i < n ; i ++) {
                    d = d * m * 1.0 / (m - i);
                    ans += d;
                }
                printf ("%.9f\n" , ans + 1.0);
            }
        }
    }
    return 0;
}