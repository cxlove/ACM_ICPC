#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int num[1005];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int k=0;
		for(int i=2;i<=n;i++){
			num[k++]=i;
			n-=i;
		}
		for(int i=k-1;n;i--){
			num[i]++;
			n--;
			if(i==0)
				i=k;
		}
		printf("%d",num[0]);
		for(int i=1;i<k;i++)
			printf(" %d",num[i]);
		printf("\n");
	}
	return 0;
}
	