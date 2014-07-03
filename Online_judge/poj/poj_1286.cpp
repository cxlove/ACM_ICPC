#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define LL long long
using namespace std;
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
int c,s;
LL eular(int n){
	LL sum=1;
	for(int i=2;i<=sqrt(1.0+n);i++)
		if(n%i==0){
			sum*=(i-1);
			n/=i;
			while(n%i==0){
				sum*=i;
				n/=i;
			}
		}
	if(n>1)
		sum*=(n-1);
	return sum;
}
LL Pow(int a,int b){
	LL ret=1;
	while(b){
		if(b&1)
			ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}
LL polya(){
	LL sum=0;
	for(int i=1;i<=s;i++)
		if(s%i==0)
     		sum+=Pow(c,i)*eular(s/i);
	if(s&1)
		sum+=s*Pow(c,(s>>1)+1);
	else
		sum+=s/2*(Pow(c,(s>>1)+1)+Pow(c,s>>1));
	return sum/2/s;
}
int main(){	
	c=3;
	while(scanf("%d",&s)!=EOF&&s!=-1){
		if(s==0) printf("0\n");
		else
			printf("%I64d\n",polya());
	}
	return 0;
}