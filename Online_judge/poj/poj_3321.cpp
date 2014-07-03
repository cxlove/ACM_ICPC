#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<algorithm>  
#include<set>  
#include<string>  
#include<queue>  
#define inf 1600005  
#define M 40  
#define N 100005
#define maxn 300005  
#define eps 1e-7
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 2012  
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;  
struct Edge{
    int v,next;
}e[N*2];
int tot,start[N];
void add(int u,int v){
    e[tot].v=v;e[tot].next=start[u];
    start[u]=tot++;
    e[tot].v=u;e[tot].next=start[v];
    start[v]=tot++;
}
int l[N],r[N],id[N];
int n;
int idx;
int s[N];
int app[N];
void dfs(int u,int pre){
    id[u]=++idx;
    l[u]=idx;
    for(int i=start[u];i!=-1;i=e[i].next){
        int v=e[i].v;
        if(v==pre) continue;
        dfs(v,u);
    }
    r[u]=idx;
}
void Update(int x,int val){
    for(int i=x;i<=n;i+=lowbit(i))
        s[i]+=val;
}
int sum(int x){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))
        ret+=s[i];
    return ret;
}
int main(){
    //freopen("in.in","r",stdin);
    while(scanf("%d",&n)!=EOF){
        tot=0;mem(start,-1);
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            add(u,v);
        }
        idx=0;
        dfs(1,0);
        mem(s,0);
        for(int i=1;i<=n;i++) s[i]=lowbit(i),app[i]=1;
        int q;
        scanf("%d",&q);
        while(q--){
            char str[5];
            int k;
            scanf("%s%d",str,&k);
            if(str[0]=='C') app[k]^=1,Update(id[k],app[k]?1:-1);
            else printf("%d\n",sum(r[k])-sum(l[k]-1));
        }
    }
    return 0;
}