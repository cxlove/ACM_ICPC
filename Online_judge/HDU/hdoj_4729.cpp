#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
#pragma comment(linker, "/STACK:1024000000,1024000000")    
using namespace std;
typedef long long LL;
const int N = 110005;
const int M = 2000000;
struct Edge {
    int v , w , next;
}edge[N << 1];
int n , q;
int start[N] , tot;
void _add (int u , int v , int w) {
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].next = start[u];
    start[u] = tot ++;
}
void add (int u , int v , int w) {
    _add (u , v , w);
    _add (v , u , w);
}
int depth , b[N << 1] , cnt , p[N] , f[N]; 
int x[N] , m;
int T[M] , num[M] , sum[M] , nodecnt , lson[M] , rson[M];
void Init_hash () {
    sort (x , x + n - 1);
    m = unique (x , x + n - 1) - x;
} 
int hash (int y) {
    return y;
    return lower_bound (x , x + m , y) - x + 1;
}
int bulid (int l , int r) {
    int root = nodecnt ++;
    num[root] = 0;
    sum[root] = 0;
    if (l != r) {
        int mid = (l + r) >> 1;
        lson[root] = bulid (l , mid);
        rson[root] = bulid (mid + 1 , r);
    }
    return root;
}
int update (int root , int l , int r , int pos , int val) {
    int newroot = nodecnt ++;
    num[newroot] = num[root] + 1;
    sum[newroot] = sum[root] + val;
    if (l != r) {
        int mid = (l + r) >> 1;
        if (pos <= mid) {
            lson[newroot] = update (lson[root] , l , mid , pos , val);
            rson[newroot] = rson[root];
        }
        else {
            rson[newroot] = update (rson[root] , mid + 1 , r , pos , val);
            lson[newroot] = lson[root]; 
        }
    }
    return newroot;
}
// search kth
int query (int left_root , int right_root , int lca_root , int l , int r , int k) {
    if (l == r) return l;
    int cal = num[lson[left_root]] + num[lson[right_root]] - 2 * num[lson[lca_root]];
    int mid = (l + r) >> 1;
    if (cal >= k) 
        return query (lson[left_root] , lson[right_root] , lson[lca_root] , l , mid , k);
    else 
        return query (rson[left_root] , rson[right_root] , rson[lca_root] , mid + 1 , r , k - cal);
}
int query (int left_root , int right_root , int lca_root , int k) {
    int calcnt = num[left_root] + num[right_root] - 2 * num[lca_root];
    int l = 0 , r = m - 1;
    int nowcnt = 0 , nowsum = 0;
    while (l < r) {
        int tmpcnt = num[lson[left_root]] + num[lson[right_root]] - 2 * num[lson[lca_root]];
        int tmpsum = sum[lson[left_root]] + sum[lson[right_root]] - 2 * sum[lson[lca_root]];
        int mid = (l + r) >> 1;
        if (mid * (tmpcnt + nowcnt) - tmpsum - nowsum >= k) {
            r = mid;
            left_root = lson[left_root];right_root = lson[right_root];lca_root = lson[lca_root];
        }
        else {
            l = mid + 1;
            nowcnt += tmpcnt;nowsum += tmpsum;
            left_root = rson[left_root];right_root = rson[right_root];lca_root = rson[lca_root];
        }
    }
    if (k - (nowcnt * l - nowsum) < 0) l --;
    return l + (k - (nowcnt * l - nowsum)) / calcnt;
}
void dfs(int u , int pre){  
    int t = ++ depth;  
    b[++ cnt] = t;  
    f[t] = u;  
    p[u] = cnt;  
    for(int i = start[u] ; i != -1 ; i = edge[i].next){  
        int v = edge[i].v , w = edge[i].w;  
        if (v == pre) continue;  
        T[v] = update (T[u] , 0 , m - 1 , hash(w) , w);
        dfs (v , u);  
        b[++ cnt] = t;  
    }  
}  
int dp[N << 1][20];  
void Init_rmq(int n){  
    for(int i = 1 ; i <= n ; i++)  
        dp[i][0] = b[i];  
    int m = floor (log (n * 1.0) / log (2.0));    
    for (int j = 1 ; j <= m ; j ++)  
        for (int i = 1;i <= n - (1 << j) + 1 ; i ++)  
            dp[i][j] = min (dp[i][j - 1] , dp[i + (1 << (j - 1))][j - 1]);    
}  
int rmq (int l , int r){    
    int k = floor (log ((r - l + 1) * 1.0) / log (2.0));    
    return min (dp[l][k] , dp[r - (1 << k) + 1][k]);    
}    
int lca (int a , int b){  
    if (p[a] > p[b]) swap(a , b);  
    return f[rmq (p[a] , p[b])];  
}  

int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    int t , cas = 0;
    scanf ("%d" , &t);
    while (t --) {
        tot = depth = cnt = nodecnt = 0;
        memset (start , -1 , sizeof(start));
        scanf ("%d %d" , &n , &q);
        for (int i = 1 ; i < n ; i ++) {
            int u , v , w;
            scanf ("%d %d %d" , &u , &v , &w);
            add (u , v , w);
            x[i - 1] = w;
        }
        // Init_hash ();
        m = 10000;
        T[1] = bulid (0 , m - 1);
        dfs (1 , 0);
        Init_rmq (cnt);
        printf ("Case #%d:\n" , ++cas);
        while (q --) {
            int s , e , k , a , b;
            scanf ("%d %d %d %d %d" , &s , &e , &k , &a , &b);
            int initial = query (T[s] , T[e] , T[lca (s , e)] , 0 , m - 1 , 1);
            if (a <= b) printf ("%d\n" , initial + k / a);
            else {
                int ans = initial;
                if (k >= a) ans = ans + 1 + (k - a) / b;
                int ret = query (T[s] , T[e] , T[lca (s , e)] , k / b);
                // cout << initial << " " << ans << " " << ret << endl;
                printf ("%d\n" , max (ans , ret));
            }
        }
    }
    return 0;
}