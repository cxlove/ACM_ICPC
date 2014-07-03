#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long LL ;
const int N = 100005;
struct Q {
    int l , r , id;
    void input(int _i) {
        id = _i;
        scanf ("%d %d" , &l , &r);
    }
    bool operator < (const Q &q) const {
        return l < q.l;
    }
}q[N];
int n , m , a[N];
int s[N] , pos[N];
void add (int x , int val) {
    for (int i = x ; i <= n ; i += lowbit(i))
        s[i] += val;
}
int sum (int x) {
    int ret = 0;
    for (int i = x ; i ; i -= lowbit(i)) 
        ret += s[i];
    return ret;
}
int ans[N];
int main () {
    // freopen ("input.txt" , "r" , stdin);
    int t  ;
    scanf ("%d" , &t);
    while (t --) {
        scanf ("%d %d" , &n , &m);
        for (int i = 1 ; i <= n ; i ++) 
            scanf ("%d" , &a[i]);
        for (int i = 0 ; i < m ; i ++) {
            q[i].input(i);
        }
        memset (s , 0 , sizeof(s));
        memset (pos , 0 , sizeof(pos));
        sort (q , q + m);
        int l = 1 , r = 0;
        for (int i = 0 ; i < m ; i ++) {
            if (q[i].r > r) {
                for (int j = r + 1 ; j <= q[i].r ; j ++) {
                    if (pos[a[j] - 1] && pos[a[j] + 1]) add (j , -1);
                    if (pos[a[j] - 1] == 0 && pos[a[j] + 1] == 0) add (j , 1);
                    pos[a[j]] = j;
                }
                r = q[i].r;
            }
            if (l < q[i].r) {
                for (int j = l ; j < q[i].l ; j ++) {
                    int u = pos[a[j] - 1] , v = pos[a[j] + 1];
                    if (u == 0 && v == 0) add (j , -1);
                    else {
                        if (u > v) swap (u , v);
                        if (u == 0) {
                            add (j , -1);
                            add (v , 1);
                        }
                        else {
                            add (j , -1);
                            add (u , 1);
                            add (v , 1);
                        }
                    }
                    pos[a[j]] = 0;
                }
                l = q[i].l;
            }
            ans[q[i].id] = sum (q[i].r);
        }
        for (int i = 0 ; i < m ; i ++)
            printf ("%d\n" , ans[i]);
    }
    return 0;
}