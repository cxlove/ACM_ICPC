#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a,b,c,d,e,f;
int main(){
	int u[4]={0,5,3,1};
	while(scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)&&a+b+c+d+e+f){
		int ans=d+e+f+(c+3)/4;
		int x=d*5+u[c%4];
		if(b>=x)
			ans+=(b-x+8)/9;
		int y=36*ans-36*f-25*e-16*d-9*c-4*b;
		if(a>y)
			ans+=(a-y+35)/36;
		printf("%d\n",ans);
	}
	return 0;
}