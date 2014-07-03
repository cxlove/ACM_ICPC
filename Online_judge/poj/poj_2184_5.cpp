#include<iostream>
#define MAX(a,b)  a>b?a:b
#define INF -10000000
using namespace std;
int dp[200005];
int main()
{
    int n;
    int s[105],f[105];
    cin>>n;
    for(int i=1;i<=n;i++)
       cin>>s[i]>>f[i];
    for(int i=0;i<=200000;i++)
       dp[i]=INF;
       dp[100000]=0;
    for(int i=1;i<=n;i++)
    {
         if(s[i]<0&&f[i]<0)  continue;
         if(s[i]>0)
         {
             for(int j=200000;j>=s[i];j--)
             {
                     if(dp[j-s[i]]>INF)
                  dp[j]=MAX(dp[j],dp[j-s[i]]+f[i]);
             }
         }
         else
         {
             for(int j=s[i];j<=200000+s[i];j++)
             {
                     if(dp[j-s[i]]>INF)
                  dp[j]=MAX(dp[j],dp[j-s[i]]+f[i]);
             }
         }
    }
    int ans=0;
    for(int i=100000;i<=200000;i++)
        if(dp[i]>=0)
            ans=MAX(ans,dp[i]+i-100000);
    cout<<ans<<endl;
    return 0;
}