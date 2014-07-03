/*
ID:cxlove
PROB:Colored stones
/*
ID:cxlove
PROB:Colored stones
DATA:2012.3.12
HINT:状态压缩DP
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[101][1<<5][6],n,m,a[101];
int main(){
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=0;j<(1<<m);j++)
				if((1<<(a[i]-1))&j)
					for(int k=1;k<=m;k++)
						if(a[i]==k)
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+1);
						else
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);		
				else
					for(int k=1;k<=m;k++){
						dp[i][(1<<(a[i]-1))|j][a[i]]=max(dp[i][j|(1<<(a[i]-1))][a[i]],dp[i-1][j][k]+1);
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]);
					}
		int ans=0;
		for(int i=0;i<(1<<m);i++)
			for(int j=1;j<=m;j++)
				ans=max(ans,dp[n][i][j]);
		printf("%d\n",n-ans);			
	}
	return 0;
}