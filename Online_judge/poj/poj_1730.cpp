#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
int flag[1000005]={0},cnt=0;
int prime[1000005];
void Prime(){
	for(int i=2;i<=1000000;i++){
		if(flag[i]) continue;
		prime[cnt++]=i;
		for(int j=2;j*i<=1000000;j++)
			flag[i*j]=1;
	}
}
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	LL n;
	Prime();
	while(scanf("%I64d",&n)!=EOF&&n){
		bool mark=false;
		int ans=1;
		LL t=n;
		if(n<0) n=-n;
		for(int i=0;i<cnt&&prime[i]*prime[i]<=n;i++){
			if(n%prime[i]==0){
				int t=0;
				while(n%prime[i]==0){
					t++;
					n/=prime[i];
				}
				if(!mark){
					mark=true;
					ans=t;
				}
				else
					ans=gcd(ans,t);
			}
		}
		if(n>1)
			ans=1;
		if(t<0){
			while(!(ans&1))
				ans>>=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}