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
int dp[100005],n,m;
int cnt[105],cost[105],val[105];
void zeroonepack(int val,int cost){
	for(int i=m;i>=cost;i--)
		dp[i]=max(dp[i],dp[i-cost]+val);
}
void completepack(int val,int cost){
	for(int i=cost;i<=m;i++)
		dp[i]=max(dp[i],dp[i-cost]+val);
}
void doublepack(int cost,int val,int count){
	if(cost*count>=m)
		completepack(val,cost);
	else{
		int tmp=1;
		while(tmp<=count){
			zeroonepack(val*tmp,cost*tmp);
			count-=tmp;
			tmp<<=1;
		}
		if(count)
	    	zeroonepack(val*count,cost*count);
	}	
}
int main(){
	while(scanf("%d%d",&m,&n)!=EOF){		
		for(int i=0;i<n;i++)
			scanf("%d%d",&cnt[i],&cost[i]);
		memset(dp,0,sizeof(dp));
		for(int i=0;i<n;i++)
	    	doublepack(cost[i],cost[i],cnt[i]);
		int ans=0;
		for(int i=0;i<=m;i++)
	    	ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}