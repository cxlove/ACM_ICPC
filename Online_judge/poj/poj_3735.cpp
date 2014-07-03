#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
struct matrix{
	LL a[105][105];
};
int n; 
matrix Mult(matrix m1,matrix m2){
	matrix ans;
	memset(ans.a,0,sizeof(ans.a));
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			if(m1.a[i][j])
				for(int k=0;k<=n;k++)
					ans.a[i][k]+=m1.a[i][j]*m2.a[j][k];
    return ans;
}
matrix Pow(matrix m,int k){
	matrix ans;
	memset(ans.a,0,sizeof(ans.a));
	for(int i=0;i<=n;i++)
		ans.a[i][i]=1;
	while(k){
		if(k&1)
			ans=Mult(ans,m);
		m=Mult(m,m);
		k>>=1;
	}
	return ans;
}
int main(){
	int k,q,t1,t2,i;
	char str[10];
	while(scanf("%d%d%d",&n,&k,&q)!=EOF&&n+k+q){
		matrix m;
		memset(m.a,0,sizeof(m.a));
		for(i=0;i<=n;i++)
			m.a[i][i]=1;
		while(q--){
			scanf("%s",str);
			if(str[0]=='g'){
				scanf("%d",&t1);
				m.a[n][t1-1]++;
			}
			else if(str[0]=='e'){
				scanf("%d",&t1);
				for(int i=0;i<=n;i++)
					m.a[i][t1-1]=0;
			}
			else{
				scanf("%d%d",&t1,&t2);
				for(int i=0;i<=n;i++)
					swap(m.a[i][t1-1],m.a[i][t2-1]);
			}
		}
		m=Pow(m,k);
		for(i=0;i<n-1;i++)
			printf("%I64d ",m.a[n][i]);
		printf("%I64d\n",m.a[n][n-1]);
	}
	return 0;
}

