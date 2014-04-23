#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
const int N = 200005;
const int inf = N * 10;
int n , a[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    cin >> n;
    for (int i = 0 ; i < n ; i ++) {
        int k;cin >> k;
        a[k] ++;
    }
    int ans = a[4];
    int t = min (a[1] , a[3]);
    ans += t;
    a[1] -= t;a[3] -= t;
    ans += a[2] / 2;
    a[2] %= 2;
    if (a[3]) {
        ans += a[3];
        a[1] = max (0 , a[1] - a[3]);
    }
    if (a[2]) {
        ans ++;
        a[1] = max (0 , a[1] - 2);
    }
    ans += (a[1] + 3) / 4;
    cout << ans << endl;
    return 0;
}