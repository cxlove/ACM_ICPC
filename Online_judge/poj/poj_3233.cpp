#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct matrix{
	int a[30][30];
};
int n,p;
matrix mult(matrix m1,matrix m2){
	matrix ans;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			ans.a[i][j]=0;
			for(int k=0;k<n;k++)
				ans.a[i][j]=(ans.a[i][j]+m1.a[i][k]*m2.a[k][j])%p;
		}
		return ans;
}
matrix add(matrix m1,matrix m2){
	matrix ans;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			ans.a[i][j]=(m1.a[i][j]+m2.a[i][j])%p;
	return ans;
}
matrix PowMod(matrix m,int k){
	matrix ans;
	memset(ans.a,0,sizeof(ans.a));
	for(int i=0;i<n;i++)
		ans.a[i][i]=1;
	while(k>=1){
		if(k&1)
			ans=mult(ans,m);
		m=mult(m,m);
		k=k>>1;
	}
	return ans;
}
matrix slove(matrix m,int k){
	matrix ans;
	memset(ans.a,0,sizeof(ans.a));
	if(k==0)
		return ans;
	if(k&1)
		ans=PowMod(m,k);
	if(k==1)
		return ans;
	matrix temp=slove(m,k>>1);
	matrix t=PowMod(m,k>>1);
	ans=add(add(ans,temp),mult(temp,t));
	return ans;
}
int main(){
	int k;
	while(scanf("%d%d%d",&n,&k,&p)!=EOF){
		matrix m,ans;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&m.a[i][j]);
				m.a[i][j]%=p;
			}
		}
		ans=slove(m,k);
		for(int i=0;i<n;i++){
			printf("%d",ans.a[i][0]);
			for(int j=1;j<n;j++)
				printf(" %d",ans.a[i][j]);
			printf("\n");
		}
	}
	return 0;
}