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
int pre[50005];
int find(int x)
{
    return pre[x]=(x==pre[x]?x:find(pre[x]));
}
int main()
{
    int n,m,cas=0,u,v;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        for(int i=1;i<=n;i++) pre[i]=i;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            int ra=find(u),rb=find(v);
            if(ra!=rb) pre[ra]=rb;
        }
        int ans=0;
        for(int i=1;i<=n;i++) if(pre[i]==i) ans++;
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}


