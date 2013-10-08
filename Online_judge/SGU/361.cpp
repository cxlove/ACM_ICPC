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
const int N = 205;
typedef long long LL;
int n , m;
char a[N][N] , b[N][N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r"  , stdin);
    #endif
    scanf ("%d %d" , &n , &m);
    int ans =  n * m;
    for (int f = 0 ; f < 3 ; f ++) {
        int t = f , cnt = 0;
        memset (a , '0' , sizeof(a));
        for (int i = 0 ; i < n ; i ++ , t = (t + 2) % 3) {
            for (int j = t ; j < m ; j += 3) {
                a[i][j] = '#';
                cnt ++;
            }
        }
        if (cnt < ans ) {
            ans = cnt;
            memcpy (b , a , sizeof(a));
        }
    }
    for (int i = 0 ; i < n ; i ++) {
        for (int j = 0 ; j < m ; j ++)
            putchar (b[i][j]);
        puts ("");
    }
    return 0;
}
