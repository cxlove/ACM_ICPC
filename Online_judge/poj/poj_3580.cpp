#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200005;
struct Treap {
    int child[N][2] , priority[N] , key[N] , size[N] , cnt[N];
    int add[N] , rev[N] , mn[N];
    int tot , waste , pool[N] , root;
    inline void clear () {
        tot = waste = root = 0;
        child[root][0] = child[root][1] = 0;
        priority[root] = -(0x7fffffff);
        key[root] = size[root] = add[root] = rev[root] = 0;
        mn[root] = 0x7fffffff; 
    }
    inline int random () {
        return (rand () << 15) | rand ();
    }
    inline void push_up (int x) {
        size[x] = size[child[x][0]] + size[child[x][1]] + 1;
        mn[x] = min (key[x] , min (mn[child[x][0]] , mn[child[x][1]]));
    }
    inline void push_down (int x) {
        int lson = child[x][0] , rson = child[x][1];
        if (rev[x]) {
            if (lson) rev[lson] ^= 1 , swap (child[lson][0] , child[lson][1]);
            if (rson) rev[rson] ^= 1 , swap (child[rson][0] , child[rson][1]);
            rev[x] = 0;
        }
        if (add[x]) {
            int v = add[x];
            if (lson) key[lson] += v , mn[lson] += v , add[lson] += v;
            if (rson) key[rson] += v , mn[rson] += v , add[rson] += v;
            add[x] = 0;
        }
    }
    inline void newnode (int &x , int y) {
        if (waste) x = pool[-- waste];
        else x = ++ tot;
        child[x][0] = child[x][1] = 0;
        key[x] = mn[x] = y;
        size[x] = 1;
        priority[x] = random ();
        add[x] = rev[x] = 0;
    }
    inline void rotate (int &x , int t) {
        int y = child[x][t];
        push_down (x);push_down (y);
        child[x][t] = child[y][t ^ 1];
        child[y][t ^ 1] = x;
        push_up (x);push_up (y);
        x = y;
    }
    void merge (int &x , int a , int b) {
        if (!a || !b) x = a | b;
        else {
            if (priority[a] > priority[b]) {
                push_down (a);
                merge (child[a][1] , child[a][1] , b);
                x = a;
            }
            else {
                push_down (b);
                merge (child[b][0] , a , child[b][0]);
                x = b;
            }
            push_up (x);
        }
    }
    void split (int p , int &a , int &b , int k) {
        if (!k) {
            a = 0;
            b = p;
            return ;
        }
        if (size[p] == k) {
            a = p;
            b = 0;
            return ;
        }
        // cout << p << " " << k << " " << size[]endl;
        push_down (p);
        if (size[child[p][0]] >= k) {
            b = p;
            split (child[p][0] , a , child[b][0] , k);
            push_up (b);
        }
        else {
            a = p;
            split (child[p][1] , child[a][1] , b , k - size[child[a][0]] - 1);
            push_up (a);
        }
    }
    inline void insert (int k , int num) {
        int x , y , z;
        split (root , x , z , k);
        newnode (y , num);
        merge (x , x , y);
        merge (root , x , z);
    }
    inline void erase (int k) {
        int x , y , z;
        split (root , x , y , k - 1);
        split (y , y , z , 1);
        merge (root , x , z);
    }
    inline int query (int l , int r) {
        int x , y , z;
        split (root , x , y , l - 1);
        split (y , y , z , r - l + 1);
        int ans = mn[y];
        merge (x , x , y);
        merge (root , x , z);
        return ans;
    }
    inline void update (int l , int r , int v) {
        int x , y , z;
        split (root , x , y , l - 1);
        split (y , y , z , r - l + 1);
        mn[y] += v;add[y] += v;key[y] += v;
        merge (x , x , y);
        merge (root , x , z);
    }
    inline void reverse (int l , int r) {
        int x , y , z;
        split (root , x , y , l - 1);
        split (y , y , z , r - l + 1);
        rev[y] ^= 1;swap (child[y][0] , child[y][1]);
        merge (x , x , y);
        merge (root , x , z);
    }
    inline void revolve (int l , int r , int t) {
        int x , y , z;
        split (root , x , y , l - 1);
        split (y , y , z , r - l + 1);
        t %= (r - l + 1);
        int y1 , y2;
        split (y , y1 , y2 , (r - l + 1) - t);
        merge (y , y2 , y1);
        merge (x , x , y);
        merge (root , x , z);
    }
}treap;
int n , q;
int main () {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
#endif
    while (scanf ("%d" , &n) != EOF) {
        treap.clear ();
        for (int i = 0 ; i < n ; i ++) {
            int num;scanf ("%d" , &num);
            treap.insert (i , num);
        }
        scanf ("%d" , &q);
        while (q --) {
            char str[10];scanf ("%s" , str);
            if (str[0] == 'I') {
                int k , num;
                scanf ("%d %d" , &k , &num);
                treap.insert (k , num);
            }
            else if (str[0] == 'D') {
                int k;scanf ("%d" , &k);
                treap.erase (k);
            }
            else if (str[0] == 'M') {
                int l , r;scanf ("%d %d" , &l , &r);
                printf ("%d\n" , treap.query (l , r));
            }
            else if (str[0] == 'A') {
                int l , r , v;scanf ("%d %d %d" , &l , &r , &v);
                treap.update (l , r , v);
            }
            else if (str[3] == 'E') {
                int l , r;scanf ("%d %d" , &l , &r);
                treap.reverse (l , r);
            }
            else {
                int l , r , t;scanf ("%d %d %d" , &l , &r , &t);
                treap.revolve (l , r , t);
            }
        }
    }
    return 0;
}