/*
ID;cxlove
PROB:tzc 搬寝室 
DATA;2012.3.6
HINT:DP
*/
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,k,val[2005],dp[2005][1005];
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&val[i]);
        sort(val+1,val+1+n);
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
            for(int j=1;j<=k;j++)
                dp[i][j]=1<<30;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=n/2;j++)
                dp[i][j]=min(dp[i-1][j],dp[i-2][j-1]+(val[i]-val[i-1])*(val[i]-val[i-1]));
        }
        printf("%d\n",dp[n][k]);
    }
    return 0;
}