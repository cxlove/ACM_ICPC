#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int a[305][305];
int change(char s[10]){
	if(strcmp(s,"MON")==0)
		return 1;
	else if(strcmp(s,"TUE")==0)
		return 2;
	else if(strcmp(s,"WED")==0)
		return 3;
	else if(strcmp(s,"THU")==0)
		return 4;
	else if(strcmp(s,"FRI")==0)
		return 5;
	else if(strcmp(s,"SAT")==0)
		return 6;
	else return 7;
}
void gauss(){
	int i,j;
	int ans[305];
	for(i=0,j=0;i<m&&j<n;j++){
		int k;
		for(k=i;k<m;k++)
			if(a[k][j])
				break;
		if(a[k][j]){
			for(int r=j;r<=n;r++)
				swap(a[k][r],a[i][r]);
			for(int r=0;r<m;r++)
				if(r!=i&&a[r][j]){
					int b1=a[i][j],b2=a[r][j];
					for(int t=0;t<=n;t++)
						a[r][t]=((a[r][t]*b1-a[i][t]*b2)%7+7)%7;
				}
			i++;
		}
	}
	for(int k=i;k<m;k++)
		if(a[k][n]){
			printf("Inconsistent data.\n");
			return;
		}
	if(i<n){
		printf("Multiple solutions.\n");
		return ;
	}
	/*for(int i=0;i<m;i++){
		for(int j=0;j<=n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}*/
	for(i=n-1;i>=0;i--){
		int temp=a[i][n];
		for(j=i+1;j<n;j++)
			temp=((temp-a[i][j]*ans[j])%7+7)%7;
		while(temp%a[i][i]!=0)temp += 7;
		ans[i]=(temp/a[i][i])%7;
	}
	for(i=0;i<n;i++)
		if(ans[i]<3)
			ans[i]+=7;
	for(i=0;i<n-1;i++)
		printf("%d ",ans[i]);
	printf("%d\n",ans[n-1]);
}
int main(){
	char str1[10],str2[10];
	while(scanf("%d%d",&n,&m)!=EOF&&n+m){
		memset(a,0,sizeof(a));
		for(int i=0;i<m;i++){
			int k;
			scanf("%d%s%s",&k,str1,str2);
			a[i][n]=(change(str2)-change(str1)+1+7)%7;
			while(k--){
				int num;
				scanf("%d",&num);
				a[i][num-1]++;
			}
			for(int j=0;j<n;j++)
				a[i][j]%=7;
		}
		/*for(int i=0;i<m;i++){
			for(int j=0;j<=n;j++)
				printf("%d ",a[i][j]);
			printf("\n");
		}*/
		gauss();
	}
	return 0;
}