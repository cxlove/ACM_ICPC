/*
ID:cxlove
PROB:The more, The Better 
DATA:2012.3.2
HINT:树形DP
*/
#include<iostream>
#include<cstdio>
using namespace std;
struct node{
    int u,v,next;
}edge[1000];
int n,m,start[300],cnt,dp[205][205],val[205];
void _addedge(int u,int v){
    edge[cnt].u=u;edge[cnt].v=v;
    edge[cnt].next=start[u];start[u]=cnt++;
}
void addedge(int u,int v){
    _addedge(u,v);    
}
void dfs(int u,int pre){
    dp[u][1]=val[u];
    for(int i=start[u];i!=-1;i=edge[i].next){
        int v=edge[i].v,w=val[u];
        if(v==pre)
            continue;
        dfs(v,u);
        for(int j=m+1;j>1;j--)
            for(int k=1;k<j;k++)
                dp[u][j]=max(dp[u][j],dp[u][j-k]+dp[v][k]);
    }
}
int main(){
    while(scanf("%d%d",&n,&m),n+m){
        cnt=0;
        memset(start,-1,sizeof(start));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            int a;
            scanf("%d%d",&a,&val[i]);
            addedge(a,i);
        }
        dfs(0,-1);
        printf("%d\n",dp[0][m+1]);
    }
    return 0;
}
/*
3 2
0 1
0 2
0 3
7 4
2 2
0 1
0 4
2 1
7 1
7 6
2 2
0 0
*/