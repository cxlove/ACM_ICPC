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
const int N = 505;
struct Node{
    int v,next,w;
}e[N<<4];
int n,m,k;
int start[N],tot;
bool vis[N];
void add(int u,int v,int w){
    e[tot].v=v;e[tot].next=start[u];
    e[tot].w=w;
    start[u]=tot++;
}
bool spfa(int s){
    queue<int>que;
    int dist[N];
    bool in[N];
    int cnt[N];
    memset(cnt,0,sizeof(cnt));
    memset(in,false,sizeof(in));
    memset(dist,0x11,sizeof(dist));
    vis[s]=true;
    dist[s]=0;
    que.push(s);
    in[s]=true;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        in[u]=false;
        cnt[u]++;
        if(cnt[u]>=n) return true;
        for(int i=start[u];i!=-1;i=e[i].next){
            int v=e[i].v,w=e[i].w;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
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
    int t;
    scanf("%d",&t);
    while(t--){
        tot=0;
        memset(start,-1,sizeof(start));
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        for(int i=0;i<k;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,-w);
        }
        memset(vis,false,sizeof(vis));
        bool flag=false;
        for(int i=1;i<=n&&!flag;i++)
            if(vis[i]==false){
                flag=spfa(i);
            }
        puts(flag?"YES":"NO");
    }
    return 0;
}