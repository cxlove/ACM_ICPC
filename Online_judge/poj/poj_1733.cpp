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
#define N 5005
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
struct Node
{
    int u,v;
    char str[10];
}que[N];
int a[N*2],n,q,cnt;
int pre[N*2],r[N*2];
int Bin(int x)
{
    int low=0,high=cnt-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==x) return mid;
        if(a[mid]<x) low=mid+1;
        else high=mid-1;
    }
    return -1;
}
int find(int x)
{
    if(x!=pre[x])
    {
        int f=pre[x];
        pre[x]=find(pre[x]);
        r[x]=r[x]^r[f];
    }
    return pre[x];
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&q);
        cnt=0;
        for(int i=0;i<q;i++)
        {
            scanf("%d%d%s",&que[i].u,&que[i].v,&que[i].str);
            que[i].u--;
            a[cnt++]=que[i].v;a[cnt++]=que[i].u;
        }
        sort(a,a+cnt);
        cnt=unique(a,a+cnt)-a;
        for(int i=0;i<cnt;i++) pre[i]=i,r[i]=0;
        int ans=0;
        for(int i=0;i<q;i++)
        {
            int u=Bin(que[i].u),v=Bin(que[i].v);
            int ra=find(u),rb=find(v);
            if(ra==rb)
            {
                if(r[u]==r[v]&&que[i].str[0]=='o') break;
                if(r[u]!=r[v]&&que[i].str[0]=='e') break;
                ans++;
            }
            else
            {
                if(que[i].str[0]=='o')
                {
                    pre[ra]=rb;
                    r[ra]=r[u]^r[v]^1;
                }
                else
                {
                    pre[ra]=rb;
                    r[ra]=r[u]^r[v];
                }
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

