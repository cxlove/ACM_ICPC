#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
using namespace std;
int a[100],b[100];
int prime[10000],count=0,cnt;
bool flag[2000005]={0};
void Prime(){
	for(int i=2;i<=1200;i++){
		if(flag[i]) continue;
		for(int j=2;j*i<=1300000;j++)
			flag[i*j]=true;
	}
}
int main(){
	int n;
	Prime();
	while(scanf("%d",&n)!=EOF&&n){
		int ans=1;
		if(!flag[n]){
			printf("0\n");
			continue;
		}
		for(int i=n-1;;i--)
			if(flag[i])
				ans++;
			else
				break;
		for(int i=n+1;;i++)
			if(flag[i])
				ans++;
			else
				break;
		printf("%d\n",ans+1);
	}
	return 0;
}
