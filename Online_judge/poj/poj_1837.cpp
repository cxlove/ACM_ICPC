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
int c,g,C[25],G[25];
int dp[25][15005];
int a[25][25];
int main(){
	int m=15000;
	while(scanf("%d%d",&c,&g)!=EOF){
		for(int i=1;i<=c;i++)
			scanf("%d",&C[i]);
		for(int i=1;i<=g;i++)
			scanf("%d",&G[i]);
		for(int i=1;i<=g;i++)
			for(int j=1;j<=c;j++)
				a[i][j]=C[j]*G[i];
		memset(dp,0,sizeof(dp));
		dp[0][7500]=1;
		for(int i=1;i<=g;i++)
			for(int j=m;j>=0;j--)
				for(int k=1;k<=c;k++)
					if(j-a[i][k]>=0)
						dp[i][j]+=dp[i-1][j-a[i][k]];
		printf("%d\n",dp[g][7500]);
	}
	return 0;
}
	