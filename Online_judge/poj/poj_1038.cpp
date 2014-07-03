/*
ID:cxlove
PROB:poj 1038 Bugs Integrated, Inc
DATA:2012.1.11
HINT:状态压缩DP
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#define Max(A,B) (A)>(B)?(A):(B)
using namespace std;
int dp[2][59049];
int mmap[151][10];
int Pow[11];
int state1[10];    //上一行状态
int state2[10];    //当前行状态
int n,m,k;
int getstate(int three[10]){
	int state=0;
	for(int i=0;i<m;i++)
		state+=three[i]*Pow[i];
	return state;
}
void putstate(int state,int three[10]){
	for(int i=0;i<m;i++,state/=3)
		three[i]=state%3;
}
void Init(){
	memset(dp[1],-1,sizeof(dp[1]));
	for(int i=0;i<m;i++)
		state2[i]=mmap[1][i]+1;
	dp[1][getstate(state2)]=0;
}
void dfs(int i,int j,int idx,int num){
    
    int temp;
	if(idx>=m){
        dp[i&1][j]=max(dp[i&1][j],num);
		return ;
    }
	if(idx+2<m&&state2[idx]==0&&state2[idx+1]==0&&state2[idx+2]==0){
		state2[idx]=state2[idx+1]=state2[idx+2]=2;
		temp=getstate(state2);
		dfs(i,temp,idx+3,num+1);
		state2[idx]=state2[idx+1]=state2[idx+2]=0;
	}
	if(idx+1<m&&state2[idx]==0&&state2[idx+1]==0&&state1[idx]==0&&state1[idx+1]==0){
		state2[idx]=state2[idx+1]=2;
		temp=getstate(state2);
		dfs(i,temp,idx+2,num+1);
		state2[idx]=state2[idx+1]=0;
	}
	dfs(i,j,idx+1,num);
}
int main(){
    int t;
    scanf("%d",&t);
	Pow[0]=1;
	for(int i=1;i<=10;i++)
		Pow[i]=Pow[i-1]*3;
    while(t--){
		memset(mmap,0,sizeof(mmap));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<k;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			mmap[x][m-y]=1;
		}
		Init();
		for(int i=2;i<=n;i++){
			memset(dp[i&1],-1,sizeof(dp[i&1]));
			for(int j=0;j<Pow[m];j++){
				if(dp[(i+1)&1][j]!=-1){
					putstate(j,state1);
					for(int k=0;k<m;k++)
						if(mmap[i][k])
							state2[k]=2;
						else
							state2[k]=max(0,state1[k]-1);
				}
				dfs(i,getstate(state2),0,dp[(i+1)&1][j]);
			}
		}
   		int ans=0;
		for(int i=0;i<Pow[m];i++)
			ans=max(ans,dp[n&1][i]);
		printf("%d\n",ans);
	}
	return 0;
}
		

