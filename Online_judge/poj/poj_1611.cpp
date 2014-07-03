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
int pre[300005],cnt[300005],flag[300005];
int find(int x)
{
    return pre[x]=(x==pre[x]?x:find(pre[x]));
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n+m)
    {
        for(int i=0;i<n;i++) pre[i]=i,cnt[i]=1,flag[i]=0;
        flag[0]=1;
        int ans=1;
        while(m--)
        {
            int k,u,v;
            scanf("%d",&k);
            if(k==0) continue;
            scanf("%d",&u);
            for(int i=1;i<k;i++)
            {
                scanf("%d",&v);
                int ru=find(u),rv=find(v);
                if(ru!=rv)
                {
                    pre[rv]=ru;
                    cnt[ru]+=cnt[rv];
                    if(flag[rv])
                    {
                        flag[ru]=1;
                    }
                    if(flag[ru]) ans=cnt[ru];
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}







