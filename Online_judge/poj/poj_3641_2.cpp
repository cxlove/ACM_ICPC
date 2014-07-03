#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
bool isprime(__int64 num){
	for(int i=2;i<=sqrt(num*1.0);i++)
		if(num%i==0)
			return false;
	return true;
}
__int64 bigmod(__int64 a,__int64 p,__int64 m){
	if(p==0) return 1;
	if(a==0||m==1) return 0;
	__int64 temp=bigmod(a,p>>1,m);
	if(p&1)		
		return ((__int64)(a%m)*bigmod(a,p-1,m))%m;
	else
		return ((__int64)(temp*temp))%m;
}
int main(){
	__int64 p,a;
	while(scanf("%I64d%I64d",&p,&a)!=EOF&&a+p){
		if(isprime(p))
			printf("no\n");
		else
			if(bigmod(a,p,p)==a)
				printf("yes\n");
			else
				printf("no\n");
	}
	return 0;
}