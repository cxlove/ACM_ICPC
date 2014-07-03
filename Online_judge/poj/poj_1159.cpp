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
short int dp[2][5005]={0};
char str[5005];
short int Min(short int a,short int b){
	return a<b?a:b;
}
int main(){
	int n;	
	scanf("%d%s",&n,str);
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<n;j++){
			if(str[i]==str[j])
				dp[i&1][j]=dp[(i+1)&1][j-1];
			else
				dp[i&1][j]=Min(dp[(i+1)&1][j]+1,dp[i&1][j-1]+1);
		}
	}
	printf("%d\n",dp[0][n-1]);
	return 0;
}