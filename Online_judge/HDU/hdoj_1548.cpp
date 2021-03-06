#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1<<30
using namespace std;
struct Node{
       int u,v,w,next;
}edge[405];
int start[205],cnt,n,a,b;
void addedge(int u,int v,int w){
     edge[cnt].u=u;edge[cnt].v=v;
     edge[cnt].w=w;edge[cnt].next=start[u];
     start[u]=cnt++;
}
int spfa(){
     bool flag[205];
     int dist[205];
     for(int i=1;i<=n;i++)
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
    while(scanf("%d",&n)!=EOF&&n){
           scanf("%d%d",&a,&b);
           cnt=0;
           memset(start,-1,sizeof(start));
           for(int i=1;i<=n;i++){
                int k;
                scanf("%d",&k);
                if(i-k>0)
                    addedge(i,i-k,1);
                if(i+k<=n)
                    addedge(i,i+k,1);
           }
           printf("%d\n",spfa());
    }
    return 0;
}
    
    
