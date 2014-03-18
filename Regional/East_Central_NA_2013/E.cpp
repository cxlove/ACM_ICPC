#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <cctype>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef unsigned long long LL;
const int N = 1000000;
const int M = 10000000;
struct Edge {
    int v , w , next;
}e[M];
int head[N] , tot , level[N] , cur[N];
int source , sink , val[M];
int way[5][2] = {0 , 1 , 0 , -1 , 1 , 0 , -1 , 0 , 0 , 0};
void _add (int u , int v , int w) {
    e[tot].v = v;e[tot].w = w;
    e[tot].next = head[u];head[u] = tot ++;
}
void add (int u , int v , int w) {
    _add (u , v , w);
    _add (v , u , 0);
}
bool bfs(){
    queue<int> q;
    memset(level,-1,sizeof(level));
    level[source] = 0;
    q.push(source);
    while(! q.empty()){
        int u = q.front();q.pop();
        for(int i = head[u];i != -1;i = e[i].next){
            int v = e[i].v;
            if(e[i].w && level[v] == -1){
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    return level[sink] != -1;
}
int dfs(int u,int flow){
    if(u == sink) return flow;
    int tmp = flow;
    for(int &i = cur[u];i != -1;i = e[i].next){
        int v = e[i].v;
        if(e[i].w && level[v] == level[u] + 1){
            int add = dfs(v,min(e[i].w,tmp));
            tmp -= add;
            e[i].w -= add;
            e[i ^ 1].w += add;
            if(! tmp) break;
        }
    }
    return flow - tmp;
}
int dinic(){
    int maxFlow = 0;
    while(bfs()){
        for(int i = 0;i < N ;i ++)
            cur[i] = head[i];
        maxFlow += dfs(source,int(1e9));
    }
    return maxFlow;
}
int n;
char str[26][26];
int main () {
#ifndef ONLINE_JUDGE 
    freopen ("input.txt" , "r" , stdin);
    freopen ("output.txt" , "w" , stdout);
#endif 
    int cas = 0;
    while (scanf ("%d" , &n) != EOF && n) {
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%s" , str[i]);
        }
        printf ("Case %d: " , ++ cas);
        if (n == 1) {
            printf ("0\n");
            continue;
        }
        memset (head , -1 , sizeof (head));
        tot = 0;source = 0;sink = N - 1;
        for (int x = 0 ; x < n ; x ++) {
            int y = 0;int id = x * n + y + 1;
            add (source , id , 1);
        }
        for (int x = 0 ; x < n ; x ++) {
            int id = N - 1 - (n - x);
            add (id , sink , 1);
        }
        int maxflow = 0;
        for (int t = 1 ; ; t ++) {
            // for (int i = 0 ; i < tot ; i ++)
            //     e[i].w = val[i];
            for (int j = 0 ; j < n ; j ++) {
                for (int k = 0 ; k < n ; k ++) {
                    if (str[j][k] == 'X') continue;
                    int old = j * n + k + 1 + (t - 1) * n * n;
                    for (int dir = 0 ; dir < 5 ; dir ++) {
                        int x = j + way[dir][0] , y = k + way[dir][1];
                        if (x >= 0 && y >= 0 && x < n && y < n && str[x][y] != 'X') {
                            int now = x * n + y + 1 + t * n * n;
                            add (old , now , 1);
                        }
                    }
                }
            }
            for (int x = 0 ; x < n ; x ++) {
                int y = n - 1;
                int now = x * n + y + 1 + t * n * n;
                int des = N - 1 - (n - x);
                add (now , des , 1);
            }
            maxflow += dinic ();
            if (maxflow == n) {
                printf ("%d\n" , t);
                break;
            }
        }
    }
    return 0;
}