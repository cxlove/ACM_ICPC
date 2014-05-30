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
typedef long long LL;
const int N = 200005;
const int HASH = 1000000007;
struct SegTree {
    int left , right;
    set <pair <int , int> > s; 
}L[N << 2];
vector <int> update;
int n , q , w , h , x[N] , y[N];
#define lson step << 1
#define rson step << 1 | 1
void build (int step , int l , int r) {
    L[step].left = l;L[step].right = r;
    L[step].s.clear ();
    if (l == r) return;
    int m = (l + r) >> 1;
    build (lson , l , m);
    build (rson , m + 1 , r);
}
void add (int step , int x , int y , int id) {
    L[step].s.insert (make_pair (y , id));
    if (L[step].left == L[step].right) return;
    int m = (L[step].left + L[step].right) >> 1;
    if (x <= m) add (lson , x , y , id);
    else add (rson , x , y , id);
}
void del (int step , int x , int y , int id) {
    L[step].s.erase (make_pair (y , id));
    if (L[step].left == L[step].right) return;
    int m = (L[step].left + L[step].right) >> 1;
    if (x <= m) del (lson , x , y , id);
    else del (rson , x , y , id);
}
void query (int step , int l , int r , int d , int u) {
    set <pair <int , int> > :: iterator it = L[step].s.lower_bound (make_pair (d , -1));
    if (it == L[step].s.end () || (*it).first > u) return ;
    if (L[step].left == l && L[step].right == r) {
        while (it != L[step].s.end () && (*it).first <= u) {
            update.push_back ((*it).second);
            it ++;
        }
        return;
    }
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) query (lson , l , r , d , u);
    else if (l > m) query (rson , l , r , d , u);
    else {
        query (lson , l , m , d , u);
        query (rson , m + 1 , r , d , u);
    }
}
void get (int x , int y , int a , int b , int c , int d , int e , int f , int id , int &X , int &Y) {
    X = (1LL * x * a + 1LL * y * b + 1LL * id * c) % w;
    Y = (1LL * x * d + 1LL * y * e + 1LL * id * f) % h;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen ("input.txt" , "r" , stdin);
    // freopen ("output.txt" , "w" , stdout);
#endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d %d %d" , &n , &q , &w , &h);
        build (1 , 0 , 2 * w);
        for (int i = 0 ; i < n ; i ++) {
            scanf ("%d %d" , &x[i] , &y[i]);
            add (1 , x[i] + y[i] , x[i] - y[i] , i);
        }
        while (q --) {
            int X , Y , D , a , b , c , d , e , f;
            scanf ("%d %d %d %d %d %d %d %d %d" , &X , &Y , &D , &a , &b , &c , &d , &e , &f);
            update.clear ();
            query (1 , max (0 , X + Y - D) , min (2 * w , X + Y + D) , X - Y - D , X - Y + D);
            for (int i = 0 ; i < update.size() ; i ++) {
                int id = update[i];                
                del (1 , x[id] + y[id] , x[id] - y[id] , id);
            }
            for (int i = 0 ; i < update.size() ; i ++) {
                int id = update[i];
                get (x[id] , y[id] , a , b , c , d , e , f , id + 1 , X , Y);
                add (1 , X + Y , X - Y , id);
                x[id] = X;y[id] = Y;
            }
        }
        printf ("Case #%d:\n" , ++ cas);
        for (int i = 0 ; i < n ; i ++) {
            printf ("%d %d\n" , x[i] , y[i]);
        }
    }
    return 0;
}