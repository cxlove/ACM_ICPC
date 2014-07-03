#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,d;
int a[105][105],cnt;
void debug(){
	for(int i=0;i<n;i++){
		for(int j=0;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}
int ta[105][105],x[105],ans[105],var,var0;  
void dfs(int v){  
	if(v==n){  
		int temp=0;  
		for(int i=0;i<n;i++)  
			x[i]=ans[i];  
		for(int i=0;i<n;i++)  
			for(int j=0;j<=n;j++)  
				ta[i][j]=a[i][j];  
		for(int i=var0-1;i>=0;i--){  
			for(int j=i+1;j<n;j++)  
				ta[i][n]^=(x[j]&&ta[i][j]);  
			x[i]=ta[i][n];  
		}  
		for(int i=0;i<n;i++)  
			if(x[i])  
				temp++;  
		cnt=min(cnt,temp);  
		return ;  
	}  
	ans[v]=0;  
	dfs(v+1);  
	ans[v]=1;  
	dfs(v+1);  
}  
void gauss(){  
	int i,j;  
	for(i=0,j=0;i<n&&j<n;j++){  
		int k=i;  
		for(;k<n;k++)  
			if(a[k][j])  
				break;  
		if(a[k][j]){  
			for(int r=0;r<=n;r++)  
				swap(a[i][r],a[k][r]);  
			for(int k=0;k<n;k++)  
				if(k!=i&&a[k][j]){  
					for(int r=0;r<=n;r++)  
						a[k][r]^=a[i][r];  
				}  
				i++;  
		}  
	}  
	if(i==n){  
		cnt=0;  
		for(int r=0;r<n;r++)  
			if(a[r][n])  
				cnt++;  
		printf("%d\n",cnt);  
		return ;  
	} 
	if(i<n){
		for(int r=i;r<n;r++)
			if(a[r][n]){
				printf("impossible\n");
				return ;
			}
	}
	var0=i;  
	cnt=100;  
	dfs(var0);  
	printf("%d\n",cnt);  
}  
int main(){
	int t;
//	scanf("%d",&t);
//	while(t--){
	//	scanf("%d%d",&n,&d);
	n=20;d=1;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
			scanf("%d",&a[i][n]);
		for(int i=0;i<n;i++)
			for(int j=max(0,i-d);j<=min(n-1,i+d);j++)
				a[j][i]=1;
		gauss();
//	}
	return 0;
}
