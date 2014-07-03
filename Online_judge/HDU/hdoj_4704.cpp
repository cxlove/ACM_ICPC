#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <set>
#include <cstring>
#define lson step << 1
#define rson step << 1 | 1
#define mp make_pair
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
char str[1000005];
LL powmod (LL a , LL b) {
    LL ret = 1LL;
    while (b) {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    } 
    return ret;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%s" , str) != EOF) {
        int l = strlen(str);
        LL sum = 0;
        for (int i = 0 ; i < l ; i ++) {
            sum = (sum * 10 + str[i] - '0') % (MOD - 1);
        }
        sum = (sum - 1 + MOD - 1) % (MOD - 1);
        printf ("%I64d\n" , powmod (2LL , sum));
    } 
    return 0;
}           