/*
ID:cxlove
PROB:poj 2246 Chessboard
DATA:2012.1.15
HINT:二分图最大匹配
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,k;
int mat[600][600]={0};
int vis[600]={0};
int mmap[35][35]={0};
int link[600]={0};
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int odd_count=0,even_count=0;
int a[35][35];
bool dfs(int u){
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if((i+j)&1&&!vis[a[i][j]]&&mat[u][a[i][j]]){
				vis[a[i][j]]=true;
				if(link[a[i][j]]==0||dfs(link[a[i][j]])){
					link[a[i][j]]=u;
					return true;
				}
			}
			return false;
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<k;i++){
		int x,y;
		cin>>y>>x;
		mmap[x][y]=1;
	}

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if((i+j)&1)
				a[i][j]=(++even_count);
			else
				a[i][j]=(++odd_count);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(((i+j)&1)==0&&mmap[i][j]==0){
				for(int r=0;r<4;r++){
					int x=i+way[r][0];
					int y=j+way[r][1];
					if(x>=1&&x<=n&&y>=1&&y<=m&&mmap[x][y]==0)
						mat[a[i][j]][a[x][y]]=1;
				}
			}
		}
	}	
	int num=0;   
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			memset(vis,0,sizeof(vis));
			if(((i+j)&1)==0&&dfs(a[i][j]))
				num++;
            }
	if(2*num+k==n*m)
		puts("YES");
	else
		puts("NO");

	return 0;
}

				
