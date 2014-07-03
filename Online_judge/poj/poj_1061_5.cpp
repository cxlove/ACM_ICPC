#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL extend_gcd(LL a,LL b, LL &x,LL &y){
	if(b==0){x=1;y=0;return a;}
	LL gcd=extend_gcd(b,a%b,x,y);
	LL t=x;
	x=y;
	y=t-a/b*y;
	return gcd;
}
int main(){
	LL x,y,m,n,l,t,X,Y;
	while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l)!=EOF){
		LL a=m-n,b=-l,c=y-x;
		LL gcd=extend_gcd(a,b,X,Y);
		if(c%gcd!=0)
			printf("Impossible\n");
		else{
			X=(X*c)/gcd;
			t=b/gcd;
			X=(X%t+t)%t;
			printf("%I64d\n",X);
		}
	}
	return 0;
}