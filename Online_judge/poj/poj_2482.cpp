#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson step << 1
#define rson step << 1 | 1
using namespace std;
typedef long long LL;
const int N = 10005;
struct Point {
    int x , y , r;
    void input () {
        scanf ("%d %d %d" , &x , &y , &r);
    }
    bool operator < (const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
}p[N];
struct Seg_tree {
    int left , right , lazy , mx;
}L[N << 2];
int n , w , h , y[N] , m;
int id (int k) {
    return lower_bound (y , y + m , k) - y + 1;
}
void bulid (int step , int l , int r) {
    L[step].left = l;
    L[step].right = r;
    L[step].lazy = L[step].mx = 0;
    if (l == r) return ;
    int m = (l + r) >> 1;
    bulid (lson , l , m);
    bulid (rson , m + 1 , r);
}
void update (int step , int l , int r , int val) ;
void push_down (int step) {
    int l = L[step].left , r = L[step].right , m = (l + r) >> 1;
    int lazy = L[step].lazy;
    if (lazy) {
        update (lson , l , m , lazy);
        update (rson , m + 1 , r , lazy);
        L[step].lazy = 0;
    }
}
void update (int step , int l , int r , int val) {
    if (l > r) return ;
    if (L[step].left == l && L[step].right == r) {
        L[step].lazy += val;
        L[step].mx += val;
        return ;
    }
    push_down (step);
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) update (lson , l , r , val);
    else if (l > m) update (rson , l , r ,val);
    else {
        update (lson , l , m , val);
        update (rson , m + 1 , r , val);
    }
    L[step].mx = max (L[lson].mx , L[rson].mx);
}
int main () {
    // freopen ("input.txt" , "r" , stdin);
    while (scanf ("%d %d %d" , &n , &w , &h) != EOF) {
        int ans = 0;
        for (int i = 0 ; i < n ; i ++) {
            p[i].input();
            y[i] = p[i].y;
        }
        // if (w * h == 0) {
        //     puts ("0");
        //     continue;
        // } 
        sort (p , p + n);
        sort (y , y + n);
        m = unique (y , y + n) - y;
        bulid (1 , 1 , m);
        for (int i = 0 , j = 0 ; i < n ; i ++) {
            update (1 , id (p[i].y - h + 1) , id (p[i].y) , p[i].r);
            while (j < n && p[i].x - p[j].x >= w) {
                update (1 , id (p[j].y - h + 1) , id (p[j].y) , -p[j].r);
                j ++;
            }
            ans = max (ans , L[1].mx);
        }
        printf ("%d\n" , ans);
    }
    return 0;
}
