#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 200005
#define MOD 1000000007
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
struct Node
{
    int u,v,w;
    bool operator< (const Node n1) const
    {
        return w>n1.w;
    }
}edge[N];
int cnt[N],pre[N];
LL sum[N];
int find(int a)
{
    return pre[a]=(a==pre[a]?a:find(pre[a]));
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n-1;i++)
        {
            scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
        }
        sort(edge,edge+n-1);
        for(int i=1;i<=n;i++)
        {
            sum[i]=0;
            pre[i]=i;
            cnt[i]=1;
        }
        LL ans=0;
        for(int i=0;i<n-1;i++)
        {
            int ra=find(edge[i].u);
            int rb=find(edge[i].v);
            LL atob=(LL)cnt[ra]*edge[i].w+sum[rb];
            LL btoa=(LL)cnt[rb]*edge[i].w+sum[ra];
            if(atob>btoa)
            {
                pre[ra]=rb;
                cnt[rb]+=cnt[ra];
                sum[rb]=atob;
            }
            else
            {
                pre[rb]=ra;
                cnt[ra]+=cnt[rb];
                sum[ra]=btoa;
            }
            ans=max(ans,max(atob,btoa));
        }
        printf("%I64d\n",ans);
    }
    return 0;
}