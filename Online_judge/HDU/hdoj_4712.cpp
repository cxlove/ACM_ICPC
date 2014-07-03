#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <ctime>
using namespace std;
typedef long long LL;
const int N = 20;
const int M = 100005;
int s[1 << N] , a[M];
bool cmp (int a , int b) {
    return s[a] < s[b];
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    s[0] = 0;
    for (int i = 1 ; i < 1 << N ; i ++)
        s[i] = s[i >> 1] + (i & 1);
    int t;
    scanf ("%d" , &t);
    while (t --) {
        int n;
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%x" , &a[i]);
        }
        sort (a , a + n , cmp);
        int ans = 21;
        for (int i = 0 ; i < n ; i ++) {
            int lim = min (n , (i + 50));
            for (int j = i + 1 ; j < lim ; j ++)
                ans = min (ans , s[a[i] ^ a[j]]); 
        }
        printf ("%d\n" , ans);
    }
    return 0;
}