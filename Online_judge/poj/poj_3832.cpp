#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson step << 1
#define rson step << 1 | 1
using namespace std;
typedef long long LL;
const int N = 100005;
struct Scan_line {
    int y , x1 , x2 , f;
    Scan_line () {}
    Scan_line (int _y , int _x1 , int _x2 , int _f):y(_y) , x1(_x1) , x2(_x2) , f(_f) {}
    bool operator < (const Scan_line &s) const {
        return y != s.y ? y < s.y : f < s.f;
    } 
}line[N << 3];
int n  , x[N << 2] , m;
struct Seg_tree {
    int left , right;
    int len;
    int cover ;
}L[N << 4];
void bulid (int step , int l , int r) {
    L[step].left = l ;
    L[step].right = r;
    L[step].len = L[step].cover = 0;
    if (l == r) return ;
    int m = (l + r) >> 1;
    bulid (lson , l , m);
    bulid (rson , m + 1 , r);
}
int get (int l , int r) {
    return x[r] - x[l - 1];
}
void push_up (int step) {
    if (L[step].cover) L[step].len = get (L[step].left , L[step].right);
    else if (L[step].left == L[step].right) L[step].len = 0;
    else L[step].len = L[lson].len + L[rson].len;
}
void update (int step , int l , int r , int val) {
    if (l > r) return;
    if (L[step].left == l && L[step].right == r) {
        L[step].cover += val;
        push_up (step);
        return ;
    }
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) update (lson , l , r , val);
    else if (l > m) update (rson , l , r , val);
    else {
        update (lson , l , m , val);
        update (rson , m + 1 , r , val);
    }
    push_up (step);
} 
void debug (int step) {
    int l = L[step].left , r = L[step].right , m = (l + r) >> 1;
    printf ("%d %d %d %d \n" , l , r , L[step].cover , L[step].len);
    if (l != r) {
        debug (lson);
        debug (rson);
    }
}
int main () {
    // freopen ("input.txt" , "r" , stdin);
    while (scanf ("%d" , &n) != EOF && n) {
        m = 0;
        for (int i = 0 ; i < n ; i ++) {
            int x1 , x2 , x3 , x4 , y1 , y2 , y3 , y4;
            scanf ("%d %d %d %d %d %d %d %d" , &x1 , &y1 , &x2 , &y2 , &x3 , &y3 , &x4 , &y4);
            x[m ++] = x1;x[m ++] = x2;x[m ++] = x3;x[m ++] = x4;
            line[i << 3 | 0] = Scan_line (y1 , x1 , x3 , 1);
            line[i << 3 | 1] = Scan_line (y2 , x1 , x3 , -1);
            line[i << 3 | 2] = Scan_line (y1 , x3 , x4 , 1);
            line[i << 3 | 3] = Scan_line (y3 , x3 , x4 , -1);
            line[i << 3 | 4] = Scan_line (y1 , x4 , x2 , 1);
            line[i << 3 | 5] = Scan_line (y2 , x4 , x2 , -1);
            line[i << 3 | 6] = Scan_line (y4 , x3 , x4 , 1);
            line[i << 3 | 7] = Scan_line (y2 , x3 , x4 , -1);
        }
        sort (line , line + (n << 3));
        sort (x , x + m);
        m = unique (x , x + m) - x;
        for (int i = 0 ; i < (n << 3) ; i ++) {
            line[i].x1 = lower_bound (x , x + m , line[i].x1) - x + 1;
            line[i].x2 = lower_bound (x , x + m , line[i].x2) - x;
        }
        LL ans = 0;
        bulid (1 , 1 , m - 1);
        for (int i = 0 ; i < (n << 3) ; i ++) {
            if (i) ans += (LL)(line[i].y - line[i - 1].y) * L[1].len;
            // debug (1);
            // cout << "update : " << line[i].y << " " << line[i].x1 << " " << line[i].x2 << " " << line[i].f << endl;
            // cout << ans << endl;
            update (1 , line[i].x1 , line[i].x2 , line[i].f);
        }
        printf ("%I64d\n" , ans);
    }
    return 0;
}
