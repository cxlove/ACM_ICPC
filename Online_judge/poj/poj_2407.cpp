#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int eular(int n){
	int ans=1;
	for(int i=2;i<=sqrt(n+1.0);i++){
		if(n%i==0){
			ans*=(i-1);
			n/=i;
			while(n%i==0){
				ans*=i;
				n/=i;
			}
		}
	}
	if(n!=1)
		ans*=(n-1);
	return ans;
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n)
		printf("%d\n",eular(n));
	return 0;
}