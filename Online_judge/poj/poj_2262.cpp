#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
bool flag[1000005]={0};
void prime(){
	for(int i=2;i<=1000;i++){
		if(flag[i]) continue;
		for(int j=2;j*i<=1000*1000;j++)
			flag[i*j]=true;
	}
}
int main(){
	prime();
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		if(n&1){
			printf("Goldbach's conjecture is wrong.\n");
			continue;
		}
		for(int i=3;i<=n/2;i++)
			if(flag[i]==false&&flag[n-i]==false){
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
	}
	return 0;
}