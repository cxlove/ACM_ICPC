#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

const int N = 1000050;

struct edge
{
    int u,v,next;
}e[N << 1];

int n,dp[N],ans,fa[N],seq[N];
int head[N],tot;
bool add[N];

void addEdge(int u,int v){
    e[tot].u = u , e[tot].v = v;
    e[tot].next = head[u] , head[u] = tot ++;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen ("input.txt" , "r" , stdin);
    #endif
    int cas;
    scanf("%d",&cas);
    while(cas --){
        scanf("%d",&n);
        memset(head,-1,sizeof(head)) , tot = 0;
        for(int i = 1;i < n;i ++){
            int u,v;
            scanf("%d%d",&u,&v);
            addEdge(u,v);
            addEdge(v,u);
        }
        memset(fa,-1,sizeof(fa));
        memset(add,false,sizeof(add));
        fa[1] = n + 1;
        for(int i = 1;i <= n;i ++)
            dp[i] = 1;
        queue<int> q;
        q.push(1);
        int id = 0;
        while(! q.empty()){
            int u = q.front();q.pop();
            seq[++ id] = u;
            for(int i = head[u];i != -1;i = e[i].next){
                int v = e[i].v;
                if(fa[v] == -1) fa[v] = u , q.push(v);
            }
        }
        ans = 0;
        for(int i = n;i >= 1;i --){
            int v = seq[i];
            int u = fa[v];
            if(dp[v] > 1){
                ans += dp[v] - 1;
                dp[v] = 0;
            } 
            else{
                if(u == n + 1) continue;
                if(add[u]) dp[u] ++;
                else add[u] = true;
                dp[v] = 0;
            }
        }
        for(int i = 1;i <= n;i ++)
            ans += dp[i];
        printf("%d\n",ans * 2 - 1);
    }
    return 0;
}