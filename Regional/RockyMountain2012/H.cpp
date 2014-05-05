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
using namespace std;
const int N = 505;
int n , m , pre[N] , vis[N];
int find (int x) {
    return pre[x] = (pre[x] == x ? x : find (pre[x]));
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int cas = 0;
    while (scanf ("%d %d" , &n , &m) != EOF && n + m) {
        for (int i = 1 ; i <= n ; i ++)
            pre[i] = i;
        memset (vis , 0 , sizeof (vis));
        int tree = n;
        while (m --) {
            int u , v;
            scanf ("%d %d" , &u , &v);
            int ra = find (u) , rb = find (v);
            if (ra == rb) {
                if (vis[ra] == 0) tree --;
                vis[ra] = 1;
            }
            else {
                if (vis[ra] == 0 || vis[rb] == 0)
                    tree --;
                if (vis[ra] || vis[rb]) vis[ra] = vis[rb] = 1;
                pre[ra] = rb;
            }
        }
        printf ("Case %d: " , ++ cas);
        if (tree <= 0) puts ("No trees.");
        else if (tree == 1) puts ("There is one tree.");
        else printf ("A forest of %d trees.\n" , tree);
    }
    return 0;
}