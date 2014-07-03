#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 100050;

struct edge
{
    int u,v,next;
}e[N << 1];

int head[N],tot,n,d,vis[N];

void addEdge(int u,int v){
    e[tot].u = u , e[tot].v = v;
    e[tot].next = head[u] , head[u] = tot ++;
}

int bfs(){
    queue<int> q;
    memset(vis,-1,sizeof(vis));
    vis[0] = 0;
    q.push(0);
    while(! q.empty()){
        int u = q.front();q.pop();
        if(vis[u] >= d) continue;
        for(int i = head[u];i != -1;i = e[i].next){
            int v = e[i].v;
            if(vis[v] == -1) vis[v] = vis[u] + 1 , q.push(v);
        }
    }
    int ret = 0;
    for(int i = 0;i < n;i ++)
        ret += (vis[i] == -1);
    return ret;
}

int main(){
    int cas;
    scanf("%d",&cas);
    while(cas --){
        scanf("%d%d",&n,&d);
        memset(head,-1,sizeof(head)) , tot = 0;
        for(int i = 1;i < n;i ++){
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        int ans = bfs();
        printf("%d\n",ans);
    }
    return 0;
}