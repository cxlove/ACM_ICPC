/*
ID:cxlove
PROB:poj 1185 炮兵阵地
DATA:2012.1.10
HINT:状态压缩DP
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
char str[105][15];
int dp[101][100][100]={0};
int mmap[101]={0};
int a[100],b[100]={0},count=0;
int pre[100][100][100]={0};
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>str[i];
		for(int j=0;j<m;j++)
			if(str[i][j]=='H')
				mmap[i]+=(1<<j);
	}
	for(int i=0;i<(1<<m);i++)
		if((i<<1&i)==0&&(i<<2&i)==0){
			a[++count]=i;
			int temp=i;
			b[count]=temp%2;
			while(temp=temp>>1)
				b[count]+=temp%2;
		}
	for(int i=1;i<=count;i++)
		for(int j=1;j<=count;j++)
			for(int k=1;k<=count;k++)
				if((a[i]&a[j])==0&&(a[i]&a[k])==0&&(a[j]&a[k])==0)
					pre[j][k][++pre[j][k][0]]=i;
	for(int i=1;i<=count;i++)
		if((mmap[1]&a[i])==0)
	    	dp[1][1][i]=b[i];
	for(int i=1;i<=count;i++)
		for(int j=1;j<=count;j++)
			if((a[i]&mmap[1])==0&(a[j]&mmap[2])==0&&(a[i]&a[j])==0)
				dp[2][i][j]=b[i]+b[j];
	int ans=0;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=count;j++){
			for(int k=1;k<=count;k++){
				if(mmap[i]&a[k]||mmap[i-1]&a[j]) continue;
				for(int r=1;r<=pre[j][k][0];r++)
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][pre[j][k][r]][j]+b[k]);
			}
		}
	}
	for(int i=1;i<=count;i++)
		for(int j=1;j<=count;j++)
			ans=max(ans,dp[n][i][j]);
	cout<<ans<<endl;
	return 0;
}