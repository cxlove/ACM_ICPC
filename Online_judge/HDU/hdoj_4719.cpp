#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#define lson step << 1
#define rson step << 1 | 1
using namespace std;
typedef long long LL;
const int N = 100005;
const LL inf = -1000000005;
struct Node {
    int pos;
    LL val;
    Node () {}
    Node (int _p , LL _v) :pos(_p) , val (_v) {}
    bool operator < (const Node n) const {
        return val != n.val ? val < n.val : pos > n.pos;
    }
};
struct Seg_tree {
    int left , right;
    LL mx;
}L[N << 2];
int n , l , h[N];
LL dp[N];
priority_queue<Node> que[N];
void bulid (int step , int l , int r) {
    L[step].left = l;
    L[step].right = r;
    L[step].mx = inf;
    if (l == r) return;
    int m = (l + r) >> 1;
    bulid (lson , l , m);
    bulid (rson , m + 1 , r);
}
LL query (int step , int l , int r) {
    if (r < 1) return inf;
    if (l > r) return inf;
    if (L[step].left == l && L[step].right == r) 
        return L[step].mx;
    int m = (L[step].left + L[step].right) >> 1;
    if (r <= m) return query (lson , l , r);
    else if (l > m) return query (rson , l , r);
    else return max (query (lson , l , m) , query (rson , m + 1 , r));
}
void update (int step , int pos , LL v) {
    if (L[step].left == L[step].right) {
        L[step].mx = v;
        return ;
    }
    int m = (L[step].left + L[step].right) >> 1;
    if (pos <= m) update (lson , pos , v);
    else update (rson , pos , v);
    L[step].mx = max (L[lson].mx , L[rson].mx);
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &n , &l);
        bulid (1 , 1 , 100000);
        for (int i = 1 ; i < N ; i ++) {
            while (!que[i].empty ())
                que[i].pop ();
        }
        for (int i = 1 ; i <= n ; i ++)
            scanf ("%d" , &h[i]);
        for (int i = 1 ; i <= n ; i ++) {
            LL ret = query (1 , 1 , h[i] - 1);
            dp[i] = inf;
            if (i <= l) dp[i] = 1LL * h[i] * h[i];
            if (ret != inf) dp[i] = max (dp[i] , (ret + 1LL * h[i] * h[i]));
            if (que[h[i]].empty () || que[h[i]].top().val < dp[i] - h[i]) 
                update (1 , h[i] , dp[i] - h[i]);
            que[h[i]].push (Node (i , dp[i] - h[i]));
            if (i > l) {
                while (!que[h[i - l]].empty() && que[h[i - l]].top().pos <= i - l)
                    que[h[i - l]].pop();
                if (que[h[i - l]].empty ()) update (1 , h[i - l] , inf);
                else update (1 , h[i - l] , que[h[i - l]].top().val);
            }
        }
        if (dp[n] == inf) printf ("Case #%d: No solution\n" , ++cas);
        else printf ("Case #%d: %I64d\n" , ++cas , dp[n]);
    }
    return 0;
}