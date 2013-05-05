#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 16005;
struct Edge{
    int v,next;
}e[N<<1];
int n,val[N];
int start[N],tot;
int ans=-(1<<20);
void _add(int u,int v){
    e[tot].v=v;e[tot].next=start[u];
    start[u]=tot++;
}
void add(int u,int v){
    _add(u,v);
    _add(v,u);
}
int dp[N];
void dfs(int u,int pre){
   // cout<<u<<" "<<pre<<endl;
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre) continue;
        dfs(v,u);
        dp[u]=max(dp[u],dp[u]+dp[v]);
    }
    ans=max(ans,dp[u]);
}
int main(){
    tot=0;memset(start,-1,sizeof(start));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
        dp[i]=val[i];
        ans=max(ans,val[i]);
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs(1,-1);
    printf("%d\n",ans);
    return 0;
}
