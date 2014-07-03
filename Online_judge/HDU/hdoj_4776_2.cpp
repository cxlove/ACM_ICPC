#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const int N = 100005;
const int BIT = 61;
struct Edge {
    int v , next;
    LL w;
}e[N << 1];
struct Trie {
    Trie *next[2];
    int cnt;
}s[N * 64] , *root;
struct Node {
    LL val;int idx , k;
    Node () {}
    Node (LL _v , int _i , int _k) {
        val = _v;idx = _i;k = _k;
    }
    bool operator < (const Node &n) const {
        return val != n.val ? val < n.val : idx < n.idx;
    }
};
int n , m , start[N] , tot , cnt;
LL dist[N] , a[N] , ans[N << 1];
priority_queue <Node> que;
void _add (int u , int v , LL w) {
    e[tot].v = v;
    e[tot].w = w;
    e[tot].next = start[u];
    start[u] = tot ++;
}
void add (int u , int v , LL w) {
    _add (u , v , w);
    _add (v , u , w);
}
void dfs (int u , int pre) {
    for (int i = start[u] ; i != -1 ; i = e[i].next) {
        int v = e[i].v;LL w = e[i].w;
        if (v != pre) {
            dist[v] = dist[u] ^ w;
            dfs (v , u);
        }
    }
}
Trie *newnode () {
    Trie *r = &s[++ cnt];
    r -> next[0] = r -> next[1] = NULL;
    r -> cnt = 0;
    return r;
}
void insert (Trie *root , LL num) {
    Trie *p = root;
    for (int i = BIT ; i >= 0 ; i --) {
        int s = (num >> i) & 1;
        if (p -> next[s] == NULL) p -> next[s] = newnode ();
        p = p -> next[s];
    }
    p -> cnt ++;
}
int gao (Trie *p) {
    if (p == NULL) return 0;
    p -> cnt += gao (p -> next[0]) + gao(p -> next[1]);
    return p -> cnt;
}
LL get_kth (Trie *root , LL num , int k) {
    Trie *p = root;
    LL ret = 0;
    for (int i = BIT ; i >= 0 ; i --) {
        int s = (num >> i) & 1;s = !s;
        if (p -> next[s] && p -> next[s] -> cnt >= k) {
            p = p -> next[s] , ret |= 1LL << i;
        }
        else {
            k -= p -> next[s] == NULL ? 0 : p -> next[s] -> cnt;
            p = p -> next[!s];
        }
    }
    return ret;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d" , &n) != EOF && n) {
        tot = cnt = 0;
        memset (start , -1 , sizeof(start));
        for (int i = 1 ; i < n ; i ++) {
            int u , v; LL w;
            scanf ("%d %d %I64d" , &u , &v , &w);
            add (u , v , w);
        }
        dist[1] = 0;
        dfs (1 , 0);
        root = newnode ();
        for (int i = 1 ; i <= n ; i ++) {
            a[i] = dist[i];
            insert (root , a[i]);
        }
        gao (root);
        while (!que.empty ()) que.pop ();
        for (int i = 1 ; i <= n ; i ++) {
            que.push (Node (get_kth (root , a[i] , 1) , i , 1));
        }
        LL k = min (200000LL , 1LL * (n - 1) * n);
        for (int i = 1 ; i <= k ; i ++) {
            Node q = que.top ();que.pop ();
            ans[i] = q.val;
            if (q.k == n - 1) continue;
            q.k ++;
            que.push (Node (get_kth (root , a[q.idx] , q.k) , q.idx , q.k));
        }
        int q;
        scanf ("%d" , &q);
        while (q --) {
            int kind; scanf ("%d" , &kind);
            if (kind < 1 || kind > k) puts ("-1");
            else printf ("%I64d\n" , ans[kind]);
        }
    }
    return 0;
}