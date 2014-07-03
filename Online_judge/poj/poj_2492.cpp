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
#define inf 1<<30
#define M 60005
#define N 10005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
#define sqr(a) ((a)*(a))
using namespace std;
int pre[2005],r[2005];
int n,m;
int find(int x)
{
    if(x!=pre[x])
    {
        int f=pre[x];
        pre[x]=find(pre[x]);
        r[x]=(r[x]^r[f]);
    }
    return pre[x];
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) pre[i]=i,r[i]=0;
        bool flag=false;
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(flag) continue;
            int ra=find(u),rb=find(v);
            if(ra==rb&&r[u]==r[v]) flag=true;
            else if(ra!=rb)
            {
                pre[ra]=rb;
                r[ra]=r[u]^r[v]^1;
            }
        }
        printf("Scenario #%d:\n",++cas);
        puts(flag?"Suspicious bugs found!\n":"No suspicious bugs found!\n");
    }
    return 0;
}





