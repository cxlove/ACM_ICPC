#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int N = 20005;
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
int ans,idx;
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
    if(mx<ans){
        ans=mx;idx=u;
    }
    else if(mx==ans&&u<idx){
        ans=mx;idx=u;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        tot=0;memset(start,-1,sizeof(start));
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        ans=n;idx=-1;
        cal(1,-1);
        dfs(1,-1);
        printf("%d %d\n",idx,ans);
    }
    return 0;
}