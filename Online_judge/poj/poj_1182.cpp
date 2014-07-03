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
#define N 605
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
int n,K;
int r[50005];//为0说明是同类，为1说明被根吃，为2说明吃根
int find(int x)
{
    if(x!=pre[x])
    {
        int f=pre[x];
        pre[x]=find(pre[x]);
        r[x]=(r[x]+r[f])%3;
    }
    return pre[x];
}
int main()
{
    scanf("%d%d",&n,&K);
    for(int i=1; i<=n; i++) pre[i]=i,r[i]=0;
    int ans=0;
    while(K--)
    {
        int k,u,v;
        scanf("%d%d%d",&k,&u,&v);
        if(u<0||v<0||u>n||v>n||(u==v&&k==2)) ans++;
        else
        {
            int ra=find(u),rb=find(v);
            if(ra==rb)
            {
                if(k==1&&r[u]!=r[v]) ans++;
                if(k==2&&(r[u]+1)%3!=r[v]) ans++;
            }
            else
            {
                pre[rb]=ra;
                r[rb]=(r[u]-r[v]+2+k)%3;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}


