#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<cmath>
#define TIME 10
#define LL long long
#define C 240
using namespace std;
LL fact[100000],cnt,fac[100000],temp,ans;
LL GCD(LL a,LL b){
	return b==0?a:GCD(b,a%b);
}
LL MultMod(LL a,LL b,LL n){
	a%=n;
	b%=n;
	LL ret=0;
	while(b){
		if(b&1){
			ret+=a;
			if(ret>=n) ret-=n;
		}
		a=a<<1;
		if(a>=n) a-=n;
		b=b>>1;
	}
	return ret;
}
LL PowMod(LL a,LL b,LL n){
	LL ret=1;
	a=a%n;
	while(b>=1){
		if(b&1)
			ret=MultMod(ret,a,n);
		a=MultMod(a,a,n);
		b=b>>1;
	}
	return ret;
}
bool Witless(LL a,LL n){
	LL u=n-1,t=0,x1,x2;
	while((u&1)==0){
		t++;
		u/=2;
	}
	x1=PowMod(a,u,n);
	for(int i=1;i<=t;i++){
		x2=MultMod(x1,x1,n);
		if(x2==1&&x1!=1&&x1!=n-1)
			return true;
		x1=x2;
	}
	if(x1!=1)
		return true;
	return false;
}
bool Miller_Rabin(LL n,LL t){
	if(n==2) return true;
	if(n==1||!(n&1)) return false;
	srand(time(NULL));
	for(int i=1;i<=t;i++){
		LL a=rand()%(n-1)+1;
		if(Witless(a,n))
			return false;
	}
	return true;
}
LL Pollar_rho(LL n,LL c){
	srand(time(NULL));
	LL i=1,k=2,x=rand()%n,y=x,d;
	while(1){
		i++;
		x=(MultMod(x,x,n)+c)%n;
		d=GCD(y-x,n);
		if(d>1&&d<n)
			return d;
		if(x==y)
			return n;
		if(i==k){
			y=x;
			k+=k;
		}
	}
}
void Find(LL n,LL c){
	if(n==1) return ;
	if(Miller_Rabin(n,TIME)){
		fact[cnt++]=n;
		return;
	}
	LL p=n;
	while(p>=n) p=Pollar_rho(p,c--);
	Find(p,c);
	Find(n/p,c);
}
void dfs(int idx,LL t){
	if(idx>=cnt){
		if(t<=sqrt(temp*1.0)&&t>ans)
			ans=t;
		return;
	}
	dfs(idx+1,t);
	dfs(idx+1,t*fac[idx]);
}
int main(){
	LL gcd,lcm;
	while(scanf("%I64d%I64d",&gcd,&lcm)!=EOF){
		if(gcd==lcm){
			printf("%I64d %I64d\n",gcd,lcm);
			continue;
		}
		temp=lcm/gcd;
		cnt=0;
		Find(temp,C);
		sort(fact,fact+cnt);
		/*for(int i=0;i<cnt;i++)
			printf("%I64d\n",fact[i]);*/
		int j=0;
		fac[0]=1;
		for(int i=0;i<cnt;i++)
			if(i==0||fact[i]==fact[i-1])
				fac[j]=fac[j]*fact[i];
			else 
				fac[++j]=fact[i];	
		cnt=j+1;
		ans=1;
	/*	for(int j=0;j<cnt;j++)
			printf("%d\n",fac[j]);*/
		dfs(0,1);
		printf("%I64d %I64d\n",ans*gcd,temp/ans*gcd);
	}
	return 0;
}