#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#include <cmath>
#define mp(a , b) make_pair (a , b)
#define pb push_back
#pragma comment(linker,"/STACK:100000000,100000000")
using namespace std;
typedef long long LL;
const int N = 1000005;
const int MOD = 1000000007;
int pre[N] , suf[N] , t , n , a[N] , b[N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 1 ; i <= n ; i ++)
            scanf ("%d" , &a[i]);
        sort (a + 1 , a + 1 + n);
        pre[0] = 1;suf[n + 1] = 1;
        for (int i = 1 , l = 1 , r = n ; i <= n ; i ++)
            if (i & 1) b[i] = a[l ++];
            else b[i] = a[r --];
        for (int i = 1 ; i <= n ; i ++)
            pre[i] = (1LL * pre[i - 1] * b[i]) % MOD;
        for (int i = n ; i >= 1 ; i --) 
            suf[i] = (1LL * suf[i + 1] * b[i]) % MOD;
        int ans = 1LL * n * pre[n] % MOD;;
        for (int i = 1 ; i < n ; i ++) {
            ans = (ans - 1LL * (1LL * pre[i - 1] * suf[i + 2] % MOD) * min (b[i] , b[i + 1]) % MOD) % MOD;
        }
        printf ("%d\n" , (ans + MOD) % MOD);
    }
    return 0;
}           

