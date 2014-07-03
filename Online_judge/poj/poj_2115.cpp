#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL extend_gcd(LL a,LL b,LL &x,LL &y){
	if(b==0) {x=1;y=0;return a;}
	LL gcd=extend_gcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
	return gcd;
}
int main(){
	LL a,b,c,k;
	while(scanf("%lld%lld%lld%lld",&a,&b,&c,&k)!=EOF&&(a+b+c+k)){
		LL A=c,B=((LL)1<<k),N=b-a,x,y;
		LL gcd=extend_gcd(A,B,x,y);
		if(N%gcd!=0)
			printf("FOREVER\n");
		else{
			LL t=B/gcd;
			x=x*N/gcd;
			x=(x%t+t)%t;
			printf("%I64d\n",x);
		}
	}
	return 0;
}