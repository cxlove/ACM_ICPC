#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
int k;
int slove(int n){
	if(n==1) return 0;
	return (slove(n-1)+k)%n;
}
int main(){
	int n,m;
	while(scanf("%d%d%d",&n,&k,&m)!=EOF&&n+m+k){
		printf("%d\n",(slove(n-1)+m)%n+1);
	}
	return 0;
}