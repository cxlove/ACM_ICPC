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
#define inf 1<<25
using namespace std;
int n,m,cnt[105],val[105];
int dp_buy[20005],dp_sale[20005];
void completepack(int *dp,int cost,int limit){
	for(int i=cost;i<=limit;i++)
		dp[i]=min(dp[i],dp[i-cost]+1);
}
void zeroonepack(int *dp,int cost,int limit,int count){
	for(int i=limit;i>=cost;i--)
		dp[i]=min(dp[i],dp[i-cost]+count);
}
void doublepack(int *dp,int cost,int count,int limit){
	if(cost*count>=limit)
		completepack(dp,cost,limit);
	else{
		int tmp=1;
		while(tmp<=count){
			zeroonepack(dp,cost*tmp,limit,tmp);
			count-=tmp;
			tmp<<=1;
		}
		if(count)
	    	zeroonepack(dp,cost*count,limit,count);
	}
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d",&val[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&cnt[i]);
		for(int i=1;i<=m+10000;i++)
			dp_sale[i]=inf;
		for(int i=1;i<=m+10000;i++)
			dp_buy[i]=inf;
		dp_buy[0]=dp_sale[0]=0;
		for(int i=0;i<n;i++)
			completepack(dp_sale,val[i],m+10000);
		for(int i=0;i<n;i++)
			doublepack(dp_buy,val[i],cnt[i],m+10000);
		int ans=inf;
		for(int i=m;i<=m+10000;i++)
			if(dp_buy[i]+dp_sale[i-m]<ans)
				ans=dp_buy[i]+dp_sale[i-m];
		if(ans==inf)
			printf("-1\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}