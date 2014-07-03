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
int dp[205][25][1005],pre[205][25][1005];
int d[205],p[205],s[205],ans[25];
int main()
{
    int cas=0,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&d[i],&p[i]);
            s[i]=d[i]-p[i];
        }
        mem(dp,-1);
        mem(pre,-1);
        int zero=m*20;
        for(int i=0;i<=n;i++)
        dp[i][0][zero]=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m&&j<=i; j++)
            {
                for(int k=0; k<=2*zero; k++)
                {
                    pre[i][j][k]=pre[i-1][j][k];
                    dp[i][j][k]=dp[i-1][j][k];
                    int tmp=k-s[i];
                    if(tmp>=0&&tmp<=2*zero&&dp[i-1][j-1][tmp]<0) continue;
                    if(dp[i-1][j-1][tmp]+d[i]+p[i]>dp[i][j][k])
                    {
                        dp[i][j][k]=dp[i-1][j-1][tmp]+d[i]+p[i];
                        pre[i][j][k]=i;
                    }
                }
            }
        }

        int sum=-1,best;
        for(int i=0; i<=zero; i++)
        {
            if(dp[n][m][zero+i]>=0||dp[n][m][zero-i]>=0)
            {
                if(dp[n][m][zero-i]>sum)
                {
                    sum=dp[n][m][zero-i];
                    best=zero-i;
                }
                if(dp[n][m][zero+i]>sum)
                {
                    sum=dp[n][m][zero+i];
                    best=zero+i;
                }
                break;
            }
        }
      //  cout<<sum<<" "<<best<<endl;
        printf("Jury #%d\n",++cas);
        int j=m,sumd=0,sump=0,id=pre[n][m][best];
        while(j)
        {
            ans[j-1]=id;
            sumd+=d[id];
            sump+=p[id];
            best-=s[id];
            id=pre[id-1][j-1][best];

        j--;
        }
        sort(ans,ans+m);
        printf("Best jury has value %d for prosecution and value %d for defence:\n",sumd,sump);
        for(int i=0; i<m; i++) printf(" %d",ans[i]);
        printf("\n\n");
    }
    return 0;
}




