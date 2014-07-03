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
int pre[100005],r[100005];
int find(int x)
{
    if(x!=pre[x])
    {
        int father=pre[x];
        pre[x]=find(pre[x]);
        r[x]=(r[x]^r[father]);
    }
    return pre[x];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            pre[i]=i;
            r[i]=0;
        }
        char str[10];int a,b;
        while(m--)
        {
            scanf("%s%d%d",str,&a,&b);
            if(str[0]=='D')
            {
                int ra=find(a),rb=find(b);
                if(ra!=rb)
                {
                    pre[ra]=rb;
                    r[ra]=(r[a]^r[b])^1;
                }
            }
            else
            {
                int ra=find(a),rb=find(b);
                if(ra!=rb) printf("Not sure yet.\n");
                else if(ra==rb&&r[a]==r[b]) printf("In the same gang.\n");
                else printf("In different gangs.\n");
            }
        }
    }
    return 0;
}


