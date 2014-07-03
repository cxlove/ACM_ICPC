/*
ID:cxlove
PROB:Find Metal Mineral (2011大连网络赛)
DATA:2012.3.2
HINT;树形DP,分组背包
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{
    int u,v,w,next;
}edge[20005];
int n,s,k,cnt,start[10005];
int dp[10005][15];
void _addedge(int u,int v,int w){
    edge[cnt].u=u;edge[cnt].v=v;edge[cnt].w=w;
    edge[cnt].next=start[u];start[u]=cnt++;
}
void addedge(int u,int v,int w){
    _addedge(u,v,w);
    _addedge(v,u,w);
}
void dfs(int u,int pre){
    for(int i=start[u];i!=-1;i=edge[i].next){
        int v=edge[i].v,w=edge[i].w;
        if(v==pre)
            continue;
        dfs(v,u);
        for(int j=k;j>=0;j--){
            dp[u][j]+=dp[v][0]+2*w;
            for(int r=1;r<=j;r++)
                dp[u][j]=min(dp[u][j],dp[u][j-r]+dp[v][r]+w*r);
        }
    }
}
int main(){
    while(scanf("%d%d%d",&n,&s,&k)!=EOF){
        cnt=0;
        memset(start,-1,sizeof(start));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);
        }
        dfs(s,-1);
        printf("%d\n",dp[s][k]);
    }
    return 0;
}
/*
3 1 1
1 2 1
1 3 1
3 1 2
1 2 1
1 3 1
*/



