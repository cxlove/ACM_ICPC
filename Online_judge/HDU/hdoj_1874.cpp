#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<30
#define N 200
using namespace std;
struct Node{
       int u,v,w,next;
}edge[1005];
int start[205],cnt,n,m,a,b;
void addedge(int u,int v,int w){
     edge[cnt].u=u;edge[cnt].v=v;
     edge[cnt].w=w;edge[cnt].next=start[u];
     start[u]=cnt++;
}
int spfa(){
     bool flag[205];
     int dist[205];
     for(int i=0;i<N;i++)
        dist[i]=inf;
     memset(flag,false,sizeof(flag));
     queue<int>que;
     dist[a]=0;
     que.push(a);
     flag[a]=true;
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
     return dist[b]==inf?-1:dist[b];
}         
int main(){
    int mat[205][205];
    while(scanf("%d%d",&n,&m)!=EOF){
           cnt=0;
           memset(start,-1,sizeof(start));
           for(int i=1;i<=m;i++){
                int u,v,w; 
                scanf("%d%d%d",&u,&v,&w);
                addedge(u,v,w);
                addedge(v,u,w);
           }
           scanf("%d%d",&a,&b);
           printf("%d\n",spfa());
    }
    return 0;
}
    
    
