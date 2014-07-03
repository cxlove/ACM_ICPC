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
	return b==0?1:Pow(a,b-1)*a;
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
	while(scanf("%d%d",&c,&s)!=EOF&&c+s)
		printf("%I64d\n",polya());
	return 0;
}