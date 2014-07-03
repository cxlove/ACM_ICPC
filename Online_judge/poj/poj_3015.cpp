#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define pii pair<int,LL>
using namespace std;
typedef long long LL;
const int N = 50005;
int n , m , a[N];
long double f[N];
long double c (int n , int m) {
    long double ans = 1.0;
    for (int i = 1 ; i <= n - m ; i ++)
        ans = ans * (i + m) / i;
    // cout << ans << endl;
    return ans;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d %d" , &n , &m) != EOF) {
        if (!n && !m) break;
        for (int i = 0 ; i < n ; i ++)
            scanf ("%d" , &a[i]);
        sort (a , a + n);
        memset (f , 0 , sizeof(f));
        f[0] = 1.0 * m / n;
        for (int i = 1 ; i <= n - m ; i ++) {
            f[i] = f[i - 1] / (n - i) * (n - m - i + 1);
        }
        long double ans = 0;
        for (int i = 0 ; i < n ; i ++) {
            ans += -a[i] * f[i] + a[i] * f[n - i - 1];
        }
        printf ("%.3f\n" , (double)ans);
    }
    return 0;
}       