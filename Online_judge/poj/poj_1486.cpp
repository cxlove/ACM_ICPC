#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>  
#include <ctime>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 100;
const int MOD = 1000000007;
struct Rec {
    int x1 , x2 , y1 , y2;
    inline void input () {
        scanf ("%d %d %d %d" , &x1 , &x2 , &y1 , &y2);
    }
}rec[N];
struct Point {
    int x , y;
    inline void input () {
        scanf ("%d %d" , &x , &y);
    }
}p[N];
int n , can[N][N] , match[N] , ans[N] , vis[N];
int in (Point p , Rec r) {
    if (p.x >= r.x1 && p.x <= r.x2 && p.y >= r.y1 && p.y <= r. y2)
        return 1;
    return 0;
}
bool dfs (int u) {
    for (int i = 0 ; i < n ; i ++) {
        if (can[u][i] && !vis[i]) {
            vis[i] = 1;
            if  (match[i] == -1 || dfs (match[i])) {
                match[i] = u;
                return true;
            }
        }
    }
    return false;
}
int hungry () {
    int ans = 0;
    memset (match , -1 , sizeof(match));
    for (int i = 0 ; i < n ; i ++) {
        memset (vis , 0 , sizeof(vis));
        if (dfs (i)) ans ++;
    }
    return ans;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int cas = 0;
    while (scanf ("%d" , &n) != EOF && n) {
        for (int i = 0 ; i < n ; i ++) 
            rec[i].input ();
        for (int i = 0 ; i < n ; i ++)
            p[i].input ();
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < n ; j ++) {
                can[i][j] = in (p[i] , rec[j]);
            }
        }
        printf ("Heap %d\n" , ++ cas);
        if (hungry () == n) {
            int cnt = 0;
            memcpy (ans , match , sizeof(match));
            for (int i = 0 ; i < n ; i ++) {
                int t = ans[i];
                can[t][i] = 0;
                if (hungry () != n) {
                    cnt ++;
                    if (cnt > 1) printf (" ");
                    printf ("(%c,%d)" , i + 'A' , ans[i] + 1);
                }
                can[t][i] = 1;
            }
            if (!cnt) puts ("none");
            else puts ("");
        }
        else puts ("none");
        puts ("");
    }
    return 0;
}