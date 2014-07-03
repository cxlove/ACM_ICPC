#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define lowbit(x) ((x) & (-(x)))
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const int N = 200005;
struct Query {
    int l , r , id;
    void input (int i) {
        id = i;
        scanf ("%d %d" , &l , &r);
    }
    bool operator < (const Query &q) const {
        return l < q.l;
    }
}q[N];
int n , m , a[N] , s[N];
int flag[N] , prime[N] , cnt , minfac[N];
int fac[N][20] , p[N] , l[N] , r[N];
vector <int> pos[N];
void Init () {
    for (int i = 2 ; i < N ; i ++) {
        if (!flag[i]) {
            prime[cnt ++] = i;
            minfac[i] = i;
        }
        for (int j = 0 ; j < cnt && prime[j] * i < N ; j ++) {
            flag[i * prime[j]] = 1;
            minfac[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
    // minfac[1] = 1;
    // fac[1][0] = 1;fac[1][1] = 1;
    for (int i = 2 ; i < N ; i ++) {
        fac[i][0] = 0;
        int m = i;
        while (m != 1) {
            fac[i][++ fac[i][0]] = minfac[m];
            m /= minfac[m];
        }
    }
}
void add (int idx , int v) {
    // cout << "update : " << idx << " " << v << endl;
    for (int i = idx ; i <= n ; i += lowbit (i)) 
        s[i] += v;
}
int sum (int idx) {
    int ret = 0;
    for (int i = idx ; i > 0 ; i -= lowbit (i))
        ret += s[i];
    return ret;
}
int ans[N];
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    Init ();
    while (scanf ("%d %d" , &n , &m) != EOF && n + m) {
        for (int i = 1 ; i <= n ; i ++)
            scanf ("%d" , &a[i]);
        for (int i = 0 ; i < N ; i ++)
            pos[i].clear ();
        memset (p , 0 , sizeof(p));
        for (int i = 1 ; i <= n ; i ++) {
            int idx = 0;
            for (int j = 1 ; j <= fac[a[i]][0] ; j ++)
                idx = max (idx , p[fac[a[i]][j]]);
            for (int j = 1 ; j <= fac[a[i]][0] ; j ++)
                p[fac[a[i]][j]] = i;
            l[i] = idx;
            pos[idx].push_back (i);
        }
        memset (p , 0x11 , sizeof(p));
        for (int i = n ; i > 0 ; i --) {
            int idx = n + 1;
            for (int j = 1 ; j <= fac[a[i]][0] ; j ++)
                idx = min (idx , p[fac[a[i]][j]]);
            for (int j = 1 ; j <= fac[a[i]][0] ; j ++)
                p[fac[a[i]][j]] = i;
            r[i] = idx;
        }
        for (int i = 0 ; i < m ; i ++)
            q[i].input (i);
        sort (q , q + m);
        memset (s , 0 , sizeof(s));
        for (int i = 1 ; i <= n ; i ++) {
            if (l[i] < 1) {
                add (i , 1);
                if (r[i] <= n)
                    add (r[i] , -1);
            }
        }
        int left = 1;
        for (int i = 0 ; i < m ; i ++) {
            while (left < q[i].l) {
                add (left , -1);
                if (r[left] <= n) add (r[left] , 1);
                for (int j = 0 ; j < pos[left].size() ; j ++) {
                    add (pos[left][j] , 1);
                    if (r[pos[left][j]] <= n) add (r[pos[left][j]] , -1);
                }
                left ++;
            }
            ans[q[i].id] = sum (q[i].r) - sum (q[i].l - 1);
            // cout << q[i].id << " " << ans[q[i].id] << " " << left << endl;
        }
        for (int i = 0 ; i < m ; i ++)
            printf ("%d\n" , ans[i]);
    }
    return 0;
}