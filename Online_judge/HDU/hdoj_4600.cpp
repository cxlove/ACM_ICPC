#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson step << 1
#define rson step << 1 | 1
using namespace std;
typedef long long LL;
const int N = 105;
int w , h , n , d , y;
int q , p , ni , mi;
int c[10];
LL get[2005];
LL gao () {
    LL ret = y;
    for (int t = 0 ; t <= d ; t += ni) {
        int up = ret / q;
        if (t + ni > d) continue;
        if (up == 0) continue;
        for (int i = 9 ; i >= 1 ; i --) {
            int r = min (up , c[i]);
            if (!r || i * p <= q) continue;
            ret += (LL)i * p * r - (LL)r * q;;
            up -= r;
        }
    }
    return ret;
}
LL gao (int mi) {
    LL ret = y;
    memset (get , 0 , sizeof(get));
    for (int t = 0 ; t <= d ;t ++) {
        ret += get[t];
        if (t + mi <= d) get[t + mi] += get[t];
        LL up = ret / q;
        LL hav = 0;
        if (up == 0 || t + ni > d) continue;
        for (int i = 9 ; i >= 1 ; i --) {
            LL r = min (up , (LL)c[i]);
            int cnt = 0;
            if (t + ni <= d) {
                cnt = 1 + (d - t - ni) / mi;
            }
            LL g = 1LL * cnt * i * p - q;
            if (!r || g <= 0) continue;
            hav += (LL)p * i * r;
            ret -= (LL)q * r;
            up -= r;
            c[i] -= r;
        }
        int tmp = t + ni;
        get[tmp] += hav;
       // while (tmp + mi <= d) get[tmp + mi] += hav , tmp += mi;
    }
    return ret;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        freopen ("output.txt" , "w" , stdout);
    #endif
    int t;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d %d %d %d" , &w , &h , &n , &d , &y);
        LL ans = y;
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d %d %d %d" , &q , &p , &ni , &mi);
            memset (c , 0 , sizeof(c));
            c[9] = (w / 3) * (h / 3);
            c[9 - (3 - w % 3) * (3 - h % 3)] ++;
            c[3 * (w % 3)] += (h - 3) / 3;
            c[3 * (h % 3)] += (w - 3) / 3;
            c[(w % 3) * (h % 3)] += 2;
            if (mi) ans = max (ans , gao (mi));
            else ans = max (ans , gao());            
        }
        printf("%I64d\n", ans);;
    }
    return 0;
}