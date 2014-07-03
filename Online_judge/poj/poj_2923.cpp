#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-6
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1<<30
using namespace std;
int n,c1,c2,cnt,w[10];
int ok[1<<10];    //能一次装过去的可行状态
int dp[1<<10]; 
bool judge(int state){
	int sum=0;
	int f[105];
	memset(f,0,sizeof(f));
	f[0]=1;
	for(int i=0;i<n;i++)
		if((1<<i)&state){
			sum+=w[i];
			for(int j=c1;j>=w[i];j--)
				f[j]=max(f[j-w[i]],f[j]);
		}	
	if(sum>c1+c2)
		return false;
	for(int i=0;i<=c1;i++)
		if(f[i]&&sum-i<=c2)
			return true;
	return false;
}
int main(){
	int t,cas=0;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&c1,&c2);
		for(int i=0;i<n;i++)
			scanf("%d",&w[i]);
		cnt=0;
		for(int i=0;i<(1<<n);i++){
			dp[i]=inf;
			if(judge(i))
				ok[cnt++]=i;
		}
		dp[0]=0;
		for(int i=0;i<cnt;i++)
			for(int j=0;j<(1<<n);j++)
				if(!(ok[i]&j))
					dp[j|ok[i]]=min(dp[j|ok[i]],dp[j]+1);
		printf("Scenario #%d:\n%d\n\n",++cas,dp[(1<<n)-1]);
	}
	return 0;
}