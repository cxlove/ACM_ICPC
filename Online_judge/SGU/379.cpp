#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <queue>
#define error {puts("0");return 0;}
#define pb push_back
#define mp(a,b) make_pair(a , b)
#define mpp(a,b,c) mp(mp(a,b),c)
#define HASH 1000000007
using namespace std;
const int N = 105;
typedef long long LL;
LL n , c , p , t;
LL a[N] , b[N];
bool check (LL cnt , LL tot) {
    LL m = 0;
    for (int i = 1 ; i <= n ; i ++) {
        if (m + a[i] >= cnt) {
            b[i] = cnt - m;
            m = i;
            break;
        }
        else b[i] = a[i] , m += a[i];
    }
    // cout << m << endl;
    LL ret = 0;
    while (true) {
        while (m > 0 && b[m] == 0) m --;
        if (m <= 0) break;
        if (b[m] > c) {
            ret += b[m] / c * 2LL * m;
            b[m] %= c;
        }
        if (b[m] == 0) m --;
        LL tmp = m;
        LL r = 0;
        while (r < c && tmp > 0) {
            if (r + b[tmp] >= c) {
                b[tmp] -= c - r;
                r = c;
                break;
            }
            r += b[tmp];
            tmp --;
        }
        ret += 2LL * m;
        m = tmp;
    }
    // cout << cnt << " " << ret << endl;
    return ret <= tot;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r"  , stdin);
    #endif
    LL low = 0 , high = 0 , mid , ans;
    cin >> n >> c >> p >> t;
    for (int i = 1 ; i <= n ; i ++) {
        cin >> a[i];
        high += a[i];
    }
    while (low <= high) {
        mid = (low + high) >> 1;
        if (check (mid , t / p)) ans = mid , low = mid + 1;
        else high = mid - 1;
    }
    cout << ans << endl;
    return 0;
}
