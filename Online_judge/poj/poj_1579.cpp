/*
ID:cxlove
PROB:Function Run Fun 
DATA:2012.3.7
HINT:DP
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[100][100][100];
int DP(int a,int b,int c){
	if(a<=0||b<=0||c<=0)
		return 1;
	if(dp[a][b][c]!=-1)
		return dp[a][b][c];
	if(a>20||b>20||c>20)
		return dp[a][b][c]=DP(20,20,20);
	if(a<b&&b<c)
		return dp[a][b][c]=DP(a,b,c-1)+DP(a,b-1,c-1)-DP(a,b-1,c);
	return dp[a][b][c]=DP(a-1,b,c)+DP(a-1,b-1,c)+DP(a-1,b,c-1)-DP(a-1,b-1,c-1);
}
int main(){
	int a,b,c;
	memset(dp,-1,sizeof(dp));
	while(scanf("%d%d%d",&a,&b,&c)!=EOF)
		if(a==-1&&b==-1&&c==-1)
			break;
		else
	    	printf("w(%d, %d, %d) = %d\n",a,b,c,DP(a,b,c));
	return 0;
}