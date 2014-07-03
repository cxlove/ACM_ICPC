#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 100005;
int n , a[N];
int nondown[N] , nonup[N];
int s1[N] , s2[N] , l1 , l2;
int c1[N] , c2[N] , id1[N] , id2[N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t ;
    scanf ("%d", &t);
    while (t --) {
        scanf ("%d", &n);
        for (int i = n ; i ; i --) {
            scanf ("%d", &a[i]);
        }
        l1 = 1;
        l2 = n + 1;
        s1[0] = -1;
        s2[n + 1] = 1 << 30;
        for (int i = 1 ; i <= n ; i ++) {
            int p = upper_bound(s1 , s1 + l1 , a[i]) - s1;
            nondown[i] = p;
            s1[p] = a[i];
            id1[p] = i;
            l1 = max (l1 , p + 1);
            if(s1[p - 1] == a[i]) c1[i] = c1[id1[p - 1]] + 1;
            else c1[i] = 1; 
            p = lower_bound(s2 + l2 , s2 + n + 2 , a[i]) - s2 - 1;
            nonup[i] = n - p + 1;
            s2[p] = a[i];
            id2[p] = i;
            l2 = min (l2 , p);
            if(s2[p + 1] == a[i]) c2[i] = c2[id2[p + 1]] + 1;
            else c2[i] = 1; 
        }
        int ans = 0;
        for (int i = 1 ; i <= n ; i ++) {
            // cout << nonup[i] << " " <<nondown[i] << endl;
            ans = max (ans , nonup[i] + nondown[i] - min(c2[i] , c1[i]));
        }
        printf ("%d\n", ans);
    }
    return 0;
}