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
#define M 6000005
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
using namespace std;
int n,a[N],b[N],c[N];
double Threesearch()
{
    double low=0,high=1000,mid,midd;
    double ans=inf;
    while(fabs(high-low)>eps)
    {
        mid=(low+high)/2;midd=(mid+high)/2;
        double t1=-inf,t2=-inf;
        for(int i=0;i<n;i++)
        {
            t1=max(t1,a[i]*mid*mid+b[i]*mid+c[i]);
            t2=max(t2,a[i]*midd*midd+b[i]*midd+c[i]);
        }
        if(t1<t2)
        {
            high=midd;
            ans=min(ans,t1);
        }
        else
        {
            low=mid;
            ans=min(ans,t2);
        }
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&c[i]);
        }
        printf("%.4f\n",Threesearch());
    }
    return 0;
}








