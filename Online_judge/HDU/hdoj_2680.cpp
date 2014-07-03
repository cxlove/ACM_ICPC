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
int start[1005],cnt,n,m,s;
void addedge(int u,int v,int w){
    edge[cnt].u=u;edge[cnt].v=v;edge[cnt].w=w;
    edge[cnt].next=start[u];start[u]=cnt++;
}
void Init(){
    memset(start,-1,sizeof(start));
    cnt=0;
}
void MakeGraph(){
    int u,v,w,k;
    while(m--){
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v,w);
    }
    scanf("%d",&k);
    while(k--){
        scanf("%d",&u);
        addedge(0,u,0);
    }
}
void spfa(){
    bool flag[1005];
    int dist[1005];
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
    if(dist[s]==inf)
        printf("-1\n");
    else
        printf("%d\n",dist[s]);
}
int main(){
    while(scanf("%d%d%d",&n,&m,&s)!=EOF){
        Init();
        MakeGraph();
        spfa();
    }
    return 0;
}