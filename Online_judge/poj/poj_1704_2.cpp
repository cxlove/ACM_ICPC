#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int main(){
	int t,a[1005],b[1005];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int ans=0;
		a[0]=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n+1);
		for(int i=n;i>=1;i-=2){
			b[i]=a[i]-a[i-1]-1;
			ans^=b[i];
		}
		if(ans==0)
			printf("Bob will win\n");
		else
			printf("Georgia will win\n");
	}
	return 0;
}

