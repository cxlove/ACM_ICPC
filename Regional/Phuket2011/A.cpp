#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
using namespace std;
const int N = 100005;
const long long inf = (long long)2e18;
int n , f[N] , c[N];
long long flow[1 << 20] , cost[1 << 20];
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    while (scanf ("%d" , &n) != EOF) {
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d %d" , f + i , c + i);
        }
        int q;
        scanf ("%d" , &q);
        int cas = 0;
        for (int i = 0 ; i < 1 << n ; i ++) {
            flow[i] = 0;cost[i] = 0;
            for (int j = 0 ; j < n ; j ++) {
                if ((1 << j) & i) {
                    flow[i] += f[j];
                    cost[i] += c[j];
                }
            }
        }
        while (q --) {
            int F , T;
            scanf ("%d %d" , &F , &T);
            long long ans = inf;
            for (int i = 0 ; i < 1 << n ; i ++) {
                if (flow[i] * 1LL * T >= F) {
                    ans = min (ans , cost[i]);
                }
            }
            printf ("Case %d: " , ++ cas);
            if (ans < inf) printf ("%lld\n" , ans);
            else puts ("IMPOSSIBLE");
        }
    }
    return 0;
}
