#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 2000005;
struct Edge {
    int v , w , next;
}e[M];
int n , m , c , val[N];
int flag[N] , start[N << 2] , tot = 0;
void add (int u , int v , int w) {
    e[tot].v = v;
    e[tot].w = w;
    e[tot].next = start[u];
    start[u] = tot ++;
}
int dist[N << 2] , in[N << 2];
int spfa (int st , int ed) {
    queue<int>que;
    memset (dist , 0x3f , sizeof(dist));
    memset (in , 0 , sizeof(in));
    que.push (st);
    in[st] = 1;
    dist[st] = 0;
    while (!que.empty ()) {
        int u = que.front ();
        que.pop ();
        in[u] = 0;
        for (int i = start[u] ; i != -1 ; i = e[i].next) {
            int v = e[i].v , w = e[i].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!in[v]) {
                    in[v] = 1;
                    que.push (v);
                }
            }
        }
    }
    return dist[ed] == 0x3f3f3f3f ? -1 : dist[ed];
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        tot = 0;
        memset (flag , 0 , sizeof(flag));
        memset (start , -1 , sizeof(start));
        scanf ("%d %d %d" , &n , &m , &c);
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d" , &val[i]);
            flag[val[i]] = 1;
        }
        for (int i = 0 ; i < m ; i ++) {
            int u , v , w;
            scanf ("%d %d %d" , &u , &v , &w);
            add (u , v , w);
            add (v , u , w);
        }
        for (int i = 1 ; i <= n ; i ++) {
            if (flag[val[i] + 1] || flag[val[i] - 1]) {
                add (i , n + val[i] , 0);
            }
        }
        for (int i = 1 ; i <= n ; i ++) {
            if (flag[val[i] + 1]) {
                add (n + val[i] + 1 , i , c);
            }
            if (flag[val[i] - 1]) {
                add (n + val[i] - 1 , i , c);
            }
        }
        printf ("Case #%d: %d\n" , ++cas , spfa (1 , n));
    }
    return 0;
}       

