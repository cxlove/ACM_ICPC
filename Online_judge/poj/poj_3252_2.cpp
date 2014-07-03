#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
int c[35][35]={0};
void Init(){
	c[0][0]=1;
	for(int i=1;i<=32;i++){
		c[i][0]=c[i][i]=1;
		for(int j=1;j<i;j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
	}
}
int slove(int n){
	int len=0,bit[50],sum=0;
	int cnt=0;
	while(n){
		bit[++len]=n%2;
		if(bit[len])
			cnt++;
		n/=2;
	}
	for(int i=1;i<len;i++){
		for(int j=i/2;j>=1;j--)
			sum+=c[i-1][j-1];
	}
	int num0=0,num1=1;
	for(int i=len-1;i>=1;i--){
		if(bit[i]){
			num0++;
			for(int j=0;j<=(len/2)-num1;j++)
				sum+=c[len-num0-num1][j];
			num0--;
			num1++;
		}
		else
			num0++;
	}
//	cout<<sum<<endl;
	return sum;
}
int main(){
	int a,b;
	Init();
	while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",slove(b+1)-slove(a));
	return 0;
}