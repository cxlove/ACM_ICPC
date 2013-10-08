#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#define error {puts("-1");return 0;}
#define mp(a,b) make_pair(a , b)
#define mpp(a,b,c) mp(mp(a,b),c)
#define HASH 1000000007
using namespace std;
typedef long long LL;
const int N = 25;
int n , m  , row[N] , s[1 << 13] , ans;
char str[N + 5][N + 5];
void dfs (int r , int c , int m) {
    if (c >= ans) return;
    // cout << r << " " << c << " " << m << endl;
    if (r == n) ans = min (ans , max (c , s[m >> 13] + s[m & ((1 << 13) - 1)]));
    else {
        dfs (r + 1 , c + 1 , m);
        dfs (r + 1 , c , m | row[r]);
    }
}
int main () {  
    s[0] = 0;
    for (int i = 1 ; i < 1 << 13 ; i ++)
        s[i] = s[i >> 1] + (i & 1);
    while (scanf ("%d %d" , &n , &m) != EOF) {
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%s" , str[i]);
            row[i] = 0;
            for (int j = 0 ; j < m ; j ++)
                if (str[i][j] == '*')
                    row[i] |= 1 << j;
        }
        ans = max (n , m);
        dfs (0 , 0 , 0);
        printf ("%d\n" , ans);
    }
    return 0;
}
