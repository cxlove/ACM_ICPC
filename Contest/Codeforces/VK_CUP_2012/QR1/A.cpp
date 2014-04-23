#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
const int N = 200005;
const int inf = N * 10;
int n , k , a[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++) {
        cin >> a[i];
    }
    sort (a , a + n);
    reverse (a , a + n);
    int ans = 0;
    for (int i = 0 ; i < n ; i ++) {
        if (a[i] && a[i] >= a[k - 1])
            ans ++;
    }
    cout << ans << endl;
    return 0;
}