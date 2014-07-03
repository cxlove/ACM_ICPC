#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
using namespace std;
__int64 a[1000005]={0};
void slove(){
	int n=1000001;
	for(int i=2;i<n;i++)
		a[i]=i;
	for(int i=2;i<n;i++)
		if(a[i]==i){
			a[i]=i-1;
			for(int j=2;j*i<n;j++)
				a[i*j]=a[i*j]/i*(i-1);
		}
	for(int i=2;i<n;i++)
		a[i]+=a[i-1];
}
int main(){
	int n;
	slove();
	while(scanf("%d",&n)!=EOF&&n){
		printf("%I64d\n",a[n]);
	}
	return 0;
}