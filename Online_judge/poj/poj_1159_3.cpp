/*
ID:cxlove
PROB:Palindrome 
DATA:2012.3.8
HINT:DP
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1<<30
using namespace std;
short int dp[5005][5005];
char str[5005];
short int Min(short int a,short int b){
	return a<b?a:b;
}
int main(){
	int n;	
	scanf("%d%s",&n,str);
	for(int i=0;i<n;i++){
	//	for(int j=0;j<n;j++)
	//		dp[i][j]=inf;
		dp[i][i]=0;
	}
	for(int i=0;i<n-1;i++)
		if(str[i]==str[i+1])
			dp[i][i+1]=0;
		else
			dp[i][i+1]=1;
	for(int k=2;k<=n-1;k++){
		for(int i=0;i<n-k;i++){
			if(str[i]==str[i+k])
				dp[i][i+k]=dp[i+1][i+k-1];
			else
				dp[i][i+k]=dp[i+1][i+k-1]+2;
			dp[i][i+k]=Min(dp[i+1][i+k]+1,Min(dp[i][i+k],dp[i][i+k-1]+1));
		}
	}
	printf("%d\n",dp[0][n-1]);
	return 0;
}