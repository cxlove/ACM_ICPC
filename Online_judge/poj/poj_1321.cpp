/*
ID:cxlove
PROB:poj 1321 棋盘问题
DATA:2012.1.9
HINT:状态压缩DP
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n,k;
	int s[1<<8]={0};
	int dp[10][1<<8]={0};
	int mmap[10];
	int pre[1<<8][1<<8]={0};
	char str[10][10];
	while(cin>>n>>k){
		if(n==-1&&k==-1)
			break;
		memset(mmap,0,sizeof(mmap));
		memset(pre,0,sizeof(pre));
		memset(dp,0,sizeof(dp));
    	for(int i=1;i<=n;i++){
	    	cin>>str[i];
			for(int j=0;j<n;j++)
				if(str[i][j]=='.')
					mmap[i]+=(1<<j);
		}
    	for(int i=1;i<(1<<n);i++)
			s[i]=s[i>>1]+i%2;
		for(int i=0;i<(1<<n);i++)
			for(int j=0;j<(1<<n);j++)
				if(s[j]==s[i]+1&&s[i^j]==1)
					pre[j][++pre[j][0]]=i;		
		dp[0][0]=1;
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<(1<<n);j++){
				if(s[j]>i) continue;
				for(int k=1;k<=pre[j][0];k++){
					if(((j-pre[j][k])&mmap[i])==0){
			    		dp[i][j]+=dp[i-1][pre[j][k]];
					}
				}
				if(s[j]<=i-1)
					dp[i][j]+=dp[i-1][j];
				if(i==n&&s[j]==k)
					ans+=dp[i][j];
			}
		}
		cout<<ans<<endl;		
	}
	return 0;
}