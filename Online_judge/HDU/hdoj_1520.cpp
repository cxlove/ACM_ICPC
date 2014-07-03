/*
ID:cxlove
PROB:Anniversary party 
DATA:2012.3.4
HINT:树形DP
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct Node{
    int u,v,next;
}edge[10000];
int n,val[6005],start[6005],cnt,vis[6006],dp[6005][2];
void addedge(int u,int v){
    edge[cnt].u=u;edge[cnt].v=v;
    edge[cnt].next=start[u];start[u]=cnt++;
}
void dfs(int u,int pre){
    for(int i=start[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v==pre) continue;
        dfs(v,u);
        dp[u][1]+=dp[v][0];
        dp[u][0]+=max(dp[v][0],dp[v][1]);
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&val[i]);
               dp[i][0]=0;
            dp[i][1]=val[i];
        }
        int u,v;
        memset(start,-1,sizeof(start));
        memset(vis,false,sizeof(vis));
        cnt=0;
        while(scanf("%d%d",&v,&u),u+v){
            addedge(u,v);
            vis[v]=true;
        }
        int root,ans=0;
        for(int i=1;i<=n;i++)
            if(vis[i]==false){
                root=i;
                 dfs(i,-1);
                  ans+=max(dp[root][0],dp[root][1]);
            }
        printf("%d\n",ans);
    }
    return 0;
}
/*
7
1
1
1
1
1
1
1
1 3
2 3
6 4
7 4
4 5
3 5
0 0
*/