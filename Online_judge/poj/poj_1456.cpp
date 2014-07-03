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
#define sqr(a) ((a)*(a))
using namespace std;
struct Node
{
    int p,d;
    bool operator<(const Node n1)const
    {
        return p!=n1.p?p>n1.p:d>n1.d;
    }
}a[10005];
int pos[10005];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        mem(pos,0);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].p,&a[i].d);
        }
        sort(a,a+n);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int j;
            for(j=a[i].d;j>0;j--)
            {
                if(!pos[j])
                {
                    pos[j]=1;
                    ans+=a[i].p;
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}


