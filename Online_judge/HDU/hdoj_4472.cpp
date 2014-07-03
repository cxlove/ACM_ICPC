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
#define inf 100000005
#define M 200005
#define N 100005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000007
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
LL dp[1005]={0};
int main()
{
    int t,cas=0;
    dp[1]=1;
    for(int i=2;i<=1000;i++)
    {
        for(int j=1;j<=i-1;j++)
        {
            if((i-1)%j==0)
            dp[i]=(dp[i]+dp[(i-1)/j])%MOD;
        }
    }
    while(scanf("%d",&t)!=EOF)
    {
        printf("Case %d: %I64d\n",++cas,dp[t]);
    }
    return 0;
}
