#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int Pow(int n){
	if(n==0)
		return 1;
	return 10*Pow(n-1);
}
int main(){
	char str[10];
	while(scanf("%s",str)!=EOF&&strcmp(str,"00e0")!=0){
		int a,b;
		sscanf(str,"%de%d",&a,&b);
		a=a*Pow(b);
		for(int i=1;;i*=2)
			if(a>=i&&a<2*i){
				printf("%d\n",(a-i)*2+1);
				break;
			}
	}
	return 0;
}