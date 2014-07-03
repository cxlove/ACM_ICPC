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
#define M 20005
#define N 5000005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int dp[N],fac[N];
void Init()
{
    dp[3]=1;
    for(int i=4;i<N;i++)
    {
        dp[i]=dp[i-1]-ceil(i/3.0)+floor((i-1)/2.0)+1;
        if(!(i&1)) dp[i]-=floor((i-(i-1)/2.0)/2.0);
        if(dp[i]>=MOD) dp[i]-=MOD;
        if(dp[i]<0) dp[i]+=MOD;
    }
    fac[1]=1;fac[2]=2;
    for(int i=3;i<N;i++)
    {
        fac[i]=fac[i-1]*2;
        if(fac[i]>=MOD) fac[i]-=MOD;
        for(int j=2;i*j<N;j++)
        {
            dp[j*i]-=dp[i];
            if(dp[j*i]<0) dp[j*i]+=MOD;
        }
    }
}
int main()
{
    Init();
    int cas=0,n;
    while(cin>>n)
    {
        LL ans=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i) continue;
            ans=(ans+(LL)dp[i]*fac[n/i])%MOD;
            if(i*i!=n) ans=(ans+(LL)dp[n/i]*fac[i])%MOD;
        }
        cout<<"Case "<<++cas<<": "<<ans<<endl;
    }
    return 0;
}
