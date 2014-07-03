#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[25][25],ans[25],var,var0,cnt;
int x[25];
void debug(){
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++)
			printf("%d ",a[i][j]);
		printf("%d\n",a[i][20]);
	}
}
int ta[25][25];
void dfs(int v){
	if(v==20){
		int temp=0;
		for(int i=0;i<20;i++)
			x[i]=ans[i];
		for(int i=0;i<20;i++)
			for(int j=0;j<=20;j++)
				ta[i][j]=a[i][j];
		for(int i=var0-1;i>=0;i--){
			for(int j=i+1;j<20;j++)
				ta[i][20]^=(x[j]&&ta[i][j]);
			x[i]=ta[i][20];
		}
		for(int i=0;i<20;i++)
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
	for(i=0,j=0;i<20&&j<20;j++){
		int k=i;
		for(;k<20;k++)
			if(a[k][j])
				break;
		if(a[k][j]){
			for(int r=0;r<=20;r++)
				swap(a[i][r],a[k][r]);
			for(int k=0;k<20;k++)
				if(k!=i&&a[k][j]){
					for(int r=0;r<=20;r++)
						a[k][r]^=a[i][r];
				}
			i++;
		}
	}
	if(i==20){
		cnt=0;
		for(int r=0;r<20;r++)
			if(a[r][20])
				cnt++;
		printf("%d\n",cnt);
		return ;
	}
	var0=i;
	cnt=100;
	dfs(var0);
	printf("%d\n",cnt);
}
int main(){
	memset(a,0,sizeof(a));
	for(int i=0;i<20;i++)
		scanf("%d",&a[i][20]);
	for(int i=0;i<20;i++){
		a[i][i]=1;
		a[max(0,i-1)][i]=1;
		a[min(19,i+1)][i]=1;
	}
	gauss();
	return 0;
}
