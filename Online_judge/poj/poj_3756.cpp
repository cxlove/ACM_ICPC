#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#define eps 1e-8
#define zero(a) fabs(a)<eps
using namespace std;
int n,m,u,v;
int step[105],stop[105];
double dp[1005][105];
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(step,0,sizeof(step));
		memset(stop,0,sizeof(stop));
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&u,&v);
			step[u]=v;
		}
		scanf("%d",&m);
		while(m--){
			scanf("%d%d",&u,&v);
			step[u]=-v;
		}
		scanf("%d",&m);
		while(m--){
			scanf("%d",&u);
			stop[u]=1;
		}
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=1;i<1000;i++){
			for(int j=0;j<n;j++){
				if(zero(dp[i-1][j])) continue;
				for(int k=1;k<=6;k++){
					int cur=j+k;
					if(cur>n) cur=2*n-cur;
					if(stop[cur]){
						dp[i+1][cur]+=1.0/6*dp[i-1][j];
						continue;
					}
					cur+=step[cur];
					if(cur>n) cur=2*n-cur;
					if(cur<0) cur=-cur;
					dp[i][cur]+=1.0/6*dp[i-1][j];
				}
			}
		}
		double ans=0;
		for(int i=1;i<1000;i++)
			ans+=i*dp[i][n];
		if(zero(ans)) puts("Impossible");
		else printf("%.2f\n",ans);
	}
	return 0;
}

