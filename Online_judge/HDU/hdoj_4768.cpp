#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define mp(a,b) make_pair(a,b)
#define mpp(a,b,c) make_pair(make_pair(a,b),c)
#define Key_value ch[ch[root][1]][0] 
#define pii pair<pair<int,int>,int>
using namespace std;
typedef long long LL;
const int N = 20005;
int n , a[N] , c[N] , b[N];
int cal (int a , int b , int c , LL r) {
    if (r == 0) return 0;
    r = min (0LL + b , r);
    if (r < a) return 0;
    return (r - a + 1 + c - 1) / c;
}
LL gao (LL l , LL r) {
    LL ret = 0;
    for (int i = 1 ; i <= n ; i ++) {
        ret += cal (a[i] , b[i] , c[i] , r) - cal (a[i] , b[i] , c[i] , l - 1);
    }
    return ret;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d" , &n) != EOF) {
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d %d %d" , &a[i] , &b[i] , &c[i]);
        }
        LL low = 1 , high = 1LL << 32 , mid , ans = -1;
        while (low <= high) {
            mid = (low + high) >> 1;
            LL t = gao (low , mid);
            if (t & 1) {
                if (low == high) {
                    ans = mid;
                    break;
                }
                high = mid;
            }
            else low = mid + 1;
        }
        if (ans == -1) puts ("DC Qiang is unhappy.");
        else printf ("%I64d %I64d\n" , ans , gao (ans , ans));
    }
    return 0;
}       