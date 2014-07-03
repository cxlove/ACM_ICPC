#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<30
using namespace std;
struct Node{
       int u,v,w,val,next;
}edge[1000005];
int start[1005],cnt,n,m,a,b;
void addedge(int u,int v,int w,int val){
     edge[cnt].u=u;edge[cnt].v=v;edge[cnt].val=val;
     edge[cnt].w=w;edge[cnt].next=start[u];
     start[u]=cnt++;
}
int spfa(){
     bool flag[1005];
     int dist[1005],cost[1005];
     for(int i=1;i<=n;i++)
        cost[i]=dist[i]=inf;
     memset(flag,false,sizeof(flag));
     queue<int>que;
     cost[a]=dist[a]=0;
     que.push(a);
     flag[a]=true;
     while(!que.empty()){
          int u=que.front();
          que.pop();
          flag[u]=false;
          for(int i=start[u];i!=-1;i=edge[i].next){
              int v=edge[i].v,w=edge[i].w,val=edge[i].val;
              if(dist[v]>dist[u]+w||(dist[v]==dist[u]+w&&cost[v]>cost[u]+val)){
                   dist[v]=dist[u]+w;
                   cost[v]=cost[u]+val;
                   if(!flag[v]){
                        flag[v]=true;
                        que.push(v);
                   }
              }
          }
     }
     printf("%d %d\n",dist[b],cost[b]);
}         
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
           cnt=0;
           memset(start,-1,sizeof(start));
           for(int i=1;i<=m;i++){
                int u,v,w,val; 
                scanf("%d%d%d%d",&u,&v,&w,&val);
                addedge(u,v,w,val);
                addedge(v,u,w,val);
           }
           scanf("%d%d",&a,&b);
           spfa();
    }
    return 0;
}
    
    
