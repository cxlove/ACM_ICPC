/*
ID:cxlove
PROB:aoj 171 going home
DATA:2012.1.23
HINT:最小费用最大流
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<30
using namespace std;
struct node{
    int u,v,f,c,next;
}edge[500005];
int N,M,idx;
int start[1005],dist[1005],vis[1005],pre[1005];
void _addedge(int u,int v,int flow,int cost){
    edge[idx].u=u;edge[idx].v=v;edge[idx].f=flow;edge[idx].c=cost;
    edge[idx].next=start[u];start[u]=idx++;
}
void addedge(int u,int v,int flow,int cost){
    _addedge(u,v,flow,cost);
    _addedge(v,u,0,-cost);
} 
bool Init(){
    if(scanf("%d%d",&N,&M)==EOF)
         return false;
    idx=0;
    memset(start,-1,sizeof(start));
    for(int i=1;i<=N;i++)
        addedge(0,i,1,0);
    for(int i=1;i<=N;i++)
        addedge(i+N,N+N+1,1,0);
    while(M--){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        addedge(u,v+N,1,w);
    }   
    return true;
}  
bool spfa(int s,int e,int n){
    queue<int>que;
    for(int i=0;i<n;i++){
        dist[i]=inf;vis[i]=0;pre[i]=-1;
    }
    que.push(s);dist[s]=0;vis[s]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        vis[u]=0;
        for(int i=start[u];i!=-1;i=edge[i].next)
            if(edge[i].f){
                int v=edge[i].v;
                if(dist[v]>dist[u]+edge[i].c){
                    dist[v]=dist[u]+edge[i].c;
                    pre[v]=i;
                    if(!vis[v]){
                        vis[v]=1;
                        que.push(v);
                    }
                }
            }
    }
    return dist[e]!=inf;
}
int MaxCostFlow(int s,int e,int n){
    int ans=0,flow=inf,Flow=0;
    while(spfa(s,e,n)){
        ans+=dist[e];
        for(int i=pre[e];i!=-1;i=pre[edge[i].u])
            flow=min(flow,edge[i].f);
        for(int i=pre[e];i!=-1;i=pre[edge[i].u]){
            edge[i].f-=flow;
            edge[i^1].f+=flow;
        }
        Flow+=flow;
    }
    if(Flow!=N)
        return -1;
    else
        return ans;
}
int main(){
    while(Init())
        printf("%d\n",MaxCostFlow(0,N+N+1,N+N+2));
    return 0;
}
