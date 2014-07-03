#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#define LL long long
using namespace std;
LL p,q,p1,q1;
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
LL eular(LL num){
	LL sum=1;
	for(int i=2;i*i<=num;i++)
		if(num%i==0){
			sum=sum*(i-1);
			num/=i;
			while(num%i==0){
				sum*=i;
				num/=i;
			}
		}
	if(num>1) sum*=(num-1);
	return sum;
}
LL PowMod(int a,int n,int m){
	if(n==0)  return 1;
	if(n==1) return a%m;
	LL ans=PowMod(a,n>>1,m);
	ans=(ans*ans)%m;
	if(n&1)
		ans=(ans*a)%m;
	return ans;
}
int main(){
	int tt=0;
	while(scanf("%I64d/%I64d",&p,&q)!=EOF){
		printf("Case #%d: ",++tt);
		LL temp=gcd(p,q);
		p=p/temp;
		q=q/temp;
		int qd=1,zd=1<<30;
		while(q%2==0){
			qd++;
			q/=2;
		}
		LL phi=eular(q);
		for(int x=2;x*x<=phi;x++)
			if(phi%x==0){
				if(PowMod(2,x,q)==1){
					zd=min(zd,x);
					break;
				}
				else if(PowMod(2,phi/x,q)==1)
					zd=min(zd,(int)phi/x);
			}
		if(zd==1<<30)
			zd=phi;
		printf("%d,%d\n",qd,zd);
	}
	return 0;
}