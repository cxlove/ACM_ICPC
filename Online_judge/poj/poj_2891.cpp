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
	int t;
	LL a1,r1,a2,r2;
	while(scanf("%d",&t)!=EOF){
		t--;
		scanf("%lld%lld",&a1,&r1);
		bool flag=false;
		while(t--){
			scanf("%lld%lld",&a2,&r2);
			LL x,y,t;
			LL gcd=extend_gcd(a1,a2,x,y);
			if((r2-r1)%gcd!=0)
				flag=true;
			if(flag)
				continue;
			t=(a2)/gcd;
			x=(x*(r2-r1))/gcd;
			x=(x%t+t)%t;
			r1=a1*x+r1;
			a1=(a1*a2)/gcd;
		}
		if(flag)
			printf("-1\n");
		else
	    	printf("%I64d\n",r1);
	}
	return 0;
}