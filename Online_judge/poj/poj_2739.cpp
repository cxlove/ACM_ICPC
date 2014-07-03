#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
using namespace std;
int a[100],b[100];
int prime[10000],count=0,cnt;
bool flag[10005]={0};
void Prime(){
	for(int i=2;i<=100;i++){
		if(flag[i]) continue;
		for(int j=2;j*i<=10000;j++)
			flag[i*j]=true;
	}
	for(int i=2;i<=10000;i++)
		if(!flag[i])
			prime[count++]=i;
}
int main(){
	int n;
	Prime();
	while(scanf("%d",&n)!=EOF&&n){
		int ans=0;
		for(int i=0;i<count;i++){
			int sum=0;
			if(prime[i]>n)
				break;
			for(int j=i;j<count;j++){
				sum+=prime[j];
				if(sum==n) {ans++;break;}
				if(sum>n) break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
