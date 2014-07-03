/*
ID:cxlove
PROB:poj 2411 Mondriaan's Dream
DATA:2012.1.10
HINT:状态压缩DP
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
LL dp[12][1<<11];
int h,w;
void dfs(int i,int j,int temp,int idx){
	if(idx>=w){
		dp[i+1][temp]+=dp[i][j];
		return ;
	}
	if((1<<idx&j)==0){
		if((1<<(idx+1)&j)==0&&idx+1<w)
			dfs(i,j,temp,idx+2);
		if(i+2<=h)
			dfs(i,j,temp+(1<<idx),idx+1);
	}
	else
		dfs(i,j,temp,idx+1);
}
int main(){
	while(cin>>h>>w){
		if(!h&&!w) break;
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0;i<h;i++)
			for(int j=0;j<(1<<w);j++)
				dfs(i,j,0,0);
		LL ans=0;
		for(int i=0;i<(1<<w);i++)
			ans+=dp[h][i];
		cout<<ans<<endl;
	}
	return 0;
}