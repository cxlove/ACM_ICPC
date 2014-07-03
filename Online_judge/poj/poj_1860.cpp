#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#define LL long long 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
const int N = 105;
struct Edge{
    int v,next;
    double r,c;
}e[N<<2];
int tot,start[N];
int n,m,s;
double money;
void add(int u,int v,double r,double c){
    e[tot].v=v;e[tot].next=start[u];
    e[tot].r=r;e[tot].c=c;start[u]=tot++;
}
bool spfa(int s,double mon){
    double dist[N];
    bool in[N];
    memset(in,false,sizeof(in));
    memset(dist,0,sizeof(dist));
    dist[s]=mon;
    queue<int>que;
    que.push(s);
    in[s]=true;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        in[u]=false;
        for(int i=start[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            double r=e[i].r,c=e[i].c;
            double tmp=(dist[u]-c)*r;
            if(tmp>dist[v]){
                if(v==s) return true;
                dist[v]=tmp;
                if(!in[v]){
                    in[v]=true;
                    que.push(v);
                }
            }
        }
    }
    return false;
}
int main(){
    while(scanf("%d%d%d%lf",&n,&m,&s,&money)!=EOF){
        tot=0;memset(start,-1,sizeof(start));
        for(int i=0;i<m;i++){
            int u,v;
            double r1,c1,r2,c2;
            scanf("%d%d%lf%lf%lf%lf",&u,&v,&r1,&c1,&r2,&c2);
            add(u,v,r1,c1);
            add(v,u,r2,c2);
        }
        puts(spfa(s,money)?"YES":"NO");
    }
    return 0;
}