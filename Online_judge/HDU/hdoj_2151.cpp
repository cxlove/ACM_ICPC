/*
ID:cxlove
PROB:WORM
DATA:2013.3.6
HINT:DP
*/
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n,p,m,t;
    int dp[105][105];
    while(scanf("%d%d%d%d",&n,&p,&m,&t)!=EOF){
        memset(dp,0,sizeof(dp));
        dp[m][t]=1;
        for(int i=m-1;i>=0;i--){
            dp[i][1]=dp[i+1][2];
            dp[i][n]=dp[i+1][n-1];
            for(int j=2;j<n;j++)
                dp[i][j]=dp[i+1][j-1]+dp[i+1][j+1];
        }
        printf("%d\n",dp[0][p]);
    }
    return 0;
}
