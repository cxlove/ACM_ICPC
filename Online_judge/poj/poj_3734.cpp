#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define LL  long long
#define MOD 10007
#define eps 1e-6
#define N 100010
#define zero(a)  fabs(a)<eps
using namespace std;
int PowMod(int a,LL b){
	int ret=1;
	while(b){
		if(b&1)
			ret=(ret*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ret;
}
int main(){
	int t;
	LL n;
	scanf("%d",&t);
	while(t--){
		scanf("%I64d",&n);
		printf("%d\n",(PowMod(4,n-1)+PowMod(2,n-1))%MOD);
	}
	return 0;
}
