#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#define error {puts("0");return 0;}
#define mp(a,b) make_pair(a , b)
#define mpp(a,b,c) mp(mp(a,b),c)
#define HASH 1000000007
using namespace std;
typedef long long LL;
const int N = 100005;
int flag[N] , prime[N] , cnt = 0 , miu[N];
void Init () {
    miu[1] = 1;
    for (int i = 2 ; i < N ; i ++) {
        if (!flag[i]) {
            prime[cnt ++] = i;
            miu[i] = -1;
        }
        for (int j = 0 ; j < cnt && i * prime[j] < N ; j ++) {
            flag[i * prime[j]] = 1;
            if (i % prime[j] == 0) {
                miu[i * prime[j]] = 0;
                // break;
            }  
            else miu[i * prime[j]] = - miu[i];  
        }
    }
}
int main () {  
    #ifndef ONLINE_JUDGE 
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t , cas = 0;
    Init ();
    scanf ("%d" , &t);
    while (t --) {
        int a , b , c , d , k;
        LL ans = 0 , ret = 0;
        scanf ("%d %d %d %d %d" , &a , &b , &c , &d , &k);
        if (k == 0) {
            printf ("Case %d: 0\n" , ++ cas);
            continue;
        }
        if (b > d) swap (b , d);
        for (int i = k ; i <= b ; i += k) {
            #define f(r) 1LL * (b / r) * (d / r)
            #define g(r) 1LL * (b / r) * (b / r)
            ans += f (i) * miu[i / k];
            ret += g (i) * miu[i / k];
        }
        printf ("Case %d: %I64d\n" , ++cas , ans - ret / 2);
    }
    return 0;
}