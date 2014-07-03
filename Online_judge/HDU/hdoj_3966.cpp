#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define pii pair<int,LL>
using namespace std;
typedef long long LL;
namespace HeavyLightDecomposition {
    const int N = 50005;
    int size[N] , top[N] , w[N] , son[N];
    int father[N] , dep[N];
    int start[N] , tot , val[N];
    int n , root , nodecnt;
    struct Edge {
        int v ,  next;
    }e[N << 1];
    inline void _add (int u , int v) {
        e[tot].v = v;
        e[tot].next = start[u];start[u] = tot ++;
    }
    inline void add (int u , int v) {
        _add (u , v);
        _add (v , u);
    }
    void cal_size_dep_father_son (int u) {
        size[u] = 1;
        for (int i = start[u] ; i != -1 ; i = e[i].next) {
            int v = e[i].v;
            if (v == father[u]) continue;
            dep[v] = dep[u] + 1;
            father[v] = u;
            cal_size_dep_father_son (v);
            size[u] += size[v];
            // heavy son
            if (son[u] == -1 || size[son[u]] < size[v])
                son[u] = v;
        }
    }
    void cal_top_w (int u , int TOP) {
        top[u] = TOP;
        w[u] = ++ nodecnt;
        // leaf
        if (son[u] == -1) return ;
        else cal_top_w (son[u] , TOP);
        for (int i = start[u] ; i != -1 ; i = e[i].next) {
            int v = e[i].v;
            if (v != son[u] && v != father[u])
                cal_top_w (v , v);
        }
    }
    struct Segment_tree {
        int left , right , lazy , val;
    }L[N << 2];
    #define lson step << 1
    #define rson step << 1 | 1
    void bulid (int step , int l , int r) {
        L[step].left = l;
        L[step].right = r;
        L[step].lazy = L[step].val = 0;
        if (l == r) return ;
        int m = (l + r) >> 1;
        bulid (lson , l , m);
        bulid (rson , m + 1 , r);
    }
    void update (int step , int l , int r , int val) ;
    inline void push_down (int step) {
        int l = L[step].left , r = L[step].right , m = (l + r) >> 1 , &z = L[step].lazy;
        if (l != r) {
            update (lson , l , m , z);
            update (rson , m + 1 , r , z);
            z = 0;
        }
    }
    void update (int step , int l , int r , int val) {
        if (L[step].left == l && L[step].right == r) {
            L[step].lazy += val;
            L[step].val += val;
            return ;
        }
        push_down (step);
        int m = (L[step].left + L[step].right) >> 1;
        if (r <= m) update (lson , l , r , val);
        else if (l > m) update (rson , l , r , val);
        else {
            update (lson , l , m , val);
            update (rson , m + 1 , r , val);
        }
    }
    int query (int step , int pos) {
        if (L[step].left == L[step].right) {
            return L[step].val;
        }
        push_down (step);
        int m = (L[step].left + L[step].right) >> 1;
        if (pos <= m) return query (lson , pos);
        else return query (rson , pos);
    }
    void init () {
        tot = nodecnt = 0;
        memset (start , -1 , sizeof(start));
        memset (son , -1 , sizeof(son));
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d" , &val[i]);
        }
        for (int i = 1 ; i < n ; i ++) {
            int u , v , w;
            scanf ("%d %d" , &u , &v);
            add (u , v);
        }
        root = (n + 1) / 2;
        dep[root] = father[root] = 0;
        cal_size_dep_father_son (root);
        cal_top_w (root , root);
        bulid (1 , 1 , nodecnt);
        for (int i = 1 ; i <= n ; i ++) {
            update (1 , w[i] , w[i] , val[i]);
        }
    }
    void gao_update (int u , int v , int val) {
        int t1 = top[u] , t2 = top[v];
        while (t1 != t2) {
            if (dep[t1] < dep[t2]) swap (t1 , t2) , swap (u , v);
            update (1 , w[t1] , w[u] , val);
            u = father[t1] , t1 = top[u];
        }
        if (dep[u] > dep[v]) swap (u , v);
        update (1 , w[u] , w[v] , val);
    }
}using namespace HeavyLightDecomposition;
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int m , q;
    while (scanf ("%d %d %d" , &n , &m , &q) != EOF) {
        init ();
        while (q --) {
            char ope[15];
            scanf ("%s" , ope);
            if (ope[0] == 'Q') {
                int u;scanf ("%d" , &u);
                printf ("%d\n" , query (1 , w[u]));
            }
            else {
                int u , v , val;
                scanf ("%d %d %d" , &u , &v , &val);
                if (ope[0] == 'D') val = -val;
                gao_update (u , v , val);
            }
        }
    }
    
    return 0;
}       