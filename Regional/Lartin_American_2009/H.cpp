/*
ID:cxlove
Prob:H Hooligan
Algorithm:Max Flow
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
#define INF 1<<20
using namespace std;
const int N=2005;
struct Edge{
    int v,w,next;
}e[N<<2];
int head[N],cur[N],level[N];
int n,m,g,tot;
int source,sink;
int cnt[55][55],point[55];
void _add(int u,int v,int w){
    e[tot].v=v;
    e[tot].w=w;
    e[tot].next=head[u];
    head[u]=tot++;
}
void add(int u,int v,int w){
    _add(u,v,w);
    _add(v,u,0);
}

bool bfs(){
    queue<int> q;
    q.push(source);
    memset(level,-1,sizeof(level));
    level[source] = 1;
    while(! q.empty()){
        int u = q.front();q.pop();
        for(int i = head[u];i != -1;i = e[i].next){
            int v = e[i].v;
            if(level[v] == -1 && e[i].w){
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
    if(level[sink] == -1) return false;
    else return true;
}
int dfs(int u,int flow){
    if(u == sink) return flow;
    int tmp = flow;
    for(int &i = cur[u];i != -1;i = e[i].next){
        int v = e[i].v;
        if(e[i].w && level[v] == level[u] + 1){
            int flow = dfs(v,min(e[i].w,tmp));
            tmp -= flow;
            e[i].w -= flow;
            e[i ^ 1].w += flow;
            if(tmp == 0) break;
        }
    }
    return flow - tmp;
}
int dinic(){
    int maxflow = 0;
    while(bfs()){
        for(int i = source;i <= sink;i ++)
            cur[i] = head[i];
        maxflow += dfs(source,INF);
    }
    return maxflow;
}
int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d%d",&n,&m,&g)!=EOF){
        if(!n&&!m&&!g) break;
        memset(cnt,0,sizeof(cnt));
        memset(point,0,sizeof(point));
        memset(head,-1,sizeof(head));
        tot=0;
        while(g--){
            int u,v;
            char str[5];
            scanf("%d%s%d",&u,str,&v);
            cnt[u][v]++;
            cnt[v][u]++;
            if(str[0]=='<') point[v]+=2;
            else point[u]++,point[v]++;
        }
        for(int i=1;i<n;i++)
            if(cnt[0][i]<m){
                point[0]+=(m-cnt[0][i])*2;
                cnt[0][i]=m;
                cnt[i][0]=m;
            }
        source=0;sink=2000;
        int t1=1,Flow=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(cnt[i][j]<m){
                    add(0,t1,(m-cnt[i][j])*2);
                    add(t1,1500+i,INF);
                    add(t1,1500+j,INF);
                    t1++;
                    Flow+=(m-cnt[i][j])*2;
                }
            }
        }
        bool flag=true;
        for(int i=1;i<n;i++){
            if(point[i]>=point[0]){
                flag=false;
                break;
            }
            add(1500+i,2000,point[0]-point[i]-1);
        }
        if(!flag||dinic()!=Flow) puts("N");
        else puts("Y");
    }
    return 0;
}