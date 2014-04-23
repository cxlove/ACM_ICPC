#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int N = 50005;
const int inf = 2000000007;
int n , k , dp[N][505];
long long ans = 0;
vector <int> e[N];
void dfs (int u , int pre) {
    dp[u][0] = 1;
    for (int i = 0 ; i < e[u].size() ; i ++) {
        int v = e[u][i];
        if (v == pre) continue;
        dfs (v , u);
        for (int j = 0 ; j < k ; j ++) {
            ans += 1LL * dp[u][j] * dp[v][k - 1 - j];
        }
        for (int j = 1 ; j <= k ; j ++) {
            dp[u][j] += dp[v][j - 1];
        }
    }
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    cin >> n >> k;
    for (int i = 1 ; i < n ; i ++) {
        int u , v;
        cin >> u >> v;
        e[u].push_back (v);
        e[v].push_back (u);
    }
    dfs (1 , 0);
    cout << ans << endl;
    return 0;
}