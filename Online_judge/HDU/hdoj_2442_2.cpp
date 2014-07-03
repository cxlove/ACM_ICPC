/*
ID:cxlove
PROB;hdu 2242 bricks 08哈尔滨现场赛
DATA;2012.1.12
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[101][729];
int n,m;
int Pow[10];
int state1[10],state2[10];
void putstate(int state,int three[6]){
    for(int i=0;i<m;i++,state/=3)
        three[i]=state%3;
}
int getstate(int three[6]){
    int state=0;
    for(int i=0;i<m;i++)
        state+=(three[i]*Pow[i]);
    return state;
}
void Init(){
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++){
        state2[i]=1;
        state1[i]=0;
    }
    dp[1][getstate(state2)]=0;
}
void dfs(int i,int j,int idx,int num){
    if(idx>=m){
      dp[i][j]=max(dp[i][j],num);
        return ;
    }
    if(idx+1<m&&state2[idx]==0&&state2[idx+1]==0&&state1[idx+1]==0){
        state2[idx+1]=2;state2[idx]=1;
        dfs(i,getstate(state2),idx+2,num+4);
        state2[idx+1]=state2[idx]=0;
    }
    if(idx+2<m&&state2[idx]==0&&state2[idx+1]==0&&state2[idx+2]==0&&state1[idx+1]==0){
        state2[idx]=state2[idx+2]=1;state2[idx+1]=2;
        dfs(i,getstate(state2),idx+2,num+5);
        state2[idx]=state2[idx+2]=state2[idx+1]=0;
    }
    if(idx+2<m&&state2[idx]==0&&state2[idx+1]==0&&state2[idx+2]==0){
        state2[idx]=state2[idx+2]=1;state2[idx+1]=2;
        dfs(i,getstate(state2),idx+2,num+4);
        state2[idx]=state2[idx+2]=state2[idx+1]=0;
    }
    if(idx+2<m&&state2[idx]==0&&state2[idx+1]==0&&state2[idx+2]==0){
        state2[idx]=state2[idx+1]=1;state2[idx+2]=2;
        dfs(i,getstate(state2),idx+2,num+4);
        state2[idx]=state2[idx+2]=state2[idx+1]=0;
    }
    if(idx+1<m&&state2[idx+1]==0&&state1[idx]==0&&state1[idx+1]==0){
        state2[idx+1]=2;
        dfs(i,getstate(state2),idx+2,num+4);
        state2[idx+1]=0;
    }
    dfs(i,j,idx+1,num);
}
int main(){
    Pow[0]=1;
    for(int i=1;i<=6;i++)
        Pow[i]=Pow[i-1]*3;
    while(scanf("%d%d",&n,&m)!=EOF){
        Init();
        for(int i=2;i<=n;i++){
            for(int j=0;j<Pow[m];j++){
                if(dp[i-1][j]!=-1){
                    putstate(j,state1);
                    for(int k=0;k<m;k++)
                        state2[k]=max(0,state1[k]-1);
                    dfs(i,getstate(state2),0,dp[i-1][j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<Pow[m];i++)
            ans=max(ans,dp[n][i]);
        printf("%d\n",ans);
    }
    return 0;
}
