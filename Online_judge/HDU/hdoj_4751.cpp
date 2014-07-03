#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 205;

struct edge
{
    int u,v,next;
}e[N * N];

int head[N],tot,n,m;
int dfn[N],low[N],stack[N],block[N],top,num,blockId;
bool inS[N],mp[N][N];

void dfs(int u){
    dfn[u] = low[u] = num ++;
    inS[u] = true;
    stack[++ top] = u;
    for(int i = head[u];i != -1;i = e[i].next){
        int v = e[i].v;
        if(dfn[v] == -1){
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
        else if(inS[v]) low[u] = min(low[u],dfn[v]);
    }
    if(dfn[u] == low[u]){
        int v = -1;
        do{
            v = stack[top --];
            inS[v] = false;
            block[v] = blockId;
        }while(u != v);
        blockId ++;
    }
}

void tarjan(){
    memset(dfn,-1,sizeof(dfn));
    top = num = blockId = 0;
    for(int i = 0;i < n << 1;i ++)
        if(dfn[i] == -1) dfs(i);
}

void addEdge(int u,int v){
    e[tot].u = u , e[tot].v = v;
    e[tot].next = head[u] , head[u] = tot ++;
}

void _add(int u,int v){
    addEdge(u,v ^ 1);
    addEdge(v,u ^ 1);
}

int main(){
    // freopen("input.txt","r",stdin);
    while(scanf("%d",&n) != EOF){
        memset(head,-1,sizeof(head)) , tot = 0;
        memset(mp,false,sizeof(mp));
        for(int i = 0,j;i < n;i ++)
            while(scanf("%d",&j) && j) mp[i][-- j] = true;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < n;j ++) if(i != j) {
                if(mp[i][j] && mp[j][i]) continue;
                _add(i << 1,j << 1);
                _add(i << 1 | 1,j << 1 | 1);
            }
        }
        tarjan();/*
        for(int i = 0;i < n << 1;i ++)
            cout << i << ' ' << block[i] << endl;*/
        bool ans = true;
        for(int i = 0;i < n && ans;i ++){
            if(block[i << 1] == block[i << 1 | 1]) ans = false;
        }
        if(ans) puts("YES");
        else puts("NO");
    }
    return 0;
}