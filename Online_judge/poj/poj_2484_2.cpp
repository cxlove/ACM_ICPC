#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n;
int main(){
	while(scanf("%d",&n)!=EOF&&n){
		if(n>2)
			printf("Bob\n");
		else
			printf("Alice\n");
	}
	return 0;
}