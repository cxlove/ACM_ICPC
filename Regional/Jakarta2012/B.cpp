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
typedef long long LL;
const int N = 100005;
int mx[N] , sum[N] , n;
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        int ans = 0;
        for (int i = 1 ; i <= n ; i ++) {
            sum[i] = mx[i] = 0;
        }
        for (int i = 1 ; i < n ; i ++) {
            int u , v , w;
            scanf ("%d %d %d" , &u , &v , &w);
            mx[u] = max (mx[u] , w);
            mx[v] = max (mx[v] , w);
            sum[u] += w;
            sum[v] += w;
            ans += w;
        }
        for (int i = 1 ; i <= n ; i ++) {
            if (mx[i] * 2 <= sum[i]) ans -= sum[i] / 2;
            else ans -= sum[i] - mx[i];
        }
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}