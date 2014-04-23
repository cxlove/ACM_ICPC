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
        cin >> a[i];
    }
    vector <int> fac;
    for (int i = 1 ; i * i <= n ; i ++) {
        if (n % i == 0) {
            fac.push_back (i);
            if (i * i != n)
                fac.push_back (n / i);
        }
    }
    int ans = -((int)1e8);
    for (int i = 0 ; i < fac.size() ; i ++) {
        if (n / fac[i] < 3) continue;
        for (int st = 0 ; st < fac[i] ; st ++) {
            int ret = 0;
            for (int j = st ; j < n ; j += fac[i]) {
                ret += a[j];
            }
            ans = max (ans , ret);
        }
    }
    cout << ans << endl;
    return 0;
}