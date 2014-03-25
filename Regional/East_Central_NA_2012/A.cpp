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
const int N = 15;
struct Node {
    int w , h , l;
    void init () {
        scanf ("%d %d %d" , &w , &h , &l);
        if (w > h) swap (w , h);
        if (w > l) swap (w , l);
        if (h > l) swap (h , l);
    }
}a[N];
int n , b[N] , dp[N] , ret;
vector <pair <int , int> > c;
void dfs (int u) {
    if (u == n) {
        c.clear ();
        for (int i = 0 ; i < n ; i ++) {
            if (b[i] == 0) c.push_back (make_pair (a[i].h , a[i].l));
            if (b[i] == 1) c.push_back (make_pair (a[i].w , a[i].l));
            if (b[i] == 2) c.push_back (make_pair (a[i].w , a[i].h));
        }
        sort (c.begin () , c.end ());
        int ans = 1;
        for (int i = 0 ; i < n ; i ++) {
            dp[i] = 1;
            for (int j = 0 ; j < i ; j ++) {
                if (c[i].second >= c[j].second)
                    dp[i] = max (dp[i] , dp[j] + 1);
            }
            ans = max (ans , dp[i]);
        }
        ret = max (ret , ans);
        return ;
    }
    for (int i = 0 ; i < 3 ; i ++) {
        b[u] = i;
        dfs (u + 1);
    }
}
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif 
    int cas = 0;
    while (scanf ("%d" , &n) != EOF && n) {
        for (int i = 0 ; i < n ; i ++)
            a[i].init ();
        ret = 0;
        dfs (0);
        printf ("Case %d: %d\n" , ++cas , ret);
    }
    return 0;
}