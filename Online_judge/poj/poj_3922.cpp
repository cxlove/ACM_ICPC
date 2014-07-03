#include<iostream>
#include<cstdio>
#include<cstring>
#define N 2000000
using namespace std;
int a[N],b[N];
int n,k,t,cas=0;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		int i=0,j=0;
		a[0]=b[0]=1;
		while(a[i]<n){
			i++;
			a[i]=b[i-1]+1;
			while(a[j+1]*k<a[i])
				j++;
			if(a[j]*k<a[i])
				b[i]=b[j]+a[i];
			else
				b[i]=a[i];
		}
		printf("Case %d: ",++cas);
		if(a[i]==n)
			puts("lose");
		else{
			int ans;
			while(n){
				if(n>=a[i]){
					n-=a[i];
					ans=a[i];
				}
				i--;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}