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
		sum=0;	
		for(int k=1;k<n;k++)
		{
			sum+=a[k].t;
			for(int i=sum;i>=0;i--)
			{		
				for(int j=sum;j>=0;j--)			
				{		
					if(i==a[k].t&&dp[0][j]+a[k].h<dp[i][j])
						dp[i][j]=dp[0][j]+a[k].h;
					if(j==a[k].t&&dp[i][0]+a[k].h<dp[i][j])
						dp[i][j]=dp[i][0]+a[k].h;
					if(i>a[k].t&&dp[i-a[k].t][j]<dp[i][j])
						dp[i][j]=dp[i-a[k].t][j];
					if(j>a[k].t&&dp[i][j-a[k].t]<dp[i][j])
						dp[i][j]=dp[i][j-a[k].t];
				}
			}
		}
		int ans=INF;
		for(int i=1;i<=sum;i++)
			for(int j=1;j<=sum;j++)
				if(dp[i][j]!=INF)			
					ans=min(ans,(a[0].h+dp[i][j])*max(sum+a[0].t-i-j,max(i,j)));
		printf("%d\n",ans);	
	}
	return 0;
}
