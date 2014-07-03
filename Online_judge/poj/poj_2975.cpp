#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[1005];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF&&n){
		int flag=0,ans=0,t;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			ans^=a[i];
		}
		if(ans==0)
			printf("0\n");
		else{
			int cnt=0;
			for(int i=0;i<n;i++)
				if(a[i]>=(ans^a[i]))
					cnt++;
			printf("%d\n",cnt);
		}
	}
	return 0;
}