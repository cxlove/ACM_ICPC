#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[21][1<<13+5];
int n,a[21],s;
int DP(int idx,int remain){
	if(dp[idx][remain]!=-1)
		return dp[idx][remain];
	if(remain==0){
		if(idx%2==1)
			return dp[idx][remain]=1;
		else
			return dp[idx][remain]=0;
	}
	if(idx%2==1) dp[idx][remain]=0;
	else dp[idx][remain]=1;
	for(int i=1;i<=a[idx];i++){
		if(i>remain) break;
		int t=DP((idx%(2*n))+1,remain-i);
		if((idx%2)==1&&t==1) dp[idx][remain]=1;
		else if((idx%2)==0&&t==0) dp[idx][remain]=0;
	}
	return dp[idx][remain];
}
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		scanf("%d",&s);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]);
		memset(dp,-1,sizeof(dp));
		printf("%d\n",DP(1,s));
	}
	return 0;
}