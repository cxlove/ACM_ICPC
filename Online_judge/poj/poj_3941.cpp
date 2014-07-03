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
#define inf 1<<28
#define M 6000005
#define N 100005
#define maxn 300005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
#define eps 1e-8
#define zero(a) (fabs(a)<eps)
using namespace std;
double c1[N],c2[N];
int n,m,k;
int main()
{
    while(scanf("%d%d%d",&n,&m,&k)!=EOF&&n+m+k)
    {
        for(int i=1;i<=m;i++)
        {
            c1[i]=1.0/m;
            c2[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=m*i;j++)
            {
                for(int k=1;k<=m;k++)
                {
                    c2[j+k]+=c1[j]*1.0/m;
                }
            }
            for(int j=1;j<=m*i+m;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        double ans=0;
        for(int i=1;i<=n*m;i++)
        {
            if(i>k) ans+=c1[i]*(i-k);
            else ans+=c1[i];
        }
        printf("%.8f\n",ans);
    }
    return 0;
}



