#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
#define N 1000000
using namespace std;
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
LL get_eular(LL n){
	LL ret=1;
	for(LL i=2;i*i<=n;i++)
		if(n%i==0){
			ret*=i-1;
			n/=i;
			while(n%i==0){
				n/=i;
				ret*=i;
			}
		}
	if(n>1)
		ret*=n-1;
	return ret;
}
LL PowMod(LL a,LL b,LL MOD){
	LL ret=1;
	while(b){
		if(b&1)
			ret=(ret*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ret;
}
LL fact[100000],cnt;
void get_fact(LL n){
	cnt=0;
	for(LL i=2;i*i<=n;i++)
		if(n%i==0){
			fact[cnt++]=i;
			fact[cnt++]=n/i;
		}
}
int main(){
	LL p,q;
	int cas=0;
	while(scanf("%lld/%lld",&p,&q)!=EOF){
		LL t=gcd(p,q);
		p/=t;
		q/=t;
		int c=1;
		while(!(q&1)){
			q/=2;
			c++;
		}
		LL phi=get_eular(q),ans;
		get_fact(phi);
		fact[cnt++]=phi;
		sort(fact,fact+cnt);
		for(int i=0;i<cnt;i++)
			if(PowMod(2,fact[i],q)==1){
				ans=fact[i];
				break;
			}
			printf("Case #%d: %d,%lld\n",++cas,c,ans);
	}
	return 0;
}
			