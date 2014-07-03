#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<map>
#define inf 1<<30
#define eps 1e-7
#define N 155
using namespace std;
struct Node{
       int u,v,next;
       double w;
}edge[10005];
map<string,int>m;
int start[31],cnt,n,mm,a,b,tot;
void addedge(int u,int v,double w){
     edge[cnt].u=u;edge[cnt].v=v;
     edge[cnt].w=w;edge[cnt].next=start[u];
     start[u]=cnt++;
}
bool spfa(){
     bool flag[31];
     double dist[31];
     for(int i=1;i<=n;i++)
       dist[i]=0;
     memset(flag,false,sizeof(flag));
     queue<int>que;
     dist[1]=1;
     que.push(1);
     flag[1]=true;
     while(!que.empty()){
          int u=que.front();
          que.pop();
          flag[u]=false;
          for(int i=start[u];i!=-1;i=edge[i].next){
              int v=edge[i].v;
              double w=edge[i].w;
              if(dist[v]<dist[u]*w){
                   dist[v]=dist[u]*w;
                   if(!flag[v]){
                        flag[v]=true;
                        que.push(v);
                   }
              }
          }
          if(dist[1]>1+eps)
             return true;
     }
     return false;
}      
int main(){
    int tt=0;
    while(scanf("%d",&n)!=EOF&&n){        
           m.clear();
           char u[100],v[100];
           string tu,tv;
           cnt=0;
           memset(start,-1,sizeof(start));
           for(int i=1;i<=n;i++){
                scanf("%s",u);
                tu=string(u);
                m[tu]=i;
           }
           scanf("%d",&mm);
           for(int i=1;i<=mm;i++){
                double w;  
                scanf("%s%lf%s",u,&w,v);
                tu=string(u);tv=string(v);        
                addedge(m[tu],m[tv],w);
           } 
           printf("Case %d: ",++tt);              
           if(spfa())
              printf("Yes\n");
           else
              printf("No\n");
    }
    return 0;
}
/*
3
USDollar
BritishPound
FrenchFranc
3
USDollar 0.5 BritishPound
BritishPound 10.0 FrenchFranc
FrenchFranc 0.21 USDollar
3
USDollar
BritishPound
FrenchFranc
6
USDollar 0.5 BritishPound
USDollar 4.9 FrenchFranc
BritishPound 10.0 FrenchFranc
BritishPound 1.99 USDollar
FrenchFranc 0.09 BritishPound
FrenchFranc 0.19 USDollar
    
*/
