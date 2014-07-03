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
const int N = 4005;
struct Edge {
    int v , next;
}e[N * N];
int start[N] , tot , n;
int dfn[N] , idx , low[N] , instack[N] , blockId , stack[N] , top , block[N];
bool love[N / 2][N / 2];
void add (int u , int v) {
    e[tot].v = v;e[tot].next = start[u];start[u] = tot ++;
}
void dfs (int u) {
    dfn[u] = low[u] = idx ++;
    stack[++ top] = u;
    instack[u] = 1;
    for (int i = start[u] ; i != -1 ; i = e[i].next) {
        int v = e[i].v;
        if (!dfn[v]) {
            dfs (v);
            low[u] = min (low[u] , low[v]);
        }
        else if (instack[v]) {
            low[u] = min (low[u] , dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        int v = -1;
        do {
            v = stack[top --];
            instack[v] = 0;
            block[v] = blockId;
        }while (u != v);
        blockId ++;
    }
}
void Tarjan () {
    memset (instack , 0 , sizeof (instack));
    memset (dfn , 0 , sizeof (dfn));
    idx = blockId = top = 0;
    for (int i = 1 ; i <= 2 * n ; i ++) {
        if (!dfn[i])
            dfs (i);
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    while (scanf ("%d" , &n) != EOF) {
        tot = 0;
        memset (start , -1 , sizeof (start));
        memset (love , 0 , sizeof (love));
        for (int i = 1 ; i <= n ; i ++) {
            int k;scanf ("%d" , &k);
            while (k --) {
                int j;scanf ("%d" , &j);
                love[i][j] = true;
                add (i , j + n);
            }   
        }
        for (int i = 1 ; i <= n ; i ++) {
            int j;scanf ("%d" , &j);
            add (j + n , i);
        }
        Tarjan ();
        for (int i = 1 ; i <= n ; i ++) {
            vector <int> ans;
            for (int j = start[i] ; j != -1 ; j = e[j].next) {
                int v = e[j].v;
                if (block[i] == block[v]) {
                    ans.push_back (v - n);
                }
            }
            sort (ans.begin () , ans.end ());
            printf ("%d" , ans.size());
            for (int j = 0 ; j < ans.size() ; j ++)
                printf (" %d" , ans[j]);
            puts ("");
        }
    }
    return 0;
}