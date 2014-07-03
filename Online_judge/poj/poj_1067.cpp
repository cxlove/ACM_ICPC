#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int a,b;
int main(){
	while(scanf("%d%d",&a,&b)!=EOF){
		if(a>b)
			swap(a,b);
		if(a==(int)((sqrt(5.0)+1)*(b-a)/2))
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}
