#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define Key_value ch[ch[root][1]][0]
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const int N = 1000005;
const int MOD = 1000000007;
struct Edge {
    int v , next;
}e[N << 1];
int tot , start[N] , size[N] , n;
LL fac[N] = {1} , inv[N] , dp[N] , ans[N];
void add (int u , int v) {
    e[tot].v = v;e[tot].next = start[u];
    start[u] = tot ++;
}
LL INV(LL x){    
    return x <= 1 ? x : (MOD - MOD / x) * INV(MOD % x) % MOD;    
}   
void gao (int u , int pre) {
    size[u] = 1;dp[u] = 1LL;
    for (int i = start[u] ; i != -1 ; i = e[i].next) {
        int v = e[i].v;
        if (v == pre) continue;
        gao (v , u);
        size[u] += size[v];
        dp[u] = (dp[u] * dp[v] % MOD * inv[size[v]]) % MOD;
    }
    dp[u] = (dp[u] * fac[size[u] - 1]) % MOD;
}
void cao (int u , int pre) {
    if (pre != -1) {
        ans[u] = (ans[pre] * size[u] % MOD) * INV (n - size[u]) % MOD;  
    }
    for (int i = start[u] ; i != -1 ; i = e[i].next) {
        int v = e[i].v;
        if (v == pre) continue;
        cao (v , u);
    }
}
// void dfs2(int u,int fa)
//  90 {
//  91     int i,v;
//  92     if(u!=1){
//  93         f[u]=(f[fa]*cnt[u])%MOD*inv(n-cnt[u],MOD)%MOD;
//  94         ans=(ans+f[u]*f[u]%MOD)%MOD;
//  95     }
//  96     for(i=0;i<q[u].size();i++){
//  97         if((v=q[u][i])==fa)continue;
//  98         dfs2(v,u);
//  99     }
// 100 }
int main () {
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
        // freopen ("ouput.txt" , "w" , stdout);
    #endif
    int t;
    scanf ("%d" , &t);
    for (int i = 1 ; i < N ; i ++) {
        fac[i] = (fac[i - 1] * i) % MOD;
        inv[i] = INV(fac[i]);
    }
    while (t --) {
        tot = 0;
        memset (start , -1 , sizeof(start));
        scanf ("%d" , &n);
        for (int i = 1 ; i < n ; i ++) {
            int u , v;
            scanf ("%d %d" , &u , &v);
            add (u , v);
            add (v , u);
        }
        gao (1 , -1);
        ans[1] = dp[1];
        cao (1 , -1);
        LL ret = 0;
        for (int i = 1 ; i <= n ; i ++) {
            // cout << i << " " << dp[i] << " " << ans[i] << endl;
            ret = (ret + ans[i] * ans[i]) % MOD;
        }
        printf ("%I64d\n" , ret);
    }
    return 0;
}