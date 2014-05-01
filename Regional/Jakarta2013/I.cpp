#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
#include <ctime>
#include <queue>
#include <map>
#include <stack>
#include <cmath>
using namespace std;
const int N = 10000005;
const int HASH = 1000000007;
int n , m , a[N];
bool check (int k) {
    int d = n / m;
    int l = a[0] - k , r = a[0] + k;
    for (int i = 1 ; i < m ; i ++) {
        l = max (l + d , a[i] - k);
        r = min (r + d , a[i] + k);
    }
    return l <= r;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &n , &m);
        for (int i = 0 ; i < m ; i ++) {
            scanf ("%d" , &a[i]);
        }
        sort (a , a + m);
        int low = 0 , high = n , mid , ans = -1;
        while (low <= high) {
            mid = (low + high) >> 1;
            if (check (mid)) ans = mid , high = mid - 1;
            else low = mid + 1;
        }
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}