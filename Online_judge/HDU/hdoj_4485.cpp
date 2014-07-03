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
const int N = 105;

char str[10000005];
int main () {
    // #ifndef ONLINE_JUDGE
    //     freopen ("input.txt" , "r" , stdin);
    //     // freopen ("output.txt" , "w" , stdout);
    // #endif
    int t ;
    scanf ("%d" , &t);
    while (t --) {
        int cas , b , ans = 0;
        scanf ("%d %d %s" , &cas , &b , str);
        for (int i = 0 ; str[i] ; i ++) {
            ans = (ans * b + str[i] - '0') % (b - 1);
        }
        printf ("%d %d\n" , cas , ans);
    }
    return 0;
}