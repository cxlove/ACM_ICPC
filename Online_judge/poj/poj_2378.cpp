#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 50005;
struct Edge{
    int v,next;
}e[N<<1];
int n,size[N],tot,start[N];
void _add(int u,int v){
    e[tot].v=v;e[tot].next=start[u];
    start[u]=tot++;
}
void add(int u,int v){
    _add(u,v);
    _add(v,u);
}
void cal(int u,int pre){
    size[u]=1;
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre) continue;
        cal(v,u);
        size[u]+=size[v];
    }
}
int ans;
vector<int>idx;
void dfs(int u,int pre){
    int mx=0,sum=1;
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre) continue;
        dfs(v,u);
        sum+=size[v];
        mx=max(size[v],mx);
    }
    mx=max(mx,n-sum);
    if(mx<=n/2)idx.push_back(u);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        tot=0;memset(start,-1,sizeof(start));
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        ans=n;idx.clear();
        cal(1,-1);
        dfs(1,-1);
        if(idx.size()==0) puts("NONE");
        sort(idx.begin(),idx.end());
        for(int i=0;i<idx.size();i++)
            printf("%d\n",idx[i]);
    }
    return 0;
}