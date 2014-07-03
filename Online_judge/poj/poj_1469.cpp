/*
ID:cxlove
PROB:poj 1469 COURSES
DATA:2012.1.14
HINT:匈牙利算法求二分匹配
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
bool mat[301][301];
bool vis[301];
int link[301];
int n,p;
bool dfs(int a){
	for(int i=1;i<=n;i++)
		if(mat[a][i]&&!vis[i]){
			vis[i]=true;
			if(link[i]==0||dfs(link[i])){
				link[i]=a;
				return true;
			}
		}
		return false;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(mat,false,sizeof(mat));
		scanf("%d%d",&p,&n);
		for(int i=1;i<=p;i++){
			int count;
			scanf("%d",&count);
			while(count--){
				int j;
				scanf("%d",&j);
				mat[i][j]=true;
			}
		}
		memset(link,0,sizeof(link));
		int num=0;
		for(int i=1;i<=p;i++){
			memset(vis,false,sizeof(vis));
			if(dfs(i))
				num++;
		}
		if(num==p)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}