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
int m,cnt[4],cost[4]={1,5,10,25},num[4][10005],dp[10005];
int main(){
	while(scanf("%d%d%d%d%d",&m,&cnt[0],&cnt[1],&cnt[2],&cnt[3])!=EOF&&m+cnt[0]+cnt[1]+cnt[2]+cnt[3]){
		for(int i=1;i<=m;i++)
			dp[i]=-1;
		dp[0]=0;
		memset(num,0,sizeof(num));
		for(int i=0;i<4;i++){
		//	for(int j=0;j<cnt[i];j++)
				for(int k=cost[i];k<=m;k++)
					if(dp[k-cost[i]]!=-1&&dp[k]<dp[k-cost[i]]+1&&num[i][k-cost[i]]+1<=cnt[i]){
						dp[k]=dp[k-cost[i]]+1;
						num[i][k]=num[i][k-cost[i]]+1;
						for(int r=0;r<i;r++)
							num[r][k]=num[r][k-cost[i]];
					}
		}
		if(dp[m]!=-1)
			printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n",num[0][m],num[1][m],num[2][m],num[3][m]);
		else
			printf("Charlie cannot buy coffee.\n");

	}
}