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
#include <stack>
#include <cmath>
using namespace std;
const int N = 1000000;
const int MOD = 1000000007;
struct SegTree {
    int left , right;
    int sum[4] , lazy[4];
}L[N << 2];
int q , two , six;
inline void add (int &a , int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}
inline int mut (int a , int b) {
    // cout << a << " " << b << endl;
    return 1LL * a * b % MOD;
}
inline int powmod (int a , int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return ret;
}
#define lson step << 1
#define rson step << 1 | 1
void build (int step , int l , int r) {
    L[step].left = l;
    L[step].right = r;
    memset (L[step].sum , 0 , sizeof (L[step].sum));
    memset (L[step].lazy , 0 , sizeof (L[step].lazy));
    if (l == r) return ;
    int m = (l + r) >> 1;
    build (lson , l , m);
    build (rson , m + 1 , r);
}
void update (int step , int l , int r , int *v);
void push_down (int step) {
    int l = L[step].left , r = L[step].right , m = (l + r) >> 1;
    int ok = 0;
    for (int i = 0 ; i < 4 ; i ++) {
        if (L[step].lazy[i]) {
            ok = 1;
        }
    }
    if (ok) {
        update (lson , l , m , L[step].lazy);
        update (rson , m + 1 , r , L[step].lazy);
        for (int i = 0 ; i < 4 ; i ++)
            L[step].lazy[i] = 0;
    }
}
// \sum {x^k}
inline int gao (int n , int k) {
    if (k == 0) return n;
    if (k == 1) return mut (mut (n , (n + 1)) , two);
    if (k == 2) return mut (n , mut (n + 1 , mut (2 * n + 1 , six)));
    return powmod (mut (mut (n , (n + 1)) , two) , 2);
}
//  \sum_{x=l}^{r}{p*x^k}
inline int gao (int l , int r , int p , int k) {
    return mut (p , ((gao (r , k) - gao (l - 1 , k)) % MOD + MOD) % MOD);
}
void update (int step , int l , int r , int *v) {
    if (L[step].left == l && L[step].right == r) {
        for (int i = 0 ; i < 4 ; i ++) {
            add (L[step].lazy[i] , v[i]);
            add (L[step].sum[i] , gao (l , r , v[i] , 3 - i));
        }
        return ;
    }
    push_down (step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) update (lson , l , r , v);
    else if (l > m) update (rson , l , r , v);
    else {
        update (lson , l , m , v);
        update (rson , m + 1 , r , v);
    }
    for (int i = 0 ; i < 4 ; i ++) {
        L[step].sum[i] = L[lson].sum[i];
        add (L[step].sum[i] , L[rson].sum[i]);
    }
}
int query (int step , int l , int r) {
    if (L[step].left == l && L[step].right == r) {
        int sum = 0;
        for (int i = 0 ; i < 4 ; i ++)
            add (sum , L[step].sum[i]);
        return sum;
    }
    push_down (step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) return query (lson , l , r);
    else if (l > m) return query (rson , l , r);
    else {
        int a = query (lson , l , m) , b = query (rson , m + 1 , r);
        add (a , b);
        return a;
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    two = powmod (2 , MOD - 2);
    six = powmod (6 , MOD - 2);
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d" , &q);
        build (1 , 0 , N - 1);
        printf ("Case #%d:\n" , ++ cas);
        while (q --) {
            char str[5];int x1 , x2 , a[4];
            scanf ("%s %d %d %d %d %d %d" , str , &x1 , &x2 , a + 0 , a + 1 , a + 2 , a + 3);
            for (int i = 0 ; i < 4 ; i ++) {
                a[i] = (a[i] % MOD + MOD) % MOD;
            }
            if (str[0] == 'p') {
                update (1 , x1 , x2 , a);
            }
            else {
                int ans = query (1 , x1 , x2);
                printf ("%d\n" , ans);
                int l = (ans * 1LL * x1) % N , r = (ans * 1LL * x2) % N;
                if (l > r) swap (l , r);
                update (1 , l , r , a);
            }
        }
    }
    return 0;
}