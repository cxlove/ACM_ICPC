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
#include <map>
#include <stack>
#include <cmath>
using namespace std;
const int N = 20005;
const int inf = 1000000007;
long long ans ;
int  n , size[N];
vector <int> e[N];
void dfs (int u , int pre) {
    size[u] = 1;
    vector <int> a;
    for (int i = 0 ; i < e[u].size() ; i ++) {
        int v = e[u][i];
        if (v == pre) continue;
        dfs (v , u);
        a.push_back (size[v]);
        size[u] += size[v];
    }
    if (n - size[u] > 0) {
        a.push_back (n - size[u]);
    }
    long long ret = 0;
    for (int i = 0 ; i < a.size() ; i ++) {
        ret += 1LL * a[i] * (n - 1 - a[i]);
    }
    ans = max (ans , ret / 2);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 1 ; i <= n ; i ++)
            e[i].clear ();
        for (int i = 1 ; i < n ; i ++) {
            int u , v;
            scanf ("%d %d" , &u , &v);
            e[u].push_back (v);
            e[v].push_back (u);
        }
        ans = 0;
        dfs (1 , 0);
        printf ("Case #%d: %lld\n" , ++ cas , ans);
    }
    return 0;
}
