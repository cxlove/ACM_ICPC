#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
int n,a[200005],b[200005],c[200005],x,y,z;
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&x,&y,&z);
			a[i]=x-y;
			b[i]=y-z;
			c[i]=z-x;
		}
		sort(a,a+n);
		sort(b,b+n);
		sort(c,c+n);
		LL ans=0;
		for(int i=0;i<n;i++){
			ans+=(LL)(2*i-n)*a[i];
			ans+=(LL)(2*i-n)*b[i];
			ans+=(LL)(2*i-n)*c[i];
		}
		printf("%I64d\n",ans/2);
	}
	return 0;
}