#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
typedef long long LL;
const int inf = 1000005;
const int N = 10005;
struct Tree {
    int left , right;
    int angle , lazy;
    double x , y;
}L[N << 2];
int n , q , len[N] , leaf[N];
#define lson step << 1
#define rson step << 1 | 1
void push_up (int step) {
    L[step].x = L[lson].x + L[rson].x;
    L[step].y = L[lson].y + L[rson].y;
}
void update (int step , int l , int r , int val);
void push_down (int step) {
    int l = L[step].left , r = L[step].right , m = (l + r) >> 1;
    int &z = L[step].lazy;
    if (z) {
        update (lson , l , m , z);
        update (rson , m + 1 , r , z);
        z = 0;
    }
}
void build (int step , int l , int r) {
    L[step].left = l;
    L[step].right = r;
    L[step].lazy = 0;
    if (l == r) {
        L[step].angle = 90;
        L[step].x = 0;L[step].y = len[l];
        leaf[l] = step;
        return ;
    }
    int m = (l + r) >> 1;
    build (lson , l , m);
    build (rson , m + 1 , r);
    push_up (step);
}
double to (double angle) {
    double pi = acos (-1.0);
    return angle / 180.0 * pi;
}
void update (int step , int l , int r , int val) {
    if (L[step].left == l && L[step].right == r) {
        L[step].lazy = ((L[step].lazy + val) % 360 + 360) % 360;
        L[step].angle = ((L[step].angle + val) % 360 + 360) % 360;
        double x = L[step].x , y = L[step].y;
        L[step].x = x * cos (to (val)) - y * sin (to (val));
        L[step].y = y * cos (to (val)) + x * sin (to (val));
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
    push_up (step);
}
int query (int step , int pos) {
    if (L[step].left == pos && L[step].right == pos)
         return L[step].angle;
    push_down (step);
    int m = (L[step].left + L[step].right) >> 1;
    if (pos <= m) return query (lson , pos);
    else return query (rson , pos);
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int first = 1;
    while (scanf ("%d %d" , &n , &q) != EOF) {
        if (!first) puts ("");
        first = 0;
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d" , &len[i]);
        }
        build (1 , 1 , n);
        while (q --) {
            int s , a;
            scanf ("%d %d" , &s , &a);
            int A = query (1 , s) - 180 , B = query (1 , s + 1) , target = (A + a + 3600) % 360 ;
            int d = (target - B + 360) % 360;
            update (1 , s + 1 , n , d);
            printf ("%.2f %.2f\n" , L[1].x + 1e-8 , L[1].y + 1e-8);
        }
    }
    return 0;  
}