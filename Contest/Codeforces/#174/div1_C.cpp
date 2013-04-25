#include<iostream>    
#include<cstdio>    
#include<map>    
#include<cstring>    
#include<cmath>    
#include<vector>    
#include<algorithm>    
#include<set>    
#include<string>    
#include<queue>    
#define inf 0x3f3f3f3f  
#define M 40    
#define N 1000005  
#define maxn 2000005    
#define eps 1e-7  
#define zero(a) fabs(a)<eps    
#define Min(a,b) ((a)<(b)?(a):(b))    
#define Max(a,b) ((a)>(b)?(a):(b))    
#define pb(a) push_back(a)    
#define mp(a,b) make_pair(a,b)    
#define mem(a,b) memset(a,b,sizeof(a))    
#define LL long long    
#define MOD 1000000007  
#define lson step<<1  
#define rson step<<1|1  
#define sqr(a) ((a)*(a))    
#define Key_value ch[ch[root][1]][0]    
#define test puts("OK");    
#define pi acos(-1.0)  
#define lowbit(x) ((x)&(-(x)))  
#pragma comment(linker, "/STACK:1024000000,1024000000")    
#define vi vector<int>   
using namespace std;  
int fa[N],nxt[N];
int n,t,q;
LL a[N];
int pre[N],vis[N]={0};
int dp[N]={0};
LL sum=0;
int find(int x){
    return pre[x]=(pre[x]==x?x:find(pre[x]));
}
void dfs(int u,int c){
    if(vis[u]) return;
    vis[u]=1;
    if(fa[u]!=-1){
        dfs(fa[u],c+1);
        a[u]+=a[fa[u]];
    }
    if(c)
        sum+=a[u];
}
int main(){
    cin>>n>>q>>t;
    mem(fa,-1);mem(nxt,-1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre[i]=i;
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        fa[v]=u;
        nxt[u]=v;
        int ra=find(u),rb=find(v);
        if(ra==rb){
            puts("0");
            return 0;
        }
        pre[ra]=rb;
    }
    for(int i=1;i<=n;i++)
        if(nxt[i]==-1)
            dfs(i,0);
    if(sum>t){
        puts("0");
        return 0;
    }
    dp[sum]=1;
    for(int i=1;i<=n;i++){
        for(int j=a[i];j<=t;j++){
            dp[j]+=dp[j-a[i]];
            if(dp[j]>=MOD)
                dp[j]-=MOD;
        }
    }
    printf("%d\n",dp[t]);
    return 0;
}