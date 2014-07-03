#include <iostream>
#include <cstdio>
#include <cstring>
#define LL long long
using namespace std;
const int MOD = 9901;
const int N = 50005;
LL a,b;
int flag[N]={0},cnt=0,prime[N];
void Init(){
	for(int i=2;i<N;i++){
		if(flag[i]) continue;
		prime[cnt++]=i;
		for(int j=2;j*i<N;j++)
			flag[i*j]=1;
	}
}
LL PowMod(LL a,LL b){
	LL ret=1;
	a%=MOD;
	while(b){
		if(b&1) ret=(ret*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ret;
}
LL solve(LL a,LL b){
	if(b==1) return a;
	LL temp=solve(a,b/2);
	temp=temp*(1+PowMod(a,b/2))%MOD;
	if(b&1) temp=(temp+PowMod(a,b))%MOD;
	return temp;
}
int main(){
	Init();
	//cout<<solve(2,4)<<endl;
	while(scanf("%lld%lld",&a,&b)!=EOF){
		if(a==0){printf("0\n");continue;}
		if(a==1||b==0){printf("1\n");continue;}
		LL ans=1;
		for(int i=0;i<cnt&&prime[i]*prime[i]<a;i++){
			if(a%prime[i]==0){
				int tot=0;
				while(a%prime[i]==0) a/=prime[i],tot++;
				ans=(ans*(solve(prime[i],(LL)b*tot)+1))%MOD;
				//ans=(ans*(PowMod(prime[i],(long long)tot*b+1)+MOD-1))%MOD*PowMod(prime[i]-1+MOD,MOD-2)%MOD;
			}
		}
		if(a>1){
			ans=(ans*(solve(a,b)+1))%MOD;
			//ans=(ans*(PowMod(a,b+1)+MOD-1))%MOD*PowMod(a-1+MOD,MOD-2)%MOD;
		}
		printf("%lld\n",ans);
	}
	return 0;
}