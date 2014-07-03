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
const int N = 30;
int a[N][N] , b[N][N] , n;
void rotate () {
    int c[N][N];
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++)
            c[j][n - i - 1] = a[i][j];
    }
    memcpy (a , c , sizeof(a));
}
int gao () {
    int cnt = 0;
    for (int i = 0 ; i < n ; i ++)
        for (int j = 0 ; j < n ; j ++)
            cnt += a[i][j] == b[i][j];
        return cnt;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d" , &n) != EOF && n) {
        for (int i = 0 ; i < n ; i ++)
            for (int j = 0 ; j < n ; j ++)
                scanf ("%d" , &a[i][j]);
        for (int i = 0 ; i < n ; i ++)
            for (int j = 0 ; j < n ; j ++)
                scanf ("%d" , &b[i][j]);
        int ans = 0;
        ans = max (ans , gao ());
        rotate ();
        ans = max (ans , gao ());
        rotate ();
        ans = max (ans , gao ());
        rotate ();
        ans = max (ans , gao ());
        printf ("%d\n" , ans);
    }
    return 0;
}