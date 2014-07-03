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
int dp[200005];
int n;
int MAX=100000;
int f[100],s[100];
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%d%d",&s[i],&f[i]);
		for(int i=0;i<=200000;i++)
			dp[i]=-inf;
		dp[100000]=0;
		for(int i=0;i<n;i++){
			if(s[i]<0){
				for(int j=0;j<=200000+s[i];j++)
					dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
			}
			else{
				for(int j=200000;j>=s[i];j--)
					dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
			}
		}
		int ans=-inf;
		for(int i=100000;i<=200000;i++)
			if(dp[i]>=0)
				ans=max(ans,dp[i]+i-100000);
		printf("%d\n",ans);
	}
	return 0;
}
	