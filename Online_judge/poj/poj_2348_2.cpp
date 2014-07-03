#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF&&a+b){
		if(a<b)
			swap(a,b);
		bool flag=true;
		while(1){
			if(b==0||a/b>=2||a%b==0) break;
			int t=b;
			b=a-b;
			a=t;
			flag=!flag;
		}
		if(!flag)
			printf("Ollie wins\n");
		else
			printf("Stan wins\n");
	}
	return 0;
}
