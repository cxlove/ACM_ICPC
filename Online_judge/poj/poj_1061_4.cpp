#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
LL extend_gcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;y=0;return a;
	}
	LL gcd=extend_gcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
	return gcd;
}
int main(){
	LL x,y,m,n,l;
	while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l)!=EOF){
		LL A=m-n,B=-l,N=y-x,X,Y;
		LL gcd=extend_gcd(A,B,X,Y);
		if(N%gcd!=0)
			printf("Impossible\n");
		else{
			X=X*N/gcd;
			LL t=B/gcd;
			X=(X%t+t)%t;
			printf("%I64d\n",X);
		}
	}
	return 0;
}