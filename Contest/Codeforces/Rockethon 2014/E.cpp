#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 100005;
const int MOD = 1000000007;
LL ans = 0;
struct Tree {
    vector <int> e[N];
    int n , size[N] , best , dist[N];
    LL up[N] , down[N] , sum;
    void init () {
        for (int i = 1 ; i < n ; i ++) {
            int u , v;
            scanf ("%d %d" , &u , &v);
            e[u].push_back (v);
            e[v].push_back (u);
        }
    }
    void dfs (int u , int pre) {
        size[u] = 1;
        up[u] = 0;
        int sz = e[u].size();
        for (int i = 0 ; i < sz ; i ++) {
            int v = e[u][i];
            if (v == pre) continue;
            dfs (v , u);
            size[u] += size[v];
            up[u] += up[v] + size[v];
        }
    }
    void dfs2 (int u , int pre) {
        int sz = e[u].size();
        for (int i = 0 ; i < sz ; i ++) {
            int v = e[u][i];
            if (v == pre) continue;
            down[v] = up[u] + down[u] - up[v] - size[v] + n - size[v];
            dfs2 (v , u);
        }
    }
    void dfs3 (int u , int pre) {
        int sz = e[u].size ();
        for (int i = 0 ; i < sz ; i ++) {
            int v = e[u][i];
            if (v == pre) continue;
            dist[v] = dist[u] + 1;
            dfs3 (v , u);
        }

    }
    void gao () {
        dfs (1 , 0);dfs2 (1 , 0);
        sum = -1;
        for (int i = 1 ; i <= n ; i ++) {
            ans += up[i] + down[i];
            if (up[i] + down[i] > sum) {
                sum = up[i] + down[i];
                best = i;
            }
        }
        dist[best] = 0;
        dfs3 (best , 0);
    }
}a[3];
int id[3];
LL cal (Tree &a , Tree &b , Tree &c) {
    LL ans = 0;
    for (int i = 1 ; i <= b.n ; i ++) {
        LL ret = 0;
        ret += a.sum * b.n + b.sum * a.n;
        ret += (b.up[i] + b.down[i]) * c.n + c.sum * b.n;
        ret += 1LL * a.n * b.n + 1LL * b.n * c.n;
        ret += a.sum * c.n + c.sum * a.n;
        ret += (2LL + b.dist[i]) * 1LL * a.n * c.n;
        ans = max (ans , ret);
    }
    return ans;
}
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    for (int i = 0 ; i < 3 ; i ++) scanf ("%d" , &a[i].n);
    for (int i = 0 ; i < 3 ; i ++) a[i].init ();
    for (int i = 0 ; i < 3 ; i ++) {
        a[i].gao ();
        id[i] = i;
    }
    LL ret = 0;
    ans /= 2;
    do {
        ret = max (ret , cal (a[id[0]] , a[id[1]] , a[id[2]]));
    }while (next_permutation (id , id + 3));
    printf ("%I64d\n" , ans + ret);
    return 0;
}