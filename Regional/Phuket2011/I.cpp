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
const int N = 1000000;
int n , ans , up[N] , down[N];
vector <pair <int , int> > e[N];
void dfs (int u , int pre) {
    up[u] = down[u] = 0;
    for (int i = 0 ; i < e[u].size() ; i ++) {
        int v = e[u][i].first , w = e[u][i].second;
        if (v == pre) continue;
        dfs (v , u);
        if (w) {
            up[u] += max (1 , up[v]);
            ans += down[v];
        }
        else {
            down[u] += max (1 , down[v]);
            ans += up[v];
        }
    }
    int ret = min (up[u] , down[u]);
    ans += ret;
    up[u] -= ret;down[u] -= ret;
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
        for (int i = 0 ; i < n ; i ++)
            e[i].clear ();
        for (int i = 1 ; i < n ; i ++) {
            int u , v;
            scanf ("%d %d" , &u , &v);
            e[u].push_back (make_pair (v , 1));
            e[v].push_back (make_pair (u , 0));
        }
        ans = 0;
        dfs (0 , -1);
        printf ("Case %d: %d\n" , ++ cas , ans + up[0] + down[0]);
    }
    return 0;
}