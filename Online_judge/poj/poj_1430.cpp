#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
LL find(int n){
	LL ret=0;
	while(n){
		n/=2;
		ret+=n;
	}
	return ret;
}
int main(){
	int t;
	int m,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		n=n-m;
		m=(m-1)/2;
		if(find(n+m)==find(m)+find(n))
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}