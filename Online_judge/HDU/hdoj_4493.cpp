#include <iostream>
#include <cstdio>
using namespace std;
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t ;
    scanf ("%d" , &t);
    while (t --) {
        double ans = 0;
        for (int i = 0 ; i < 12 ; i ++) {
            double k;
            scanf ("%lf" , &k);
            ans += k;
        }
        ans = ans / 12.0;
        int ret = (ans * 100 + 0.5);
        if (ret % 100 == 0) printf ("$%d\n" , ret / 100);
        else if (ret % 10 == 0) printf ("$%.1f\n" , ret / 100.0);
        else printf ("$%.2f\n" , ret / 100.0);
    }
    return 0;
}