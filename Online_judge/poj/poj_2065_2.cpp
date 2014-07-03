/*
ID:cxlove
PROB:poj 2065
DATA:2012.3.31
HINT:高斯消元
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int p,n,a[100][100];
char str[100];
void debug(){
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
void gauss(){
	int ans[100];
	int i,j;
	for(i=0,j=0;i<n&&j<n;j++){
		int k=i;
		for(;k<n;k++)
			if(a[k][j])
				break;
		if(a[k][j]){
			for(int r=0;r<=n;r++)
				swap(a[i][r],a[k][r]);
			for(int k=0;k<n;k++){
				if(k!=i&&a[k][j]){
					int b1=a[k][j],b2=a[i][j];
					for(int r=0;r<=n;r++)
						a[k][r]=((a[k][r]*b2-a[i][r]*b1)%p+p)%p;
				}
			}
		    i++;
		}
	}
//	debug();
	for(int i=n-1;i>=0;i--){
		int temp=a[i][n];
		for(int j=i+1;j<n;j++)
			temp=((temp-a[i][j]*ans[j])%p+p)%p;
		while(temp%a[i][i]!=0) temp+=p;
		ans[i]=(temp/a[i][i])%p;
	}
	for(int i=0;i<n-1;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n-1]);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&p,str);
		n=strlen(str);
		for(int i=0;i<n;i++){
			if(str[i]=='*')
				a[i][n]=0;
			else
				a[i][n]=str[i]-'a'+1;
			a[i][0]=1;
			for(int j=1;j<n;j++)
				a[i][j]=(a[i][j-1]*(i+1))%p;
		}
	//	debug();
		gauss();

	}
}
