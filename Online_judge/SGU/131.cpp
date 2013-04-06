#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <set>
#include <vector>
#define LD long double
#define pi acos(-1.0)
#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))
using namespace std;
long long dp[15][1<<9];
int n,m;
set<int>statu[2];
void dfs(int row,int col,int now,int next,int pre){
  if(col>=m){
		dp[row+1][next]+=dp[row][pre];
		statu[(row+1)&1].insert(next);
		return ;
	}
	if(row>n) return ;
	if(now&(1<<col)){
		dfs(row,col+1,now,next,pre);
		return ;
	}
	//  11
	if(col<m-1){
		if(!(now&(1<<(col+1))))
			dfs(row,col+2,now+(1<<col)+(1<<(col+1)),next,pre);
	}
	//  1
	//  1
	if(row<n){
		if(!(next&(1<<col)))
			dfs(row,col+1,now+(1<<col),next+(1<<col),pre);
	}
	//  11
	//  1
	if(row<n&&col<m-1){
		if(!(now&(1<<(col+1)))&&!(next&(1<<col)))
			dfs(row,col+2,now+(1<<col)+(1<<(col+1)),next+(1<<col),pre);
	}
	// 11
	//  1
	if(row<n&&col<m-1){
		if(!(now&(1<<(col+1)))&&!(next&(1<<(col+1))))
			dfs(row,col+2,now+(1<<col)+(1<<(col+1)),next+(1<<(col+1)),pre);
	}
	//  1
	// 11
	if(col>0&&row<n){
		if(!(next&(1<<col))&&!(next&(1<<(col-1))))
			dfs(row,col+1,now+(1<<col),next+(1<<col)+(1<<(col-1)),pre);
	}
	// 1
	// 11
	if(col<m-1&&row<n){
		if(!(next&(1<<col))&&!(next&(1<<(col+1))))
			dfs(row,col+1,now+(1<<col),next+(1<<col)+(1<<(col+1)),pre);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	memset(dp,0,sizeof(dp));
	dp[1][0]=1;
	statu[1].insert(0);
	for(int i=1;i<=n;i++){
		set<int>::iterator it;
		for(it=statu[i&1].begin();it!=statu[i&1].end();it++)
			dfs(i,0,*it,0,*it);
		statu[i&1].clear();
	}
	printf("%I64d\n",dp[n+1][0]);
	return 0;
}
