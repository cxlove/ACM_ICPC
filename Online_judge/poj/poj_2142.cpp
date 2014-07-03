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
LL Abs(LL a){
	return a<0?-a:a;
}
int main(){
	LL a,b,n;
	while(scanf("%lld%lld%lld",&a,&b,&n)!=EOF){
		if(a==0&&b==0&&n==0)break;
		LL x1,y1,x,y,gcd=extend_gcd(a,b,x,y),mmax;
		LL t=b/gcd;
		LL tx=x*n/gcd;
		tx=(tx%t+t)%t;
		LL ty=Abs((a*tx-n)/b);
		x1=tx;y1=ty;
		mmax=tx+ty;
		t=a/gcd;
		ty=y*n/gcd;
		ty=(ty%t+t)%t;
		tx=Abs((b*ty-n)/a);
		if(tx+ty<mmax){
			x1=tx;y1=ty;
			mmax=tx+ty;
		}
		printf("%I64d %I64d\n",x1,y1);
	}
	return 0;
}
