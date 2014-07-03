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
const int N = 200005;
typedef long long LL;
int n , a , b  , c[N];
int gcd (int a , int b) {
    return b == 0 ? a : gcd(b , a % b);
}
LL LCM (int a , int b) {
    return a / gcd (a , b) * 1LL * b;
}
LL gao (LL n , LL a , LL b) {
    LL ans = 0 , i = 0 ;
    while (i < n) {
        LL j = (a - i % a) > (b - i % b) ? (b - i % b) : ( a - i % a);
        if (i + j >= n) j = n - i ;
        ans += abs(i % a - i % b) * j;
        i += j;  
    } 
    return ans;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif 
    int t ;
    scanf ("%d" , &t);
    while (t --) {
        memset (c, 0 , sizeof(c));
        scanf ("%d %d %d", &n , &a , &b);
        LL lcm = LCM (a , b);
        LL ans ;
        if (lcm >= n) {
            ans = gao ( n , a , b);
        } 
        else ans = gao (lcm , a , b) * (n / lcm) + gao(n % lcm , a , b);
        cout << ans << endl;
    }
    return 0;
}        