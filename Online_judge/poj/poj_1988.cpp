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
using namespace std;
int pre[30005],cnt[30005],num[30005];
int find(int x)
{
    if(x!=pre[x])
    {
        int f=pre[x];
        pre[x]=find(pre[x]);
        num[x]+=num[f];
    }
    return pre[x];
}
int main()
{
    int n=30000,p;
    while(scanf("%d",&p)!=EOF)
    {
        for(int i=1;i<=n;i++) pre[i]=i,cnt[i]=1,num[i]=0;
        while(p--)
        {
            char str[15];
            int u,v;
            scanf("%s",str);
            if(str[0]=='M')
            {
                scanf("%d%d",&u,&v);
                int rv=find(v),ru=find(u);
                if(rv!=ru)
                {
                    pre[ru]=rv;
                    num[ru]+=cnt[rv];
                    cnt[rv]+=cnt[ru];
                }
            }
            else
            {
                scanf("%d",&u);
                find(u);
                printf("%d\n",num[u]);
            }
        }
    }
    return 0;
}


