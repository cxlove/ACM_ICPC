#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
using namespace std;
typedef long long LL;
const int MOD = 10007;
int powmod (int a , int b) {
    int ret = 1;
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
    int t , cas = 0 , k;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &k);
        int ans = powmod (k , 54 + 8 + 12);
        ans = (ans + 6 * powmod (k , 15 + 3 + 2)) % MOD;
        ans = (ans + 3 * powmod (k , 28 + 6 + 4)) % MOD;
        ans = (ans + 6 * powmod (k , 27 + 7 + 4)) % MOD;
        ans = (ans + 8 * powmod (k , 18 + 4 + 4)) % MOD;
        ans = (ans * powmod(24 , MOD - 2)) % MOD;
        printf ("Case %d: %d\n" , ++cas , ans); 
    }
    return 0;
}