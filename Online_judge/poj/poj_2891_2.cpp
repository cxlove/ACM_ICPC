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
	int t;
	
	LL a1,a2,r1,r2;
	while(scanf("%d",&t)!=EOF){
		scanf("%lld%lld",&a1,&r1);
		t--;bool flag=false;
		while(t--){
			scanf("%lld%lld",&a2,&r2);
			if(flag)
				continue;
			LL x,y;
			LL p=extend_gcd(a1,a2,x,y);
			if((r2-r1)%p!=0){
				flag=true;
				continue;
			}
			x=x*(r2-r1)/p;
			LL t=a2/p;
			x=(x%t+t)%t;
			r1=a1*x+r1;
			a1=(a1*a2)/p;
		}
		if(flag)
			printf("-1\n");
		else
			printf("%I64d\n",r1);
	}
	return 0;
}