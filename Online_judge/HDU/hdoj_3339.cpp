/*
ID:cxlove
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<25
using namespace std;
struct Node{
    int u,v,w,next;
}edge[30000];
int start[105],cnt,n,m,s,val[105],sum,total,dist[105];
void addedge(int u,int v,int w){
    edge[cnt].u=u;edge[cnt].v=v;edge[cnt].w=w;
    edge[cnt].next=start[u];start[u]=cnt++;
}
void Init(){
    memset(start,-1,sizeof(start));
    cnt=0;sum=0;total=0;
}
void MakeGraph(){
    scanf("%d%d",&n,&m);
    int u,v,w,k;
    while(m--){
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
        addedge(v,u,w);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&val[i]);
        sum+=val[i];
    }
}
void spfa(){
    bool flag[105];
    queue<int>que;
    memset(flag,false,sizeof(flag));
    for(int i=0;i<=n;i++)
        dist[i]=inf;
    que.push(0);
    dist[0]=0;
    flag[0]=true;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        flag[u]=false;
        for(int i=start[u];i!=-1;i=edge[i].next){
            int v=edge[i].v,w=edge[i].w;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                if(!flag[v]){
                    flag[v]=true;
                    que.push(v);
                }
            }
        }
    }
}
void DP(){
    int dp[100001];
    for(int i=1;i<=n;i++){
        total+=dist[i];
        if(dist[i]==inf){
            printf("impossible\n");
            return;
        }
    }
    for(int i=0;i<=total;i++)
        dp[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=total;j>=dist[i];j--)
            dp[j]=max(dp[j],dp[j-dist[i]]+val[i]);
    }
    for(int i=1;i<=total;i++)
        if(dp[i]>=(sum/2+1)){
            printf("%d\n",i);
            return ;
        }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        Init();
        MakeGraph();
        spfa();
        DP();
    }
    return 0;
}