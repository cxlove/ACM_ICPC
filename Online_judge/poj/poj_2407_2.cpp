#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
int eular(int num){
	int sum=1;
	for(int i=2;i*i<=num;i++)
		if(num%i==0){ 
			sum*=i-1;
			num/=i;
			while(num%i==0){
				sum*=i;
				num/=i;
			}
		}
		if(num>1)
			sum*=num-1;
		return sum;		
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n)
		printf("%d\n",eular(n));
	return 0;
}