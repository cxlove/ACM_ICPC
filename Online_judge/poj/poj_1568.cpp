#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<queue>  
#include<algorithm>  
#include<set>  
#define inf 1<<30
#define N 50005  
#define maxn 100005  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define eps 1e-9  
#define zero(a) fabs(a)<eps  
#define LL long long  
#define ULL unsigned long long  
#define lson (step<<1)  
#define rson (step<<1|1)  
#define MOD 1000000007  
#define mp(a,b) make_pair(a,b)  
using namespace std;  
char str[5][5];
int X,Y,chess;
//判断一个局面是否结束
bool check(int x,int y){
	int tot=0;
	//横向判断
	for(int i=0;i<4;i++)
		if(str[x][i]=='o') tot++;
		else if(str[x][i]=='x') tot--;
	if(tot==4||tot==-4) return true;
	tot=0;
	//纵向判断
	for(int i=0;i<4;i++)
		if(str[i][y]=='o') tot++;
		else if(str[i][y]=='x') tot--;
	if(tot==4||tot==-4) return true;
	tot=0;
	//正对角线判断
	for(int i=0;i<4;i++)
		if(str[i][i]=='o') tot++;
		else if(str[i][i]=='x') tot--;
	if(tot==4||tot==-4) return true;
	tot=0;
	//反对角线判断
	for(int i=0;i<4;i++)
		if(str[i][3-i]=='o') tot++;
		else if(str[i][3-i]=='x') tot--;
	if(tot==4||tot==-4) return true;
	return false;
}
int MinSearch(int x,int y,int beta);
int MaxSearch(int x,int y,int alpha);
int MaxSearch(int x,int y,int alpha){
	int ans=-inf;
	//已经结束
	if(check(x,y)) return ans;
	//平局
	if(chess==16) return 0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(str[i][j]=='.'){
				str[i][j]='x';chess++;
				int tmp=MinSearch(i,j,ans);
				str[i][j]='.';chess--;
				ans=max(ans,tmp);
				if(ans>=alpha) return ans;
			}
	return ans;
}
int MinSearch(int x,int y,int beta){
	int ans=inf;
	//已经结束
	if(check(x,y)) return ans;
	//平局
	if(chess==16) return 0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(str[i][j]=='.'){
				str[i][j]='o';chess++;
				int tmp=MaxSearch(i,j,ans);
				str[i][j]='.';chess--;
				ans=min(ans,tmp);
				if(ans<=beta) return ans;
			}
	return ans;
}
bool slove(){
	int beta=-inf;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(str[i][j]=='.'){
				str[i][j]='x';chess++;
				int tmp=MinSearch(i,j,beta);
				str[i][j]='.';chess--;
				beta=max(tmp,beta);
				if(beta==inf){
					X=i;
					Y=j;
					return true;
				}
			}
	return false;
}
int main(){
	char ch[5];
	while(scanf("%s",ch)!=EOF&&ch[0]!='$'){
		chess=0;
		for(int i=0;i<4;i++){
			scanf("%s",str[i]);
			for(int j=0;j<4;j++)
				chess+=str[i][j]!='.';
		}
		/*if(chess<=4){
			printf("#####\n");
			continue;
		}*/
		if(slove()) printf("(%d,%d)\n",X,Y);
		else printf("#####\n");
	}
	return 0;
}

