#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int INF=0xFFFFFF;
struct node
{
	int h,t;
}a[80];
bool cmp(struct node s1,struct node s2)
{
	return s1.h>s2.h;
}
int dp[2105][2105];
int main(){
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,sum=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&a[i].h,&a[i].t);
			sum+=a[i].t;
		}
		sort(a,a+n,cmp);
		for(int i=0;i<=sum;i++)
			for(int j=0;j<=sum;j++)
				dp[i][j]=INF;
		dp[0][0]=0;
		int tmax=0;
		for (int i = 1; i < n; ++i) 
		{	
			int h = a[i].h, t = a[i].t;		
			tmax += t;
			for (int j = tmax, jj = tmax - t; j >= 0; --j, --jj)				
				for (int k = tmax, kk = tmax - t; k >= 0; --k, --kk) 
				{
				if (jj > 0 && dp[jj][k] < dp[j][k])
					dp[j][k] = dp[jj][k];
				if (!jj && dp[0][k] + h < dp[j][k])
					dp[j][k] = dp[0][k] + h;
				if (kk > 0 && dp[j][kk] < dp[j][k])
					dp[j][k] = dp[j][kk];
				if (!kk && dp[j][0] + h < dp[j][k])
					dp[j][k] = dp[j][0] + h;									
				}	
		}
        int ans = INF;
    	for (int j = 1; j <= tmax; ++j)
		for (int k = 1; k <= tmax; ++k)
			if (dp[j][k] < INF)
			{
				ans = min(ans,(a[0].h + dp[j][k]) * max(max(j, k), sum - j - k));
			}

		
		printf("%d\n",ans);	
	}
	return 0;
}
