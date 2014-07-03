#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<ctime>
#include<sstream>
#include<cassert>
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define inf 1<<20
#define N 100005
#define pi acos(-1.0)
#define pb(a) push_back(a)
#define lson step<<1
#define rson step<<1|1
using namespace std;
struct Node{
    int v,w,next;
}edge[100005];
int start[1005],tot;
int n,m,dp[1005];
void addedge(int u,int v,int w){
    edge[tot].v=v;edge[tot].w=w;
    edge[tot].next=start[u];
    start[u]=tot++;
}
void _addedge(int u,int v,int w){
    addedge(u,v,w);
    addedge(v,u,w);
}
void dfs(int u,int limit,int pre){
    bool flag=false;
    for(int i=start[u];i!=-1;i=edge[i].next){
        int v=edge[i].v,w=edge[i].w;
        if(v==pre) continue;
        flag=true;
        dfs(v,limit,u);
        dp[u]+=min(dp[v],w>limit?inf:w);
    }
    if(!flag) dp[u]=inf;
}
bool check(int limit){
    memset(dp,0,sizeof(dp));
    dfs(1,limit,-1);
   // cout<<limit<<" "<<dp[1]<<" "<<dp[2]<<" "<<dp[3]<<" "<<dp[4]<<endl;
    if(dp[1]>m) return false;
    return true;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
        tot=0;memset(start,-1,sizeof(start));
        for(int i=1;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            _addedge(u,v,w);
        }
        int low=0,high=m,mid,ok=0,ans=-1;
        while(low<=high){
            mid=(low+high)/2;
            if(check(mid)) {ans=mid;high=mid-1;}
            else low=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}






