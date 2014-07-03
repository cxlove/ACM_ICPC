#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
typedef long long LL ;
const LL MOD = 2011;
LL powmod (LL a , LL b , LL MOD) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
         b >>= 1;
    }
    return ret;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int n;
    while (scanf ("%d" , &n) != EOF && n) {
        LL p = (powmod (6 , n , 30 * MOD) -1 + 30 * MOD) % (30 * MOD);
        LL q = (30 - p % 30);
        if (q == 30) q = 0;
        printf ("%I64d" , (p + q) * powmod (30 , MOD - 2 , MOD) % MOD);
        p = (powmod (6 , n , 5 * MOD) -1 + 5 * MOD) % (5 * MOD);
        q = (5 - p % 5);
        if (q == 5) q = 0;
        printf(" %I64d\n", (p + q) * powmod (5 , MOD - 2 , MOD) % MOD);
    }
    return 0;
}