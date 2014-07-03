#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int flag=0,ans=0,t;
		for(int i=0;i<n;i++){
			scanf("%d",&t);
			ans^=t;
			if(t>1) flag=1;
		}
		if(flag){
			if(ans==0)
		    	printf("No\n");
			else
				printf("Yes\n");
		}
		else{
			if(n%2==0)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}