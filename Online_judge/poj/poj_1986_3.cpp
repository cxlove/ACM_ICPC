#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#include<set>  
#include<string>  
#include<ctime>
#include<queue>  
#define inf 1000000005  
#define M 10000005 
#define N 50005
#define maxn 210005  
#define eps 1e-8
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 1000000007
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#define lowbit(x) ((-(x))&(x))
#define HASH1 1331
#define HASH2 10001
#define C   240  
#define vi vector<int>
#define TIME 10  
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;
vector<pair<int,int> >edge[N];
int n,q,dist[N];
int depth=0,b[N*2],a[N*2],tot=0;
int p[N],f[N];
void dfs(int u,int pre){
    int t=++depth;
    b[++tot]=t;
    f[t]=u;
    p[u]=tot;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i].first,w=edge[u][i].second;
        if(v==pre) continue;
        dist[v]=dist[u]+w;
        dfs(v,u);
        b[++tot]=t;
    }
}
int dp[N*2][20];
void Init_rmq(int n){
    for(int i=1;i<=n;i++)
        dp[i][0]=b[i];
    int m=floor(log(n*1.0)/log(2.0));  
    for(int j=1;j<=m;j++)
        for(int i=1;i<=n-(1<<j)+1;i++)
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);  
}
int rmq(int l,int r){  
    int k=floor(log((r-l+1)*1.0)/log(2.0));  
    return min(dp[l][k],dp[r-(1<<k)+1][k]);  
}  
int lca(int a,int b){
    if(p[a]>p[b]) swap(a,b);
    return f[rmq(p[a],p[b])];
}
int main(){
    scanf("%d%d",&n,&q);
    while(q--){
        int u,v,w;char str[5];
        scanf("%d%d%d%s",&u,&v,&w,str);
        edge[u].pb(mp(v,w));
        edge[v].pb(mp(u,w));
    }
    dist[1]=0;
    dfs(1,0);
    Init_rmq(tot);
    scanf("%d",&q);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        printf("%d\n",dist[u]+dist[v]-2*dist[lca(u,v)]);
    }
    return 0;
}