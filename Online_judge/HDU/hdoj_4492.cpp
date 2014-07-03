#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
const int N = 1005;
char str[N];
int n , a[N];
int main () {
    // #ifndef ONLINE_JUDGE
    //     freopen ("input.txt" , "r" , stdin);
    //     // freopen ("output.txt" , "w" , stdout);
    // #endif
    int t ;
    scanf ("%d" , &t);
    while (t --) {
        int cas , n;
        scanf ("%d" , &cas);char ch = getchar ();
        gets (str);
        int l = strlen (str);
        // cout << l << endl;
        scanf ("%d" , &n);
        printf ("%d " , cas);
        int p = 0;
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d" , &a[i]);
            p = ((p + a[i]) % l + l) % l;
            putchar (str[p]);
        }
        puts ("");
    }
    return 0;
}