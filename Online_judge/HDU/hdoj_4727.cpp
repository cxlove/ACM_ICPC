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
const int N = 1000005;
int t , cas = 0 , n , a[N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &n);
        for (int i = 0 ; i < n ; i ++)
            scanf ("%d" , &a[i]);
        printf ("Case #%d: " , ++cas);
        for (int i = 1 ; i <= n ; i ++) {
            if (i == n) {
                puts ("1");
            }
            else if (a[i] - a[i - 1] != 1){
                printf ("%d\n" , i + 1);
                break;
            }
        }
        // puts ("");
    }
    return 0;
}