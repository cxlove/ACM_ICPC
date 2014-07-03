#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#define eps 1e-6
using namespace std;
int main(){
	__int64 n;
	while(scanf("%I64d",&n)!=EOF&&n){
		bool flag=false;
		if(n<0) {flag=true;n=-n;}
		for(int i=32;i>=1;i--){
			__int64 temp=(__int64)(eps+pow(n,1.0/i));
			__int64 sum=1;
			int j=i;
			while(j--)
				sum=sum*temp;
			if((sum==n&&!flag)||(sum==n&&flag&&i%2==1)){
				printf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}