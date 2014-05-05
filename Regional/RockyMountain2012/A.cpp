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
const int N = 55;
int n , c[N] , p[N];
int cost[N] , cnt[N];
double dp[N][N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    long long l , p , v , cas = 0;
    while (cin >> l >> p >> v) {
        if (!l && !p && !v) break;
        long long ans = v / p * 1LL * l + min (l , v % p);
        cout << "Case " << ++ cas << ": " << ans << endl;
    }
    return 0;
}