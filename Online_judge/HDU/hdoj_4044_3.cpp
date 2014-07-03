#include <iostream>

#include <cstdio>
#include <cstring>
#include <vector>
#define N 1005
#define M 205
using namespace std;
int dp[N][M],n,V,tmp[M];
int p[N][55],w[N][55];
vector<int>tree[N];
bool vis[N];
void dfs(int x,int r)
{
    if(vis[x])return;
    vis[x]=true;
    int l=tree[x].size();
    int v,f=0,t;
    for(int i=0; i<l; i++)
    {
        v=tree[x][i];
        if(v==r)continue;
        f=1;
        dfs(v,x);
        for(int j=V; j>=0; j--)
        {
            t=0;//这里和分组背包差不多
            for(int k=0; k<=j; k++)
                t=max(t,min(dp[x][j-k],dp[v][k]));
            dp[x][j]=t; 
        }
    }
    if(f==0)//叶子的情况
    {
        for(int i=0; i<=V; i++)
            dp[x][i]=0;
    }
    for(int i=0; i<=V; i++)
        tmp[i]=dp[x][i];//由于有price=0的武器，所以把背包倒着来并不能保证每组取一个
    for(int i=V; i>=0; i--)//下面就是典型的分组背包。先枚举背包然后物品
    {
        for(int j=1; j<=p[x][0]; j++)
            if(i-p[x][j]>=0)
                dp[x][i]=max(dp[x][i],tmp[i-p[x][j]]+w[x][j]);
        for(int j=0;j<=V;j++)
            tmp[i]=dp[x][i];
    }

}
int main()
{
       int T,x,y,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1; i<=n; i++)tree[i].clear();
        memset(dp,0x6f,sizeof(dp));
        for(int i=1; i<n; i++)
        {
            scanf("%d %d",&x,&y);
            tree[x].push_back(y);
            tree[y].push_back(x);
        }
        scanf("%d",&V);
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&m);
            p[i][0]=w[i][0]=m;
            for(int j=1; j<=m; j++)
            {
                scanf("%d %d",&x,&y);
                p[i][j]=x;
                w[i][j]=y;
            }
        }
        memset(vis,0,sizeof(vis));
        dfs(1,0);
        printf("%d\n",dp[1][V]);
    }
    return 0;
} 

