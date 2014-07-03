#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,a[230][230];
char str[20][20];
int gauss(){
	int i,j;
	for(i=0,j=0;j<n*n&&i<n*n;j++){
		int k=i;
		for(;k<n*n;k++)
			if(a[k][j])
				break;
		if(a[k][j]){
			for(int r=0;r<=n*n;r++)
				swap(a[i][r],a[k][r]);
			for(int k=0;k<n*n;k++)
				if(k!=i&&a[k][j])
					for(int r=0;r<=n*n;r++)
						a[k][r]=a[k][r]^a[i][r];
			i++;
		}
	}
	for(int k=i;k<n*n;k++)
		if(a[k][n*n])  return -1;
	int cnt=0;
	for(i=0;i<n*n;i++)
		cnt+=a[i][n*n];
	return cnt;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			scanf("%s",str[i]);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				if(str[i][j]=='y')
					a[i*n+j][n*n]=0;
				else
					a[i*n+j][n*n]=1;
		}
		for(int i=0;i<n*n;i++){
			a[i][i]=1;
			if(i%n!=0)
				a[i-1][i]=1;
			if(i%n!=(n-1))
				a[i+1][i]=1;
			if(i>=n)
				a[i-n][i]=1;
			if(i<n*(n-1))
				a[i+n][i]=1;
		}
		int ans=gauss();
		if(ans==-1)
			printf("inf\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
