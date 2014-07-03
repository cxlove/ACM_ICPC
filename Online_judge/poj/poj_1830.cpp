/*
ID:cxlove
PROB:poj 1830 开关问题
DATA:2012.3.30
HINT:高斯消元
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int s[35],e[35],a[35][35],n;
int gauss(){
	int i,j;
	for(i=1,j=1;i<=n&&j<=n;j++){
		int k=i;
		for(;k<=n;k++)
			if(a[k][j])
				break;
		if(a[k][j]){
			for(int r=1;r<=n+1;r++)
				swap(a[i][r],a[k][r]);
			for(int r=1;r<=n;r++)
				if(r!=i&&a[r][j])
					for(k=1;k<=n+1;k++)
						a[r][k]^=a[i][k];
			i++;
		}
	}
	for(j=i;j<=n;j++)
		if(a[j][n+1])
			return -1;
	return 1<<(n-i+1);
}
int main(){
	int t,i,j;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(j=1;j<=n;j++){
			scanf("%d",&e[j]);
			if(s[j]!=e[j])
				a[j][n+1]=1;
			a[j][j]=1;
		}			
		while(scanf("%d%d",&i,&j)&&i+j)
			a[j][i]=1;
		int ans=gauss();
		if(ans==-1)
			printf("Oh,it's impossible~!!\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}