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
const int N = 500005;
int flag[N] , prime[N] , cnt = 0 , miu[N] , sum[20][N];
int minumfac[N] , cntfac[N];
void Init () {
    miu[1] = 1;
    for (int i = 2 ; i < N ; i ++) {
        if (!flag[i]) {
            prime[cnt ++] = i;
            miu[i] = -1;
        }
        for (int j = 0 ; j < cnt && i * prime[j] < N ; j ++) {
            flag[i * prime[j]] = 1;
            minumfac[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) {
                miu[i * prime[j]] = 0;
                break;
            }  
            else miu[i * prime[j]] = - miu[i];  
        }
    }
    cntfac[1] = 0;
    for (int i = 2 ; i < N ; i ++) {
        if (!flag[i]) cntfac[i] = 1;
        else cntfac[i] = cntfac[i / minumfac[i]] + 1;
    }
    for (int i = 1 ; i < N ; i ++) {
        for (int j = i ; j < N ; j += i)
            sum[cntfac[i]][j] += miu[j / i];
    }
    for (int i = 1 ; i < N ; i ++) {
        for (int j = 1 ; j < 20 ; j ++)
            sum[j][i] += sum[j - 1][i];
    }
    for (int i = 1 ; i < N ; i ++) {
        for (int j = 0 ; j < 20 ; j ++)
            sum[j][i] += sum[j][i - 1];
    }
}
int main () {  
    #ifndef ONLINE_JUDGE 
        freopen ("input.txt" , "r" , stdin);
    #endif
    Init ();
    int t;
    scanf ("%d" , &t);
    while (t --) {
        int n , m , p;
        scanf ("%d %d %d" , &n , &m , &p);
        p = min (p , 19);
        if (n > m) swap (n , m);
        LL ans = 0;
        for (int i = 1 ; i <= n ; ) {
            #define f(x) 1LL * (n / x) * (m / x)
            int d = min ((n / (n / i)) , (m / (m / i)));
            ans += f (i) * (sum[p][d] - sum[p][i - 1]);
            i = d + 1;
        }
        printf ("%I64d\n" , ans);
    }
    return 0;
}