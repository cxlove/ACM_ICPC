#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
LL a[100005]={0},b[100005];
int main(){
	int n,k,c;
	while(scanf("%d%d",&c,&n)!=EOF&&n+c){
		bool flag=false;
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			if(flag) continue;
			a[i]=a[i-1]+k;
			if(a[i]%c==0){
				for(int j=1;j<i;j++)
					printf("%d ",j);
				printf("%d\n",i);
				flag=true;
			}
			else if(b[a[i]%c]){
				for(int j=b[a[i]%c]+1;j<i;j++)
					printf("%d ",j);
				printf("%d\n",i);
				flag=true;
			}
			else
				b[a[i]%c]=i;
		}
	}
	return 0;
}