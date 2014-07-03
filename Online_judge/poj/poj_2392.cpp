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
struct Node{
	int cnt,cost,limit;
}a[405];
bool cmp(Node n1,Node n2){
	return n1.limit<n2.limit;
}
int dp[40005],n,m;
void zeroonepack(int val,int cost,int limit){
	for(int i=limit;i>=cost;i--)
		dp[i]=max(dp[i],dp[i-cost]+val);
}
void completepack(int val,int cost,int limit){
	for(int i=cost;i<=limit;i++)
		dp[i]=max(dp[i],dp[i-cost]+val);
}
void doublepack(int cost,int val,int count,int limit){
	if(cost*count>=limit)
		completepack(val,cost,limit);
	else{
		int tmp=1;
		while(tmp<=count){
			zeroonepack(val*tmp,cost*tmp,limit);
			count-=tmp;
			tmp<<=1;
		}
		if(count)
			zeroonepack(val*count,cost*count,limit);
	}	
}
int main(){
	while(scanf("%d",&n)!=EOF){	
		m=0;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&a[i].cost,&a[i].limit,&a[i].cnt);
			m=max(m,a[i].limit);
		}
		memset(dp,0,sizeof(dp));
		sort(a,a+n,cmp);
		for(int i=0;i<n;i++)
	    	doublepack(a[i].cost,a[i].cost,a[i].cnt,a[i].limit);
		int ans=0;
		for(int i=0;i<=m;i++)
	    	ans=max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}