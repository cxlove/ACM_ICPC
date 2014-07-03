#include<iostream>
#include<cstdio>
#include<cstring>
#define MOD 10000
using namespace std;
int c[2][2];
void MultMatrix(int a[2][2],int b[2][2]){
	memset(c,0,sizeof(c));
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				c[i][j]=(c[i][j]+a[i][k]*b[k][j])%MOD;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			a[i][j]=c[i][j];
}
void PowMod(int a[2][2],int ans[2][2],int n){
	while(n>=1){
		if(n&1)
			MultMatrix(ans,a);
		MultMatrix(a,a);
		n=n>>1;
	}
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n!=-1){
		int a[2][2]={1,1,1,0},ans[2][2]={1,0,0,1};
		PowMod(a,ans,n);
		printf("%d\n",ans[0][1]);
	}
	return 0;
}