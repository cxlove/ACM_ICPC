#include<iostream>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<algorithm>
#include<cstdlib>
#define LL long long
#define TIME  8
using namespace std;
int flag[1300000]={0},cnt=0;
int prime[100005];	
int a,b,c,ans[1005];
void Prime(){
	for(int i=2;i<=10000;i++){
		if(flag[i])
			continue;
		prime[cnt++]=i;
		for(int j=2;j*i<=10000;j++)
			flag[i*j]=1;
	}
}
int temp;
int vis[1005];
void dfs(int cnt){
	if(temp)
		return;
	if(cnt==(b-a+1)){
		temp=1;
		printf("%d",ans[0]);
		for(int i=1;i<=b-a;i++)
			printf(",%d",ans[i]);
		printf("\n");
		return;
	}
	for(int i=0;i<=b-a;i++){
		if(vis[i]==0){
			ans[cnt]=i+a;
			int sum=i+a;
			bool id=false;
			for(int j=cnt-1;j>=0&&j>=cnt-c+1;j--){
				sum+=ans[j];
				if(flag[sum]==0){
					id=true;
					break;
				}
			}
			if(!id){
				vis[i]=1;
				dfs(cnt+1);
				vis[i]=0;
			}
		}
	}
}
int main(){
	Prime();
	while(scanf("%d%d%d",&a,&b,&c)!=EOF&&a+b+c){
		temp=0;
		memset(vis,0,sizeof(vis));
		dfs(0);
		if(temp==0)
			printf("No anti-prime sequence exists.\n");
	}
	return 0;
}
	