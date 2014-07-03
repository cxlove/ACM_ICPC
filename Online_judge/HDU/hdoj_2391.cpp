#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[1005][1005],a[1005][1005];
int main(){
    int t,n,m,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        dp[0][0]=a[0][0];
        for(int i=1;i<m;i++)
            dp[0][i]=dp[0][i-1]+a[0][i];
        for(int i=1;i<n;i++){
            dp[i][0]=dp[i-1][0]+a[i][0];
            for(int j=1;j<m;j++)
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
        printf("Scenario #%d:\n%d\n\n",++cas,dp[n-1][m-1]);
    }
    return 0;
}