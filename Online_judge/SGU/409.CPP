#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <queue>
#define error {puts("0");return 0;}
#define pb push_back
#define mp(a,b) make_pair(a , b)
#define mpp(a,b,c) mp(mp(a,b),c)
#define HASH 1000000007
using namespace std;
const int N = 1005;
typedef long long LL;
int n , k;
char a[N][N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r"  , stdin);
    #endif
    memset (a , '.' , sizeof(a));
    cin >> n >> k;
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < n ; j ++) {
            int x = j * n + i;
            for (int r = x , c = 0 ; c < k ; c ++ , r = (r + 1) % (n * n))
                a[i * n + j][r] = '*';
        }
    }
    for (int i = 0 ; i < n * n ; i ++) {
        for (int j = 0 ; j < n * n ; j ++)
            putchar (a[i][j]);
        puts ("");
    }
    return 0;
}
