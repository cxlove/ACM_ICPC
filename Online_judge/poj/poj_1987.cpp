#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#pragma comment(linker, "/STACK:1024000000,1024000000")   
using namespace std;
const int N = 40005;
struct Edge{
    int v,next,w;
}e[N<<1];
int tot,start[N],n,m,k,del[N],ans=0;
int size[N];
void _add(int u,int v,int w){
    e[tot].v=v;e[tot].w=w;
    e[tot].next=start[u];start[u]=tot++;
}
void add(int u,int v,int w){
    _add(u,v,w);
    _add(v,u,w);
}
// void cal (int u , int p) {
//     vector <int> nxt[N];
//     int que[N] , pre[N];
//     int head = 0 , tail = 0;
//     que[tail] = u;pre[tail ++] = p;
//     while (head <= tail) {
//         u = que[head];
//         p = pre[head ++];
//         for(int i=start[u];i!=-1;i=e[i].next){
//             int v=e[i].v;
//             if(v==p||del[v]) continue;
//             nxt[u].push_back (v);
//             que[tail] = v;
//             pre[tail ++] = u;
//         }
//     }
//     for (int i = tail - 1 ; i >= 0 ; i --) {
//         int u = que[i] , p = pre[i] , sz = nxt[u].size();
//         for (int j = 0 ; j < sz ; j ++) {
//             int v = nxt[u][j];
//             if(v==p||del[v]) continue;
//             size[u] += size[v];
//         }
//     }
// }
void cal(int u,int pre){
    size[u]=1;
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre||del[v]) continue;
        cal(v,u);
        size[u]+=size[v];
    }
}
int newroot,maxsize,totalsize,pre[N];
void bfs(int u){
    queue<int>que;
    que.push(u);
    pre[u]=-1;
    while(!que.empty()){
        int u=que.front(),mx=0,sum=1;
        que.pop();
        for(int i=start[u];i!=-1;i=e[i].next){
            int v=e[i].v;
            if(v==pre[u]||del[v]) continue;
            que.push(v);
            pre[v]=u;
            mx=max(mx,size[v]);
            sum+=size[v];
        }
        mx=max(mx,totalsize-sum);
        if(mx<maxsize){
            maxsize=mx;
            newroot=u;
        }
    }
}
int search(int r){
    newroot=-1;maxsize=1<<30;
    cal(r,-1);
    totalsize=size[r];
    bfs(r);
    return newroot;
}
int dist[N],idx;
vector<int>sub[N],all;
void gao(int u){
    pre[u]=-1;
    queue<int>que;
    que.push(u);
    while(!que.empty()){
        int u=que.front();
        all.push_back(dist[u]);
        sub[idx].push_back(dist[u]);
        que.pop();
        for(int i=start[u];i!=-1;i=e[i].next){
            int v=e[i].v,w=e[i].w;
            if(v==pre[u]||del[v]) continue;
            dist[v]=dist[u]+w;
            que.push(v);pre[v]=u;
        }
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
        gao(v);
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
    // freopen ("input.txt" , "r" , stdin);
    tot=0;memset(start,-1,sizeof(start));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int u,v,w;char str[5];
        scanf("%d%d%d%s",&u,&v,&w,str);
        add(u,v,w);
    }
    scanf("%d",&k);
    solve(1);
    printf("%d\n",ans);
    return 0;
}