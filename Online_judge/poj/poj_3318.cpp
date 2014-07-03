#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <algorithm>
using namespace std;
const int N = 505;
typedef long long LL;
int n;
LL a[N][N],b[N][N],c[N][N];
LL ans[N],d[N];
bool check(){
	int t[N];
	memset(t,0,sizeof(t));
	memset(ans,0,sizeof(ans));
	for(int i=0;i<n;i++)
		d[i]=rand()%101;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			t[i]+=d[j]*a[j][i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			ans[i]+=t[j]*b[j][i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			ans[i]-=d[j]*c[j][i];
	}
	for(int i=0;i<n;i++){
		if(ans[i])
			return false;
	}
	return true;
}
int main(){
	srand(time(0));
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%lld",&a[i][j]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%lld",&b[i][j]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%lld",&c[i][j]);
		puts(check()?"YES":"NO");
	}
	return 0;
}