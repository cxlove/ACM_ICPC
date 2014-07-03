#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n,p[200]={0};
	while(scanf("%d",&n)!=EOF&&n){
		int m=1;
		for(int i=1;i<n-1;i++){
			p[i]=(p[i-1]+m-1)%(n-i);
			if(p[i]==0){
				i=0;
				m++;
			}
		}
		printf("%d\n",m);
	}
	return 0;
}