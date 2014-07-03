#include <iostream>
#include <cstdio>
#include <queue>
#include <set>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long LL;
const int N = 50001;
struct Query {
    int l , r , id;
    void input(int _i) {
        id = _i;
        scanf ("%d %d" , &l , &r);
    }
    bool operator < (const Query &q) const {
        return r < q.r;
    }
}que[N];
int n , a[N] , q;
int r[N] , ans[N] , pre[N];
vector <int> divisior[N];
void update (int x , int val) {
    for (int i = x ; i <= n ; i += lowbit(i))
        r[i] = max (r[i] , val);
}
int ask (int x) {
    int ret = 0;
    for (int i = x ; i > 0 ; i -= lowbit(i))
        ret = max (ret , r[i]);
    return ret;
}
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int t ;
    scanf ("%d" , &t);
    for (int i = 1 ; i < N ; i ++) {
        for (int j = 1 ; j * j <= i ; j ++) {
            if (i % j == 0){
                divisior[i].push_back(j);
                if (j * j != i)
                    divisior[i].push_back(i / j);
            }
        }
    }
    while (t --) {
        scanf ("%d", &n);
        for (int i = 1 ; i <= n ; i ++)
            scanf ("%d" , &a[i]);
        scanf ("%d" , &q);
        for (int i = 0 ; i < q ; i ++) {
            que[i].input(i);
        }
        for (int i = 1 ; i <= n ; i ++) {
            r[i] = pre[i] = 0;
        }
        que[q].r = 0;
        sort (que , que + q + 1); 
        for (int i = 1 ; i <= q ; i ++) {
            for (int j = que[i - 1].r + 1 ; j <= que[i].r ; j ++) {
                int m = a[j];
                for (int k = 0 ; k < divisior[m].size() ; k ++) {
                    int v = divisior[m][k];
                    if (pre[v]) update(n - pre[v] + 1 , v);
                    pre[v] = j;
                }
            }
            ans[que[i].id] = ask (n - que[i].l + 1);
        }
        for (int i = 0 ; i < q ; i ++)
            printf ("%d\n" , ans[i]);
    }    
    return 0;
}