#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 1000005;
int n;
long long a[N] , b[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int cas = 0;
    while (scanf ("%d" , &n) != EOF && n) {
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%lld" , &a[i]);
        }
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%lld" , &b[i]);
            a[i] -= b[i];
            b[i] = a[i];
        }
        long long worst = a[1];
        for (int i = 2 ; i <= n ; i ++) {
            a[i] = a[i - 1] + a[i];
            if (a[i] < worst) worst = a[i];
        }
        printf ("Case %d:" , ++ cas);
        for (int i = 1 ; i <= n ; i ++) {
            if (worst >= 0) {
                printf (" %d" , i);
            }
            worst -= b[i];
        }
        puts ("");
    }
    return 0;
}