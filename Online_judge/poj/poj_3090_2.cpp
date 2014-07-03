#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int f[1001][1001]={0};
int gcd(int a,int b){
	if(f[a][b]||f[b][a]!=0)
		return f[a][b];
	if(b==0)
		return f[a][b]=f[b][a]=a;
	else
		return f[a][b]=f[b][a]=gcd(b,a%b);
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<=1000;i++)
		for(int j=i;j<=1000;j++)
			gcd(i,j);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		int ans=1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(f[i][j]==1)
					ans++;
		printf("%d %d %d\n",tt,n,2*ans+1);
	}
	return 0;
}