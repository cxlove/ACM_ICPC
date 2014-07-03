/*
ID:cxlove
PROB:GeoDefense 北京网络赛
DATA:2012.3.3
HINT:树形DP+分组背包
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Node{
    int u,v,next;
}edge[3000];
struct NODE{
    int k;
    int cost[55],val[55];
}p[1005];
int n,cnt,start[1005],dp[1005][205],m;
int tmp[1005];
void _addedge(int u,int v){
    edge[cnt].u=u;edge[cnt].v=v;
    edge[cnt].next=start[u];
    start[u]=cnt++;
}
void addedge(int u,int v){
    _addedge(u,v);
    _addedge(v,u);
}
void dfs(int u,int pre){
    bool flag=true;
    for(int i=start[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==pre)
            continue;
        dfs(v,u);
        flag=false;
        for(int j=m;j>=0;j--){
            int t=0;
            for(int k=0;k<=j;k++)
                t=max(t,min(dp[u][j-k],dp[v][k]));
            dp[u][j]=t;
        }
    }
    if(flag)
        for(int i=0;i<=m;i++)
            dp[u][i]=0;
    for(int i=0;i<=m;i++)
        tmp[i]=dp[u][i];
    for(int i=m;i>=0;i--){
        for(int j=0;j<p[u].k;j++)
            if(i-p[u].cost[j]>=0)
                dp[u][i]=max(dp[u][i],tmp[i-p[u].cost[j]]+p[u].val[j]);
        for(int j=0;j<=m;j++)
            tmp[i]=dp[u][i];
    }
    
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);        
        memset(start,-1,sizeof(start));
        cnt=0;
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        scanf("%d",&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i].k);
            for(int j=0;j<p[i].k;j++)
                scanf("%d%d",&p[i].cost[j],&p[i].val[j]);
        }
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j]=1<<30;
        dfs(1,0);
        printf("%d\n",dp[1][m]);
    }
    return 0;
}
/*
2
2
1 2
30
3 10 20 20 40 30 50
3 10 30 20 40 30 45
4
2 1
3 1
1 4
60
3 10 20 20 40 30 50
3 10 30 20 40 30 45
3 10 30 20 40 30 35
3 10 30 20 40 30 35
*/