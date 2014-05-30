#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <vector>
#include <sstream>
#include <set>
#include <ctime>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 10005;
const int M = 100005;
const int MOD = 1000000007;
struct Edge {
    int v , next;
}e[M << 1];
int tot , start[N] , n , m;
int stack[N] , instack[N] , top , idx , dfn[N] , low[N] , block[N] , blockCnt;
inline void add (int u , int v) {
    e[tot].v = v;e[tot].next = start[u];start[u] = tot ++;
}
void dfs (int u , int pre) {
    // cout << u << " " << pre << endl;
    dfn[u] = low[u] = ++ idx;
    stack[++ top] = u;
    instack[u] = 1;
    int flag = 0;
    for (int i = start[u] ; i != -1 ; i = e[i].next) {
        int v = e[i].v;
        if (v == pre && !flag) {
            flag = 1;
            continue;
        }
        if (!dfn[v]) {
            dfs (v , u);
            low[u] = min (low[u] , low[v]);
        }
        else if (instack[v]) {
            low[u] = min (low[u] , dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        if (stack[top] == u) {
            top -- ;
            return;
        }
        blockCnt ++;
        int v;
        do {
            v = stack[top --];
            block[v] = blockCnt;
            instack[v] = 0;
        }while (u != v);
    }
}
void dcc () {
    memset (block , 0 , sizeof (block));
    memset (instack , 0 , sizeof (instack));
    memset (dfn , 0 , sizeof (dfn));
    top = blockCnt = idx = 0;
    for (int i = 1 ; i <= n ; i ++) {
        if (!dfn[i]) {
            dfs (i , -1);
        }
    }
}
int __cnt;
void cal (int u , int pre) {
    block[u] = 1;__cnt ++;
    for (int i = start[u] ; i != -1 ; i = e[i].next) {
        int v = e[i].v;
        if (v == pre || block[v]) continue;
        cal (v , u);
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        tot = 0;memset (start , -1 , sizeof (start));
        scanf ("%d %d" , &n , &m);
        for (int i = 0 ; i < m ; i ++) {
            int u , v;
            scanf ("%d %d" , &u , &v);
            add (u , v);add (v , u);
        }
        dcc ();
        int ans = 0;
        for (int i = 1 ; i <= n ; i ++) {
            if (!block[i]) {
                __cnt = 0;
                cal (i , -1);
                ans += (__cnt - 1) * __cnt / 2;
            }
        }
        printf ("Case #%d: %d\n" , ++ cas , ans);
    }
    return 0;
}