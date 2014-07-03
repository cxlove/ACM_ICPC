#include <iostream>
#include <cstdio>
using namespace std;
const int N = 505;
typedef long long LL;
int n,m,d,k;
void mut(LL a[],LL b[]){
	LL c[N];
	for(int i=0;i<n;i++){
		c[i]=0;
		for(int j=0;j<n;j++){
			c[i]+=a[j]*b[(j-i+n)%n];
		}
		c[i]%=m;
	}
	for(int i=0;i<n;i++){
		b[i]=c[i];
	}
}
LL a[N],b[N],c[N],ans[N];
int main(){
	while(scanf("%d%d%d%d",&n,&m,&d,&k)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		for(int i=0;i<n;i++)
			c[i]=b[i]=min(i,n-i)<=d;
		k--;
		while(k){
			if(k&1) mut(b,c);
			mut(b,b);
			k>>=1;
		}
		for(int i=0;i<n;i++){
			ans[i]=0;
			for(int j=0;j<n;j++){
				ans[i]=(ans[i]+a[j]*c[(j-i+n)%n])%m;
			}
		}
		for(int i=0;i<n;i++)
			printf("%lld%c",ans[i],(i==n-1)?'\n':' ');
	}
	return 0;
}