#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#pragma comment(linker, "/STACK:1024000000,1024000000")   
using namespace std;
const int N = 10005;
struct Edge{
    int v,next,w;
}e[N<<1];
int tot,start[N],n,m,k,del[N],ans;
int size[N];
void _add(int u,int v,int w){
    e[tot].v=v;e[tot].w=w;
    e[tot].next=start[u];start[u]=tot++;
}
void add(int u,int v,int w){
    _add(u,v,w);
    _add(v,u,w);
}
void cal(int u,int pre){
    size[u]=1;
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre||del[v]) continue;
        cal(v,u);
        size[u]+=size[v];
    }
}
int newroot,maxsize,totalsize;
void dfs(int u,int pre){
    int mx=0,sum=1;
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre||del[v]) continue;
        dfs(v,u);
        mx=max(mx,size[v]);
        sum+=size[v];
    }
    mx=max(mx,totalsize-sum);
    if(mx<maxsize){
        maxsize=mx;
        newroot=u;
    }
}
int search(int r){
    newroot=-1;maxsize=1<<30;
    cal(r,-1);
    totalsize=size[r];
    dfs(r,-1);
    return newroot;
}
int dist[N],idx;
vector<int>sub[N],all;
void gao(int u,int pre){
    all.push_back(dist[u]);
    sub[idx].push_back(dist[u]);
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v,w=e[i].w;
        if(v==pre||del[v]) continue;
        dist[v]=dist[u]+w;
        gao(v,u);
    }
}
void solve(int root){
    root=search(root);
    del[root]=1;
    if(totalsize==1) return ;
    idx=0;all.clear();
    for(int i=start[root];i!=-1;i=e[i].next){
        int v=e[i].v,w=e[i].w;
        if(del[v]) continue;
        sub[idx].clear();
        dist[v]=w;
        gao(v,-1);
        sort(sub[idx].begin(),sub[idx].end());
        idx++;
    }
    for(int i=0;i<idx;i++){
        int pos;
        for(int j=0;j<sub[i].size();j++){
            pos=upper_bound(sub[i].begin(),sub[i].end(),k-sub[i][j])-sub[i].begin()-1;
            if(pos>j) ans-=pos-j;
        }
        pos=upper_bound(sub[i].begin(),sub[i].end(),k)-sub[i].begin()-1;
        if(pos>=0) ans+=pos+1;
    }
    sort(all.begin(),all.end());
    for(int i=0;i<all.size();i++){
        int pos=upper_bound(all.begin(),all.end(),k-all[i])-all.begin()-1;
        if(pos>i) ans+=pos-i;
    }
    for(int i=start[root];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(del[v]) continue;
        solve(v);
    }
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==0&&k==0) break;
        ans=0;
        tot=0;memset(start,-1,sizeof(start));
        memset(del,0,sizeof(del));
        for(int i=1;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
        }
        solve(1);
        printf("%d\n",ans);
    }
    return 0;
}