#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int main(){
	int t,k,cas=0;
	scanf("%d",&t);
	while(t--){
		printf("Scenario #%d:\n",++cas);
		scanf("%d",&k);
		int a[2][2]={0,0,0,0};
		for(int i=0;i<k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x&1][y&1]++;
		}
		long long ans=0;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++){
				long long t=a[i][j];
				ans+=t*(t-1)*(t-2)/6+t*(t-1)/2*(k-t);
			}
		printf("%I64d\n\n",ans);
	}
	return 0;
}