#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
const int N = 200005;
const int inf = N * 10;
struct SegTree {
    int left , right;
    int dist[2][2];
}L[N << 2];
int n , q , own[N] , dist[N][2];
char str[2][N];
#define lson step << 1
#define rson step << 1 | 1
inline int Dist (int l , int x , int r , int y) {
    if (x == y) return dist[l][x];
    else return min (dist[l][x] + own[r] , dist[l][y] + own[l]);
}
void build (int step , int l , int r) {
    L[step].left = l;
    L[step].right = r;
    if (l == r) {
        for (int i = 0 ; i < 2 ; i ++)
            for (int j = 0 ; j < 2 ; j ++) {
                L[step].dist[i][j] = (i == j ? 0 : own[l]);
            }
        return;
    }
    int m = (l + r) >> 1;
    build (lson , l , m);
    build (rson , m + 1 , r);
    for (int i = 0 ; i < 2 ; i ++) {
        for (int j = 0 ; j < 2 ; j ++)
            L[step].dist[i][j] = inf;
    }
    for (int i = 0 ; i < 2 ; i ++) {
        for (int j = 0 ; j < 2 ; j ++) {
            for (int x = 0 ; x < 2 ; x ++) {
                for (int y = 0 ; y < 2 ; y ++) {
                    L[step].dist[i][j] = min (L[step].dist[i][j] , L[lson].dist[i][x] + L[rson].dist[y][j] + Dist (m , x , m + 1 , y));
                }
            }
        }
    }
}
int vis[N << 2][2][2] , idx , dp[N << 2][2][2];
int query (int step , int l , int x , int r , int y) {
    if (L[step].left == l && L[step].right == r) {
        return L[step].dist[x][y];
    }
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) return query (lson , l , x , r , y);
    else if (l > m) return query (rson , l , x , r , y);
    else {
        if (vis[step][x][y] == idx) {
            return dp[step][x][y];
        }
        int ans = inf;
        for (int i = 0 ; i < 2 ; i ++) {
            for (int j = 0 ; j < 2 ; j ++) {
                int tmp = query (lson , l , x , m , i) + query (rson , m + 1 , j , r , y);
                ans = min (ans , tmp + Dist (m , i , m + 1 , j));
            }
        }
        vis[step][x][y] = idx ; dp[step][x][y] = ans;
        return ans;
    }
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    scanf ("%d %d" , &n , &q);
    for (int i = 0 ; i < 2 ; i ++) {
        scanf ("%s" , str[i] + 1);
    }
    for (int i = 1 ; i <= n ; i ++) {
        if (str[0][i] == 'X' || str[1][i] == 'X')
            own[i] = inf;
        else own[i] = 1;
    }
    for (int i = 1 ; i < n ; i ++) {
        for (int j = 0 ; j < 2 ; j ++) {
            if (str[j][i] == 'X' || str[j][i + 1] == 'X')
                dist[i][j] = inf;
            else dist[i][j] = 1;
        }
    }
    build (1 , 1 , n);
    while (q --) {
        idx ++;
        int x , y , l , r;
        scanf ("%d %d" , &x , &y);
        if (x > n) {
            l = x - n;
            x = 1;
        }
        else {
            l = x;x = 0;
        }
        if (y > n) {
            r = y - n;
            y = 1;
        }
        else {
            r = y;y = 0;
        }
        if (l > r) swap (l , r) , swap (x , y);
        int ans = query (1 , l , x , r , y);
        if (ans >= inf) ans = -1;
        printf ("%d\n" , ans);
    }
    return 0;
}