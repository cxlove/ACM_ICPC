#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
const int N = 20005;
int n , m , k;
int a[N][15] , cnt[N] , ans[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    cin >> n >> m >> k;
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m ; j ++)
            cin >> a[i][j];
    }
    while (k --) {
        int x , y;
        cin >> x >> y;
        cnt[y] ++;ans[x] --;
    }
    for (int i = 1 ; i <= n ; i ++) {
        for (int j = 1 ; j <= m ; j ++) {
            if (a[i][j])
                ans[i] += cnt[j];
        }
    }
    for (int i = 1 ; i <= n ; i ++)
        cout << ans[i] << " " ;
    return 0;
}