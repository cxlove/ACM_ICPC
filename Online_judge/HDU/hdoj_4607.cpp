#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 100005;
struct Edge{
    int v, next;
}e[N << 1];
int n , q;
int tot , start[N], mx, idx;
void bfs (int s) {
    int dist[N];
    memset (dist , 0x11 , sizeof(dist));
    dist[s] = 0;
    queue<int> que;
    que.push(s);
    while (! que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = start[u] ; i != -1 ; i = e[i].next) {
            int v = e[i].v;
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }
    idx = s;
    mx = 0;
    for (int i = 1 ; i <= n ; i ++) {
        if (dist[i] > mx) 
            mx = dist[i], idx = i;
    }
}
void _add (int u , int v) {
    e[tot].v = v;
    e[tot].next = start[u];
    start[u] = tot ++;
}
void add (int u , int v) {
    _add (u , v);
    _add (v , u);
}
int main () {
    // freopen ("input.txt", "r", stdin);
    int t;
    scanf ("%d", &t);
    while (t --) {
        tot = 0 ;
        memset (start , -1 , sizeof(start));
        scanf ("%d %d", &n, &q);
        for (int i = 1 ; i < n ; i ++) {
            int u , v;
            scanf ("%d %d", &u, &v);
            add (u , v);
        }
        bfs (1);
        bfs (idx);
        while (q --) {
            int k;
            scanf ("%d", &k);
            if (k <= mx + 1) printf("%d\n", k - 1);
            else printf("%d\n", mx + (k - mx - 1) * 2);
        }
    }
    return 0;
}