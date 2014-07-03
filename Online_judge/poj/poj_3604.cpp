#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 100005
#define inf  1<<30
#define MOD 9973
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
bool flag[10005];
int prime[10005],cnt=0;
int fac[1005],tot;
void Prime(){
	for(int i=2;i<=3000;i++){
		if(flag[i])
			continue;
		prime[cnt++]=i;
		for(int j=2;j*i<=3000;j++)
			flag[i*j]=true;
	}
}
LL slove(int k){
	int a=k,b=k+1;
	if(!(a&1))
		a/=2;
	else
		b/=2;
	return (LL)a*a*b*b;
}
int main(){
	int t,n;
	Prime();
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		tot=0;
		for(int i=0;i<cnt&&prime[i]<=n;i++)
			if(n%prime[i]==0){
				fac[tot]=0;
				while(n%prime[i]==0){
					fac[tot]++;
					n/=prime[i];
				}
				tot++;
			}
		if(n>1)
			fac[tot++]=1;
		LL ans=1;
		for(int i=0;i<tot;i++)
			ans*=slove(fac[i]+1);
		printf("%lld\n",ans);
	}
	return 0;
}
