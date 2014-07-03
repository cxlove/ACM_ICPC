#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1005;
struct Dominoe {
    int x1 , y1 , x2 , y2;
    void input (int k) {
        scanf ("%d %d", &x1 , &y1);
        if (k == 0) x2 = x1 + 1 , y2 = y1;
        else x2 = x1 , y2 = y1 + 1;
    }
    bool operator == (const Dominoe &d) const {
        return (x1 == d.x1 && y1 == d.y1) || (x2 == d.x2 && y2 == d.y2) || (x1 == d.x2 && y1 == d.y2) || (x2 == d.x1 && y2 == d.y1);
    }
}row[N] , col[N];
struct Edge {
    int v , next;
}e[N << 2];
int tot , start[N];
int match[N] , vis[N];
int n , m;
void add (int u , int v) {
    e[tot] . v = v;
    e[tot] . next = start[u];
    start[u] = tot ++;
}
bool dfs (int u) {
    for (int i = start[u] ; i != -1 ; i = e[i].next) {
        int v = e[i].v;
        if (!vis[v]) {
            vis[v] = 1;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}
int hungry () {
    memset (match , -1 , sizeof(match));
    int ans = 0 ;
    for (int i = 0 ; i < n ; i ++) {
        memset (vis , 0 , sizeof(vis));
        if (dfs(i)) ans ++;
    }
    return ans;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%d %d" , &n , &m) != EOF) {
        if (!n && !m) break;
        tot = 0 ; memset (start , -1 , sizeof(start));
        for (int i = 0 ; i < n ; i ++) {
            row[i].input (0);
        }
        for (int i = 0 ; i < m ; i ++) {
            col[i].input (1);
        }
        for (int i = 0 ; i < n ; i ++) {
            for (int j = 0 ; j < m ; j ++) {
                if (row[i] == col[j]) {
                    add (i , j);
                }
            }
        }
        printf ("%d\n" , n + m - hungry ());
    } 
    return 0;
}