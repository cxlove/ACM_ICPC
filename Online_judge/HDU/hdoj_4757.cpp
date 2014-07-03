#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#define lson step << 1
#define rson step << 1 | 1
#define lowbit(x) (x & (-x))
#define Key_value ch[ch[root][1]][0] 
using namespace std;
typedef long long LL;
const int N = 100005;
const int M = 2000005;
struct Edge {
    int v , next;
}edge[N << 1];
int n , tot , start[N] , q , a[N]; 
int dp[N << 1][20];   
int depth , b[N << 1] , cnt , p[N] , f[N];  
int T[N] , ch[M][2] , nodecnt , num[M];
void add (int u , int v) {
    edge[tot].v = v;edge[tot].next = start[u];
    start[u] = tot ++;
}
int newnode () {
    ch[nodecnt][0] = ch[nodecnt][1] = 0;
    num[nodecnt] = 0;
    return nodecnt ++;
}
void insert (int x , int y , int val) {
    x = T[x] ; y = T[y];
    for (int i = 15 ; i >= 0 ; i --) {
        int c = (val >> i) & 1;
        if (!ch[x][c]) ch[x][c] = newnode () , ch[x][c ^ 1] = ch[y][c ^ 1] , num[ch[x][c]] = num[ch[y][c]];
        x = ch[x][c]; y = ch[y][c];
        num[x] ++;
    }
}
void dfs(int u , int pre){    
    int t = ++ depth;    
    b[++ cnt] = t;    
    f[t] = u;    
    p[u] = cnt;  
    T[u] = newnode ();
    insert (u , pre , a[u]);  
    for(int i = start[u] ; i != -1 ; i = edge[i].next){    
        int v = edge[i].v;
        if (v == pre) continue;    
        dfs (v , u);    
        b[++ cnt] = t;    
    }    
}    
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
int query (int x , int y , int lca , int z) {
    int ret = a[lca] ^ z , ans = 0;
    x = T[x]; y = T[y]; lca = T[lca];
    for (int i = 15 ; i >= 0 ; i --) {
        int c = (z >> i) & 1;
        if (num[ch[x][c ^ 1]] + num[ch[y][c ^ 1]] - 2 * num[ch[lca][c ^ 1]]  > 0) ans |= 1 << i , x = ch[x][c ^ 1] , y = ch[y][c ^ 1] , lca = ch[lca][c ^ 1];
        else  x = ch[x][c] , y = ch[y][c] , lca = ch[lca][c];
    }
    return max (ret , ans);
} 
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("output.txt" , "w" , stdout);
    #endif
    while (scanf ("%d %d" , &n , &q) != EOF) {
        tot = depth = cnt = nodecnt = 0;
        memset (start , -1 , sizeof(start));
        for (int i = 1 ; i <= n ; i ++)
            scanf ("%d" , &a[i]);
        for (int i = 1 ; i < n ; i ++) {
            int u , v;
            scanf ("%d %d" , &u , &v);
            add (u , v);add (v , u);
        }
        T[0] = newnode ();
        dfs (1 , 0);
        Init_rmq (cnt);
        while (q --) {
            int x , y , z;
            scanf ("%d %d %d" , &x , &y , &z);
            printf ("%d\n" , query (x , y , lca (x , y) , z));
        }
    }
    return 0;
}       

