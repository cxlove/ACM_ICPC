#include <iostream>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const int N = 200005;
const int M = 10000005;
struct Edge{
    int v,next,k;
}e[N];
int start[N], totaledge;
int T[M], lson[M], rson[M], lcnt[M], rcnt[M];
int w[N], n, tot, m, x[N], cnt;
queue<int> que;
void add(int u,int v,int k){
    e[totaledge].v = v;
    e[totaledge].k = k;
    e[totaledge].next = start[u];
    start[u] = totaledge ++;
}
int bulid (int l ,int r){
    int root = tot ++;
    lcnt[root] = rcnt[root] = 0;
    if(l == r){
        lcnt[root] = rcnt[root] = 0;
        return root;
    }
    int m = (l + r) >> 1;
    lson[root] = bulid(l , m);
    rson[root] = bulid(m + 1 , r);
    lcnt[root] = lcnt[lson[root]] + lcnt[rson[root]];
    rcnt[root] = rcnt[lson[root]] + rcnt[rson[root]];
    return root;
}
int update(int root,int l,int r, int pos, int lval, int rval) {
    int newroot = tot ++;
    lcnt[newroot] = rcnt[newroot] = 0;
    // cout << l << " " << r << " " << pos << endl; 
    if(pos == l && pos == r){
        lcnt[newroot] = lcnt[root] + lval;
        rcnt[newroot] += rcnt[root] + rval;
        return newroot;
    }
    int m = (l + r) >> 1;
    if(pos <= m) {
        lson[newroot] = update(lson[root], l, m, pos, lval, rval);
        rson[newroot] = rson[root];
    }
    else {
        rson[newroot] = update(rson[root], m + 1, r, pos, lval, rval);
        lson[newroot] = lson[root];
    }
    lcnt[newroot] = lcnt[lson[newroot]] + lcnt[rson[newroot]];
    rcnt[newroot] = rcnt[lson[newroot]] + rcnt[rson[newroot]];
    return newroot;
}
int query(int root,int L,int R, int l,int r, int k){
    if (l > r ) return 0;
    if (l >= cnt) return 0;
    if (r < 0 ) return 0;
    if(L == l && R == r) {
        if(k == 0) return lcnt[root];
        return rcnt[root];
    }
    int m = (L + R) >> 1;
    if(r <= m) return query(lson[root], L, m, l, r, k);
    else if(l > m) return query(rson[root], m + 1, R, l, r, k);
    else return query(lson[root], L ,m , l , m, k) + query(rson[root], m + 1, R, m + 1 ,r, k);
}
int main() {
    int t;
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    scanf ("%d", &t);
    while (t--) {
        tot = 0;
        totaledge = 0;
        memset (start , -1 , sizeof(start));
        scanf ("%d", &n);
        for (int i = 1 ; i <= n ; i ++) {
            scanf ("%d", &w[i]);
            x[i - 1] = w[i];
        }
        sort (x, x+n);
        cnt = unique(x, x + n) - x;
        x[cnt] = -1;
        T[1] = bulid(0, cnt - 1);
        scanf ("%d", &m);
        for (int i = 0 ; i < m ; i++){
            int u , a , b;
            scanf("%d%d%d", &u, &a, &b);
            add(u , a, 0);
            add(u , b, 1);
        }
        que.push(1);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i = start[u] ; i != -1 ; i = e[i].next) {
                int v = e[i].v, k = e[i].k;
                T[v] = update(T[u], 0, cnt - 1, lower_bound(x, x + cnt , w[u]) - x , k == 0 , k == 1);
                que.push(v);
            }
        }
        int q;
        scanf ("%d", &q);
        while(q --){
            int num, v;
            scanf ("%d%d", &v, &num);
            if(v == 1){
                printf("0 0\n");
                continue;
            }
            int p = lower_bound(x, x + cnt , num) - x;
            int l = p - 1 , r = p ;
            if(x[p] == num){
                int ret = query(T[v], 0 , cnt - 1, p, p, 0) + query(T[v], 0 , cnt - 1 , p, p, 1);
                if(ret){
                    puts("0");
                    continue;
                }
                r ++ ;
            }
            int left_small = query(T[v],0 , cnt - 1, 0, l, 0);
            int left_large = query(T[v],0 , cnt - 1, r , cnt - 1, 0);
            int right_small = query(T[v],0 , cnt - 1, 0, l, 1);
            int right_large = query(T[v],0 , cnt - 1, r , cnt - 1, 1);
            int down = 0, up = 0;
            // cout<<left_small<<" "<<left_large<<" "<<right_small<<" "<<right_large<<endl;
            down += left_small * 3;
            down += left_large;
            down += right_small * 3;
            up += right_small;
            down += right_large;
            printf("%d %d\n",up,down);
        }
    }
    return 0;
}   