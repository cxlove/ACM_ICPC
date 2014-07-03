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


int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t , n , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        printf ("Case #%d:\n" , ++cas);
        puts ("*------------*");
        for (int i = 100 ; i > 0 ; i -= 10) {
            if (n >= i) puts ("|------------|");
            else puts ("|............|");
        }
        puts ("*------------*");
    }
    return 0;
}