#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
#include <ctime>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
using namespace std;
const int N = 105;
const int inf = 1000000007;
long long p[N] , vis[N];
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        for (int i = 0 ; i < N ; i ++) {
            vis[i] = 0;
            p[i] = -(1LL << 60);
        }
        int q;scanf ("%d" , &q);
        printf ("Case #%d:\n" , ++ cas);
        priority_queue <long long> que[N];
        while (q --) {
            char str[5];
            scanf ("%s" , str);
            if (str[0] == 'P') {
                int x , y , k;
                scanf ("%d %d %d" , &x , &y , &k);
                que[k].push (1LL * y - 1LL * x * k);
                // p[k] = max (p[k] , 1LL * y - 1LL * x * k);
            }
            else {
                int x;scanf ("%d" , &x);
                long long ans = -(1LL << 60) , idx;
                for (int i = 0 ; i < N ; i ++) {
                    if (!que[i].empty ()) {
                        long long p = que[i].top ();
                        long long ret = p + 1LL * i * x;
                        if (ret >= ans) {
                            ans = ret;
                            idx = i;
                        }
                    }
                }
                que[idx].pop ();
                printf ("%lld %lld\n" , ans , idx);
            }
        }
    }
    return 0;
}