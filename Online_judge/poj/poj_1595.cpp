#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool f[10000];
void prime(){
	memset(f,false,sizeof(f));
	for(int i=2;i<=100;i++){
		if(f[i])  continue;
		for(int j=2;i*j<=9999;j++)
			f[i*j]=true;
	}
}
int main(){
	int n,c;
	prime();
	while(scanf("%d%d",&n,&c)!=EOF){
		int cnt=0;
		int prime[10000];
		f[0]=true;
		for(int i=1;i<=n;i++)
			if(!f[i])
				prime[cnt++]=i;
		printf("%d %d:",n,c);
		if(cnt&1){		
			for(int i=max(0,cnt/2-c/2);i<=min(cnt-1,cnt/2+c/2);i++)
				printf(" %d",prime[i]);
			printf("\n");
		}
		else{
			for(int i=max(0,cnt/2-c);i<=min(cnt-1,cnt/2+c-1);i++)
				printf(" %d",prime[i]);
			printf("\n");		
		}
		printf("\n");
	}
	return 0;
}
