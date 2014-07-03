#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define LL long long
#define N 1000000000
#define MOD 9973
using namespace std;
int n,m,p,k;
bool flag[40000]={0};
int prime[40000],cnt=0;
struct matrix{
	int m[15][15];
}mat;
matrix operator*(matrix m1,matrix m2){
	matrix ans;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++){
			ans.m[i][j]=0;
			for(int k=1;k<=m;k++)
				ans.m[i][j]=(ans.m[i][j]+m1.m[i][k]*m2.m[k][j])%MOD;
		}
	return ans;
}
matrix operator^(matrix m1,int num){
	matrix ans;
	memset(ans.m,0,sizeof(ans.m));
	for(int i=1;i<=m;i++) ans.m[i][i]=1;
	while(num){
		if(num&1) ans=ans*m1;
		m1=m1*m1;
		num>>=1;
	}
	return ans;
}
void Prime(){
	for(int i=2;i<=sqrt(N+1.0);i++){
		if(flag[i]) continue;
		prime[cnt++]=i;
		for(int j=2;j*i<=sqrt(N+1.0);j++)
			flag[i*j]=true;
	}
}
int eular(int m){
	int sum=1;
	for(int i=0;i<cnt&&prime[i]<=m;i++)
		if(m%prime[i]==0){
			sum*=(prime[i]-1);
			m/=prime[i];
			while(m%prime[i]==0){
				sum*=prime[i];
				m/=prime[i];
			}
		}
		if(m>1)
			sum*=(m-1);
		return sum%MOD;
}
int Pow(int a,int b){
	int ret=1;
	a=a%MOD;
	while(b){
		if(b&1)
			ret=(ret*a)%MOD;
		a=(a*a)%MOD;
		b>>=1;
	}
	return ret;
}
void debug(matrix t){
	for(int i=1;i<=m;i++){
		for(int j=1;j<m;j++)
			printf("%d ",t.m[i][j]);
		printf("%d\n",t.m[i][m]);
	}
}
int slove(int num){
	matrix temp=mat^num;
	int ret=0;
	for(int i=1;i<=m;i++)
		ret=(ret+temp.m[i][i])%MOD;
	return ret;
}
int polya(){
	int sum=0;
	int i=1;
	for(;i*i<n;i++)
		if(n%i==0)
			sum=(sum+eular(i)*slove(n/i)+eular(n/i)*slove(i))%MOD;
	if(i*i==n)
		sum=(sum+eular(i)*slove(i))%MOD;
	return (sum*Pow(n%MOD,MOD-2))%MOD;
}
int main(){	
	int t;
	Prime();
	scanf("%d",&t);
	while(t--){	
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				mat.m[i][j]=1;
		while(k--){
			int a,b;
			scanf("%d%d",&a,&b);
			mat.m[a][b]=mat.m[b][a]=0;
		}
		printf("%d\n",polya());
	}
	return 0;
}