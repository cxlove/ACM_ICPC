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
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 1000005;
int prime[N] , flag[N] , cnt;
int ans[N];
LL a , b , l , r;
void init () {
    for (int i = 2 ; i < N ; i ++) {
        if (!flag[i]) {
            prime[cnt ++] = i;
        }
        for (int j = 0 ; j < cnt && i * prime[j] < N ; j ++) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
inline bool isprime (LL n) {
    if (n < 2) return false;
    for (LL i = 2 ; i * i <= n ; i ++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
void extend_gcd (LL a , LL b , LL &x , LL &y) {
    if (!b) x = 1 , y = 0;
    else {
        extend_gcd (b , a % b , y , x);
        y -= x * (a / b);
    }
}
void bruteforce () {
    int ret = 0;
    for (long long x = l ; x <= r ; x ++) {
        if (isprime (x * a + b)) {
            ret ++;
        }
    }
    cout << "brute force : " << ret << endl;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif
    init ();
    int cas = 0;
    while (scanf ("%lld" , &a) != EOF && a) {
        scanf ("%lld %lld %lld" , &b , &l , &r);
        printf ("Case %d: " , ++ cas);
        // bruteforce ();
        if (__gcd (a , b) > 1) {
            if (l == 0 && isprime (b)) {
                puts ("1");
            }
            else puts ("0");
            continue;
        }
        memset (ans , 0x11 , sizeof (ans));
        if (l == 0) {
            ans[0] = isprime (b);
        }
        if (l <= 1) {
            ans[1 - l] = isprime (a + b);
        } 
        int tot = r - l + 1;
        for (int i = 0 ; i < cnt && 1LL * prime[i] * prime[i] <= r * a + b ; i ++) {
            LL p = prime[i];
            // px + (-a)y = b + l * n
            // Ax + By = C
            LL A = p , B = -a , C = b + l * a;
            LL gcd = __gcd (A , B);
            if (C % gcd) continue;
            LL x , y;
            extend_gcd (A , B , x , y);
            x = x * (C / gcd);
            y = y * (C / gcd);
            LL t1 = B / gcd , t2 = (-A) / gcd;
            t2 = abs (t2);
            y = (y % t2 + t2) % t2;
            // x = (C - B * y) / A;
            // if (A * x + B * y != C) {
            //     puts ("error");
            //     break;
            // } 
            while (y < tot && -B * y + C <= p) {
                y += t2;
            }
            // cout << "here " << p << endl;
            while (y < tot) {
                // cout << -B * y + C << " ";
                ans[y] = false;
                y += t2;
            }
            // cout << endl;
        }
        int ret = 0;
        for (int i = 0 ; i < tot ; i ++) {
            if (ans[i]) {
                // if (!isprime ((i + l) * a + b))
                //     cout << "error: " << i << endl;
                ret ++;
            }
        }
        printf ("%d\n" , ret);
    }
    return 0;
}