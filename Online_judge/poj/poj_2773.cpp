#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int cnt,a[1000000];
int main(){
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF){
		cnt=0;
		for(int i=1;i<=n;i++)
			if(gcd(n,i)==1)
				a[cnt++]=i;
		if(k%cnt==0)
			printf("%d\n",n*(k/cnt-1)+a[cnt-1]);
		else
			printf("%d\n",n*(k/cnt)+a[k%cnt-1]);
	}
	return 0;
}