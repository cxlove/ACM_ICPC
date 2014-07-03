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
struct Node
{
    int u,v,k;
}a[2005];
int n,m;
int pre[505],r[505];
int error[505];
void Init()
{
    for(int i=0;i<n;i++) pre[i]=i,r[i]=0;
}
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
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<m;i++)
        {
            scanf("%d",&a[i].u);
            char ch;
            while((ch=getchar())==' ');
            scanf("%d",&a[i].v);
            a[i].k=(ch=='=')?0:(ch=='<'?1:2);
        }
        mem(error,-1);
        for(int i=0;i<n;i++)
        {
            Init();
            for(int j=0;j<m;j++)
            {
                if(i==a[j].u||i==a[j].v) continue;
                int ra=find(a[j].u),rb=find(a[j].v);
                if(ra==rb)
                {
                    if(a[j].k==0&&r[a[j].u]!=r[a[j].v]) {error[i]=j+1;break;}
                    if(a[j].k==1&&(r[a[j].u]+1)%3!=r[a[j].v]) {error[i]=j+1;break;}
                    if(a[j].k==2&&(r[a[j].u]+2)%3!=r[a[j].v]) {error[i]=j+1;break;}
                }
                else
                {
                    pre[rb]=ra;
                    r[rb]=(r[a[j].u]-r[a[j].v]+3+a[j].k+r[ra])%3;
                }
            }
        }
        int cnt=0,a1=0,a2=0;
        for(int i=0;i<n;i++)
        {
            if(error[i]==-1)
            {
                cnt++;
                a1=i;
            }
            a2=max(a2,error[i]);
        }
        if(cnt==0) puts("Impossible");
        else if(cnt>1) puts("Can not determine");
        else printf("Player %d can be determined to be the judge after %d lines\n",a1,a2);
    }
    return 0;
}


