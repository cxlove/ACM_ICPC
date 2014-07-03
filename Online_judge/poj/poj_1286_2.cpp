#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
LL gcd(LL a,LL b){
	return b==0?a:gcd(b,a%b);
}
int c,s;
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
		sum+=Pow(c,gcd(s,i));
	if(s&1)
		sum+=s*Pow(c,(s>>1)+1);
	else{
		for(int i=1;i<=s;i++)
			if(i&1)
				sum+=Pow(c,(s>>1)+1);
			else
				sum+=Pow(c,s>>1);
	}
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