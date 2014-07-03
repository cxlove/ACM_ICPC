#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson step << 1
#define rson step << 1 | 1
using namespace std;
typedef long long LL;
const int N = 100005;
const int MOD = 10007;
struct Seg_tree {
    int left , right;
    int one , two , three;
    int add , cover , mut;
    int cnt () {
        return right - left + 1;
    }
    void init () {
        one = two = three = add = cover = 0;
        mut = 1;
    }
}L[N << 2];
int n , q;
void bulid (int step , int l , int r) {
    L[step].left = l;
    L[step].right = r;
    L[step].init();
    if (l == r) return ;
    int m = (l + r) >> 1;
    bulid (lson , l , m);
    bulid (rson , m + 1 , r);
}
void push_up (int step) {
    L[step].one = (L[lson].one + L[rson].one) % MOD;
    L[step].two = (L[lson].two + L[rson].two) % MOD;
    L[step].three = (L[lson].three + L[rson].three) % MOD;
}
void add (int step , int l , int r , int val) ;
void mut (int step , int l , int r , int val) ;
void cover (int step , int l , int r , int val) ;
void push_down (int step) {
    int l = L[step].left , r = L[step].right , m = (l + r) >> 1;
    if (L[step].cover) {
        cover (lson , l , m , L[step].cover);
        cover (rson , m + 1 , r , L[step].cover);
        L[step].cover = 0;
    }
    if (L[step].mut != 1) {
        mut (lson , l , m , L[step].mut);
        mut (rson , m + 1 , r , L[step].mut);
        L[step].mut = 1;
    }
    if (L[step].add) {
        add (lson , l , m , L[step].add);
        add (rson , m + 1 , r , L[step].add);
        L[step].add = 0;
    }
}
int mut (int a , int b) {
    return (LL) a * b % MOD;
}
int mut (int a , int b , int c) {
    return mut (a , mut (b , c));
}
void add (int step , int l , int r , int val) {
    if (L[step].left == l && L[step].right == r) {
        val %= MOD;
        L[step].add = (L[step].add + val) % MOD;
        int one = L[step].one , two = L[step].two , three = L[step].three;
        L[step].one = (one + (LL)L[step].cnt() * val) % MOD;
        L[step].two = (two + 2LL * val * one + (LL)mut(val , val) * L[step].cnt()) % MOD;
        L[step].three = (three + 3LL * val * val * one + 3LL * val * two + (LL)mut(val , val , val) * L[step].cnt()) % MOD;
        return ;
    }
    push_down (step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) add (lson , l , r , val);
    else if (l > m) add (rson , l , r , val);
    else {
        add (lson , l , m , val);
        add (rson , m + 1 , r , val);
    }
    push_up (step);
}
void mut (int step , int l , int r , int val) {
    if (L[step].left == l && L[step].right == r) {
        val %= MOD;
        L[step].add = ((LL)L[step].add * val) % MOD;
        L[step].mut = ((LL)L[step].mut * val) % MOD;
        int one = L[step].one , two = L[step].two , three = L[step].three;
        L[step].one = ((LL)one * val) % MOD;
        L[step].two = ((LL)two * mut(val , val)) % MOD;
        L[step].three = ((LL)three * mut(val , val , val)) % MOD;
        return ;
    }
    push_down (step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) mut (lson , l , r , val);
    else if (l > m) mut (rson , l , r , val);
    else {
        mut (lson , l , m , val);
        mut (rson , m + 1 , r , val);
    }
    push_up (step);
}
void cover (int step , int l , int r , int val) {
    if (L[step].left == l && L[step].right == r) {
        val %= MOD;
        L[step].add = 0;
        L[step].mut = 1;
        L[step].cover = val;
        int one = L[step].one , two = L[step].two , three = L[step].three;
        L[step].one = ((LL)val * L[step].cnt()) % MOD;
        L[step].two = ((LL)mut(val , val) * L[step].cnt()) % MOD;
        L[step].three = ((LL)mut(val , val , val) * L[step].cnt()) % MOD;
        return ;
    }
    push_down (step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) cover (lson , l , r , val);
    else if (l > m) cover (rson , l , r , val);
    else {
        cover (lson , l , m , val);
        cover (rson , m + 1 , r , val);
    }
    push_up (step);
}
int query (int step , int l , int r , int p) {
    if (L[step].left == l && L[step].right == r) {
        if (p == 1) return L[step].one;
        else if (p == 2) return L[step].two;
        return L[step].three;
    }
    push_down(step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) return query (lson , l , r , p);
    else if (l > m) return query (rson , l , r , p);
    else return (query (lson , l , m , p) + query (rson , m + 1 , r ,p)) % MOD;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    while (scanf ("%d %d" , &n , &q) != EOF) {
        if (!n && !q) break;
        bulid (1 , 1 , n);
        while (q --) {
            int k , x , y , c;
            scanf ("%d %d %d %d" , &k , &x , &y , &c);
            if (k == 1) {
                add (1 , x , y , c);
            }
            else if (k == 2) {
                mut (1 , x , y , c);
            }
            else if (k == 3) {
                cover (1 , x , y , c);
            }
            else printf ("%d\n" , query (1 , x , y , c));
        }
    }
    return 0;
}