#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
const int N = 100005;
vector <int> e[N];
int n , m , vis[N];
void dfs (int u) {
    if (vis[u]) return ;
    vis[u] = 1;
    for (int i = 0 ; i < e[u].size() ; i ++)
        dfs (e[u][i]);
    cout << " " << u ;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    cin >> n >> m;
    for (int i = 0 ; i < m ; i ++) {
        int u , v;
        cin >> u >> v;
        e[u].push_back (v);
    }
    for (int i = 1 ; i <= n ; i ++)
        if (!vis[i])
            dfs (i);
    return 0;
}