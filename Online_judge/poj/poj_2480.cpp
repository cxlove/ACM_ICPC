#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define LL long long
#define MOD 1000000007
using namespace std;
int main(){
	LL n;
	while(scanf("%lld",&n)!=EOF){
		LL ans=1;
		for(LL i=2;i*i<=n;i++)
			if(n%i==0){
				LL k=0,p=1;
				while(n%i==0){
					k++;
					p*=i;
					n/=i;
				}
				ans*=k*(p-p/i)+p;
			}
		if(n>1)
			ans*=2*n-1;
		printf("%lld\n",ans);
	}
	return 0;
}
