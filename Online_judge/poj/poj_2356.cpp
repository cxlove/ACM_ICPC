#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n,k;
	int a[10005]={0},b[10005];
	while(scanf("%d",&n)!=EOF){
		bool flag=false;
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			if(flag) continue;
			a[i]=a[i-1]+k;
			if(a[i]%n==0){
				printf("%d\n",i);
				for(int j=1;j<=i;j++)
					printf("%d\n",a[j]-a[j-1]);
				flag=true;
			}
			else if(b[a[i]%n]){
				printf("%d\n",i-b[a[i]%n]);
				for(int j=b[a[i]%n]+1;j<=i;j++)
					printf("%d\n",a[j]-a[j-1]);
				flag=true;
			}
			else
				b[a[i]%n]=i;
		}
	}
	return 0;
}