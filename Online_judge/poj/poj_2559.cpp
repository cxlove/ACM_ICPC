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
#define M 1000005
#define N 50005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1,l,m
#define rson step<<1|1,m+1,r
#define MOD 1073741824
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
using namespace std;
int a[100005],n;
int l[100005],r[100005];
int main()
{
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[0]=-1;a[n+1]=-1;
        for(int i=1;i<=n;i++)
        {
            int j=i-1;
            while(a[i]<=a[j]) j=l[j]-1;
            l[i]=j+1;
        }
        for(int i=n;i>0;i--)
        {
            int j=i+1;
            while(a[i]<=a[j]) j=r[j]+1;
            r[i]=j-1;
        }
        LL ans=0;
        for(int i=1;i<=n;i++)
        {
            if((LL)(r[i]-l[i]+1)*a[i]>ans)
                 ans=(LL)(r[i]-l[i]+1)*a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}



