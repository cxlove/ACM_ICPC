#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL Gcd(LL a,LL b){
	return b==0?a:Gcd(b,a%b);
}
LL extend_gcd(LL a,LL b,LL &x,LL &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	LL mod=extend_gcd(b,a%b,x,y);
	LL temp=x;
	x=y;
	y=temp-a/b*y;
	return mod;
}
void slove(LL a,LL b,LL n){
	LL gcd=Gcd(a,b);
	if(n%gcd!=0)
		printf("Impossible\n");
	else{
		LL x,y;
		LL temp=extend_gcd(a,b,x,y);
		x=x*n/gcd;y=y*n/gcd;
		LL t1=b/gcd;
		x=(x%t1+t1)%t1;y=(n-a*x)/b;
		printf("%I64d\n",x);
	}
}
int main(){
	LL x,y,m,n,l;
	while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&l)!=EOF)
		slove(n-m,l,x-y);
	return 0;
}