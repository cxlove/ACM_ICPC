#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
struct Treap {
    int child[N][2] , priority[N] , cnt[N] , size[N] , key[N];
    int pool[N] , tot , waste , root;
    inline void clear () {
        tot = waste = root = 0;
        size[root] = cnt[root] = 0;
        child[root][0] = child[root][1] = 0;
        priority[root] = 0x7fffffff;
    }
    inline int random () {
        return (rand () << 15) | rand ();
    } 
    inline void newnode (int &x , int y) {
        if (waste) x = pool[-- waste];
        else x = ++ tot;
        child[x][0] = child[x][1] = 0;
        priority[x] = random ();
        cnt[x] = 1;key[x] = y;
    }
    inline void push_up (int x) {
        size[x] = size[child[x][0]] + size[child[x][1]] + cnt[x];
    }
    inline void rotate (int &x , int t) {
        int y = child[x][t];
        child[x][t] = child[y][t ^ 1];
        child[y][t ^ 1] = x;
        push_up (x);push_up (y);
        x = y;
    }
    void __insert (int &x , int y) {
        if (x) {
            if (key[x] == y) cnt[x] ++;
            else {
                int son = y < key[x] ? 0 : 1;
                __insert (child[x][son] , y);
                if (priority[child[x][son]] < priority[x])
                    rotate (x , son);
            }
        }
        else newnode (x , y);
        push_up (x);
    }
    void __erase (int &x , int y) {
        if (!x) return;
        if (key[x] == y) {
            if (cnt[x]) cnt[x] --;
            else {
                if (!child[x][0] && !child[x][1]) {
                    pool[waste ++] = x;
                    x = 0;
                    return ;
                }
                int son = priority[child[x][0]] > priority[child[x][1]];
                rotate (x , son);
                __erase (x , y);
            }
        }
        else __erase (child[x][y > key[x]] , y);
        push_up (x);
    }
    int __getKth (int &x , int k) {
        if (size[child[x][0]] >= k) return __getKth (child[x][0] , k);
        k -= size[child[x][0]] + cnt[x];
        if (k <= 0) return key[x];
        return __getKth (child[x][1] , k);
    }
    inline void insert (int num) {
        __insert (root , num);
    }
    inline void erase (int num) {
        __erase (root , num);
    }
    inline int getKth (int num) {
        return __getKth (root , num);
    }
}treap;
struct Ask {
    int l , r , k , id;
    inline void input (int i) {
        id = i;
        scanf ("%d %d %d" , &l , &r , &k);
    }
    bool operator < (const Ask &n) const {
        return l < n.l;
    }
}ask[N];
int n , q , a[N] , ans[N];
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    while (scanf ("%d %d" , &n , &q) != EOF) {
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d" , &a[i]);
        }
        for (int i = 0 ; i < q ; i ++)
            ask[i].input (i);
        sort (ask , ask + q);
        treap.clear ();
        for (int i = 0 , l = 1 , r = 0 ; i < q ; i ++) {
            while (r < ask[i].r) treap.insert (a[++ r]);
            while (l < ask[i].l) treap.erase (a[l ++]);
            ans[ask[i].id] = treap.getKth (ask[i].k);
        }
        for (int i = 0 ; i < q ; i ++) {
            printf ("%d\n" , ans[i]);
        }
    }
    return 0;
}