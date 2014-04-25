#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
#include <map>
using namespace std;
const int N = 300005;
const int inf = N * 10;
int n , k , a[N] , c[N] , s[N];
int u[N] , v[N];
map <pair <int , int>  , int> mymap;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    scanf ("%d %d" , &n , &k);
    for (int i = 1 ; i <= n ; i ++) {
        scanf ("%d %d" , &u[i] , &v[i]);
        if (u[i] > v[i]) swap (u[i] , v[i]);
        a[u[i]] ++; a[v[i]] ++;
        mymap[make_pair (u[i] , v[i])] ++;
    }
    for (int i = 1 ; i <= n ; i ++) {
        c[a[i]] ++;
    }
    long long ans = 0;
    for (int i = 0 ; i <= n ; i ++) {
        int p = i - 1 , q = max (0 , k - i);
        if (p >= q)
            ans += (s[p] - (q == 0 ? 0 : s[q - 1])) * 1LL * c[i];
        if (i + i >= k)
            ans += 1LL * c[i] * (c[i] - 1) / 2;
        s[i] = s[i - 1] + c[i];
    }
    for (map <pair <int , int> , int> :: iterator it = mymap.begin () ; it != mymap.end () ; it ++) {
        int x = (*it).first.first , y =  (*it).first.second;
        long long t = a[x] + a[y];
        long long d = t - (*it).second;
        if (t >= k && d < k) {
            ans --;
        }
    }
    cout << ans << endl;
    return 0;
}