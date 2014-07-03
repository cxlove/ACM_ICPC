#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson step << 1
#define rson step << 1 | 1
using namespace std;
typedef long long LL;
const int N = 60005;
struct Point {
    int x , y , z;
    void input () {
        scanf ("%d %d" , &x , &y);
    }
};
struct Spot {
    Point a , b;
    void input () {
        a.input();b.input();
        a.z = 0;
    }
}p[N];
struct Line {
    int y , x1 , x2 , f;
    Line () {}
    Line (int _y , int _x1 , int _x2 , int _f):y(_y) , x1(_x1) , x2(_x2) , f(_f){}
    bool operator < (const Line &l) const {
        return y < l.y;
    }
}line[N << 1];
struct Seg_tree {
    int left , right , cover;
    int len ;
}L[N << 3];
int n , cntx , cntz , x[N << 1] , z[N << 1] , m , val[N];
void bulid (int step , int l , int r) {
    L[step].left = l;
    L[step].right = r;
    L[step].len = L[step].cover = 0;
    if (l == r) return ;
    int m = (l + r) >> 1;
    bulid (lson , l , m);
    bulid (rson , m + 1 , r);
}
void push_up (int step) {
    int l = L[step].left , r = L[step].right; 
    if (L[step].cover) {
        L[step].len = x[r] - x[l - 1];
    }
    else {
        if (l == r) L[step].len = 0;
        else L[step].len = L[lson].len + L[rson].len;
    }
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
int main () {
    // freopen ("input.txt" , "r" , stdin);
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        cntx = cntz = 0;
        scanf ("%d %d" , &n , &m);
        for (int i = 0 ; i < m ; i ++)
            scanf ("%d" , &val[i]);
        for (int i = 0 ; i < n ; i ++) {
            p[i].input();
            int k;scanf ("%d" , &k);
            p[i].b.z = val[k - 1];
            x[cntx ++] = p[i].a.x;z[cntz ++] = p[i].a.z;
            x[cntx ++] = p[i].b.x;z[cntz ++] = p[i].b.z;
        }
        sort (x , x + cntx);
        sort (z , z + cntz);
        cntx = unique (x , x + cntx) - x;
        cntz = unique (z , z + cntz) - z;
        for (int i = 0 ; i < n ; i ++) {
            p[i].a.x = lower_bound (x , x + cntx , p[i].a.x) - x + 1;
            p[i].b.x = lower_bound (x , x + cntx , p[i].b.x) - x;
        }
        LL volume = 0LL;
        for (int i = 0 ; i < cntz - 1 ; i ++) {
            int cnt = 0;
            LL area = 0LL;
            for (int j = 0 ; j < n ; j ++) {
                if (p[j].a.z <= z[i] && p[j].b.z > z[i]) {
                    line[cnt ++] = Line (p[j].a.y , p[j].a.x , p[j].b.x , 1);
                    line[cnt ++] = Line (p[j].b.y , p[j].a.x , p[j].b.x , -1);
                }
            }
            sort (line , line + cnt);
            bulid (1 , 1 , cntx - 1);
            for (int j = 0 ; j < cnt ; j ++) {
                if (j) area += (LL)(line[j].y - line[j - 1].y) * L[1].len;
                update (1 , line[j].x1 , line[j].x2 , line[j].f);
            }
            volume += area * 1LL * (z[i + 1] - z[i]);
        }
        printf ("Case %d: %I64d\n" , ++ cas , volume);
    }
    return 0;
}