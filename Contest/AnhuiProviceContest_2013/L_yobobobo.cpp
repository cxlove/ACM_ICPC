#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <string>
#include <ctime>
#include <cstdlib>
#define Hash1 (LL)11111
#define Hash2 (LL)13337
#define lson l,m,rt << 1
#define rson m + 1,r,rt << 1 | 1
#define eps 1e-8
#define ft first
#define sd second
#define LL long long
#define Test puts("END")
#define pi acos(-1.0)
#define clr(a,b) memset(a,b,sizeof(a));
#define zero(x) (((x)>0?(x):-(x))<eps)
#pragma comment(linker, "/STACK:32000000")
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000000;
const int N = 120000;
const int M = 1000;

struct edge
{
    int u,v,w,next;
}e[N << 1];

int head[N],tot,degree[N],n;
double dp[N];

void add_edge(int u,int v){
    e[tot].u = u , e[tot].v = v;
    e[tot].next = head[u] , head[u] = tot ++;
}

void dfs(int f,int u){
    dp[u] = 0.0;
    for(int i = head[u];i != -1;i = e[i].next){
        int v = e[i].v;
        if(v == f) continue;
        dfs(u,v);
        dp[u] += dp[v] / max(1,degree[v] - 1) + 1.0 / degree[v];
    }
}

void call(int f,int u){
    for(int i = head[u];i != -1;i = e[i].next){
        int v = e[i].v;
        if(v == f) continue;
        dp[v] += (dp[u] - (dp[v] / max(1,degree[v] - 1) + 1.0 / degree[v])) / max(1,degree[u] - 1) + (1.0 / degree[u]);
        call(u,v);
    }
}

int main()
{
    // freopen("input.txt","r",stdin);
    while(scanf("%d",&n) != EOF && n){
        clr(dp,0);
        clr(degree,0);
        clr(head,-1);
        tot = 0;
        for(int i = 1;i < n;i ++){
            int u,v;
            scanf("%d%d",&u,&v);
            degree[u] ++,degree[v] ++;
            add_edge(u,v);
            add_edge(v,u);
        }
        dfs(1,1);
        call(1,1);
        double ans = 0.0;
        for(int i = 1;i <= n;i ++)
            if(degree[i] == 1)
                ans = max(ans,dp[i]);
        printf("%.3f\n",ans);
    }
    return 0;
}