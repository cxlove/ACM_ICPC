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
#define N 110005
#define maxn 300005
#define eps 1e-8
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
using namespace std;
vector<int>a;
int n,m;
int cmp(int a,int b)
{
    int t=0;
    while(a||b)
    {
        if(a%2!=b%2) t++;
        a/=2;b/=2;
    }
    return t;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        a.clear();
        for(int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            a.pb(k);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<m;i++)
        {
            int k;
            scanf("%d",&k);
            int mmin=100,ans;
            for(int j=0;j<n;j++)
            {
                int tmp=cmp(k,a[j]);
                if(tmp<mmin)
                {
                    mmin=tmp;
                    ans=a[j];
                }
            }
            printf("%d\n",ans);
        }
    }
}


