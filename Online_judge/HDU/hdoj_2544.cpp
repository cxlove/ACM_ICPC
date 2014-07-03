#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<30
using namespace std;
struct Node{
       int u,v,w,next;
}edge[10005];
int start[105],cnt,n,m;
void addedge(int u,int v,int w){
     edge[cnt].u=u;edge[cnt].v=v;
     edge[cnt].w=w;edge[cnt].next=start[u];
     start[u]=cnt++;
}
int spfa(){
     bool flag[105];
     int dist[105];
     for(int i=1;i<=n;i++)
        dist[i]=inf;
     memset(flag,false,sizeof(flag));
     queue<int>que;
     dist[1]=0;
     que.push(1);
     flag[1]=true;
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
     return dist[n]==inf?-1:dist[n];
}         
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
           cnt=0;
           memset(start,-1,sizeof(start));
           for(int i=1;i<=m;i++){
                int u,v,w; 
                scanf("%d%d%d",&u,&v,&w);
                addedge(u,v,w);
                addedge(v,u,w);
           }
           printf("%d\n",spfa());
    }
    return 0;
}
    
    
