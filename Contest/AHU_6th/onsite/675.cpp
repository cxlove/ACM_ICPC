#include <iostream>
#include <cstdio>
#include <set>
using namespace std;
const int N = 100005;
int n , a[N] , s[N];
set <int> c[N];
int main () {
    while (scanf ("%d" , &n) != EOF) {
        for (int i = 0 ; i < n ; i ++)
            c[i].clear ();
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d" , &a[i]);
            s[i] = (s[i - 1] + a[i]) % n;
            c[s[i]].insert (i);
        }
        int L , R;
        for (int l = 1 ; l <= n ; l ++) {
            if (c[s[l - 1]].size() > 0) {
                L = l;
                R = *c[s[l - 1]].begin ();
                break;
            }
            c[s[l]].erase (l);
        }
        printf ("%d %d\n" , L , R);
    }
    return 0;
}