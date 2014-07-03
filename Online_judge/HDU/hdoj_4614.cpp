#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#define lson step << 1
#define rson step << 1 | 1
using namespace std;
const int N = 50005;
struct Node{
    int left , right;
    int cnt , cover ;
}L[N << 2];
int n , m ;
void bulid (int step , int l , int r) {
    L[step].left = l;
    L[step].right = r;
    L[step].cnt = 0;
    L[step].cover = -1;
    if (l == r) return ;
    int m = (l + r) >> 1;
    bulid (lson , l , m);
    bulid (rson , m + 1 , r );
}
void push_up (int step) {
    L[step].cnt = L[lson].cnt + L[rson].cnt;
}
void update (int step , int l , int r , int val);
void push_down (int step) {
    int l = L[step].left , r = L[step].right , m = (l + r) >> 1;
    if (L[step].cover != -1) {
        update (lson , l , m , L[step].cover);
        update (rson , m + 1 , r , L[step].cover);
        L[step].cover = -1;
    }
}
int query (int step , int l , int r) {
    if (L[step].left == l && L[step].right == r) {
        return L[step].cnt;
    }
    push_down(step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) return query(lson , l , r);
    else if(l > m) return query(rson , l , r);
    else return query(lson , l , m) + query (rson , m + 1 , r);
}
int query_left (int step , int l , int r) {
    if (L[step].cnt == L[step].right - L[step].left + 1) return -1; 
    if (L[step].left == L[step].right) 
        return L[step].left;
    push_down(step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) return query_left (lson , l , r);
    else if (l > m) return query_left (rson , l , r);
    else {
        int p = query_left (lson , l , m);
        if (p != -1) return p;
        return query_left (rson , m + 1 , r);
    }
}
void update (int step , int l , int r , int val) {
    if (L[step].left == l && L[step].right == r) {
        if (val == 0)  L[step].cnt = 0;
        else L[step].cnt = r - l + 1;
        L[step].cover = val;
        return ;
    }
    push_down(step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) update (lson , l , r , val);
    else if (l > m) update (rson , l , r , val);
    else {
        update (lson , l , m , val);
        update (rson , m + 1 , r ,val);
    }
    push_up (step);
}
int query_pos (int step , int l , int r , int val) {
    if (L[step].right - L[step].left + 1 - L[step].cnt < val) return -1;
    if (L[step].left == L[step].right) {
        return L[step].left;
    }
    push_down(step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) return query_pos (lson , l , r ,val);
    else if( l > m )return query_pos (rson , l , r, val);
    else {
        int p = query_pos(lson , l , m , val);
        if (p != -1) return p;
        val -= m - l + 1 - query(lson , l , m);
        return query_pos(rson , m + 1 , r , val);
    }
}
int main () {
    #ifndef ONLINE_JUDGE
         freopen("input.txt","r",stdin);
    #endif
    int t;
    scanf ("%d", &t);
    while (t --) {
        scanf ("%d%d", &n, &m);
        bulid (1 , 1 , n);
        while (m --) {
            int k , p , v;
            scanf ("%d %d %d" , &k , &p , &v);
            if (k == 1) {
                p ++ ;
                int cnt = (n + 1 - p) - query (1 , p , n);
                if (v > cnt) v = cnt;
                if (v == 0) puts ("Can not put any one.");
                else {
                    int l = query_left (1 , p , n) , r = query_pos (1 , p , n , v);
                    printf ("%d %d\n" , l - 1 , r - 1);
                    update ( 1 , l ,r , 1);
                }
            }
            else {
                p++;v++;
                printf ("%d\n", query(1 , p , v));
                update (1 , p , v , 0);
            }
        }
        puts ("");
    }
    return 0;
}        

