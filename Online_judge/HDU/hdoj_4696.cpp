#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
using namespace std;
const int N = 100005;
int n , q , x[N] , c[N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("ouput.txt" , "w" , stdout);
    #endif
    while (scanf ("%d %d" , &n , &q) != EOF) {
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d" , &x[i]);
        }
        bool one = false;
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d" , &c[i]);
            if (c[i] == 1) one = true;
        }
        while (q --) {
            int k ;
            scanf ("%d" , &k);
            if (k <= 0) puts ("NO");
            else {
                if (k % 2 == 0) puts ("YES");
                else {
                    if (one) puts ("YES");
                    else puts ("NO");
                }
            }
        }
    }

    return 0;
}        