/*
ID:cxlove
Prob:A Another Crisis
Algorithm:tree dp
*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define N 100005
using namespace std;
struct Edge{
    int v,next;
}e[N<<1];
int n,t;
int tot,start[N];
int size[N];
void _add(int u,int v){
    e[tot].v=v;e[tot].next=start[u];
    start[u]=tot++;
}
void add(int u,int v){
    _add(u,v);
    _add(v,u);
}
int dfs(int pre,int u){
    vector<int>tmp;
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre) continue;
        tmp.push_back(dfs(u,v));
    }
    if(tmp.size()==0) return 1;
    else{
        sort(tmp.begin(),tmp.end());
        int k=ceil(size[u]*0.01*t),ret=0;
        for(int i=0;i<k;i++)
            ret+=tmp[i];
        return ret;
    }
}
int main(){
    while(scanf("%d%d",&n,&t)!=EOF){
        if(!n&&!t) break;
        memset(start,-1,sizeof(start));
        memset(size,0,sizeof(size));
        tot=0;
        for(int i=1;i<=n;i++){
            int pre;
            scanf("%d",&pre);
            add(pre,i);
            size[pre]++;
        }
        printf("%d\n",dfs(-1,0));
    }
    return 0;
}