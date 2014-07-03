#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#define error {puts("-1");return 0;}
#define mp(a,b) make_pair(a , b)
#define mpp(a,b,c) mp(mp(a,b),c)
#define HASH 1000000007
using namespace std;
typedef long long LL;
const int N = 1000;
const int M = 100005;
int v[32][M];
int n;LL k;
LL gao (LL a , LL b , LL c) {
    LL low = 1 , high = n , mid , ans = 0;
    while (low <= high) {
        mid = (low + high) >> 1;
        LL t = a * mid * mid + b * mid + c;
        if (t <= 0) ans = mid , low = mid + 1;
        else high = mid - 1;
    }
    return ans;
}
int main () {
    #ifndef ONLINE_JUDGE 
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d%lld" ,&n , &k);
        LL low = -(LL)1e12 , high = (LL)1e12 , mid , ans = -1;
        while (low <= high) {
            LL tmp = 0;
            mid = (low + high) >> 1;
            for (int j = 1 ; j <= n ; j ++) {
                tmp += gao (1 , 100000 + j , 1LL * j * j - 100000LL * j - mid);
            }if (tmp < k) low = mid + 1;
            else high = mid - 1 , ans = mid; 
        }
        printf ("%lld\n" , ans);
    }
    return 0;
}