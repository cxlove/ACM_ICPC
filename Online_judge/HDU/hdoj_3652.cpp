#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 100005
#define inf 1<<29
#define MOD 9973
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
int dp[10][13][3];
//dp[i][j][k]表示i位数，对13的余数是j
//k为0表示没有出现13
//k为1表示没有出现13，但是首位为3
//k为2表示出现13
int bit[15],len;
//分别表示当前考虑的位置，前一个数字，当前余数，是否有限制，是否已经出现13
int dfs(int pos,int pre,int mod,bool limit,bool flag){
    if(pos<=0) return flag&&(mod==0);
    if(!limit&&flag&&dp[pos][mod][0]!=-1)  return  dp[pos][mod][0];
    if(!limit&&!flag&&pre!=1&&dp[pos][mod][2]!=-1) return dp[pos][mod][2];
    if(!limit&&!flag&&pre==1&&dp[pos][mod][1]!=-1) return dp[pos][mod][1];
    int end=(limit?bit[pos]:9);
    int ret=0;
    for(int i=0;i<=end;i++)
        ret+=dfs(pos-1,i,(mod*10+i)%13,limit&&(i==end),flag||(pre==1&&i==3));
    if(!limit){
        if(pre==1&&!flag) dp[pos][mod][1]=ret;
        if(pre!=1&&!flag) dp[pos][mod][2]=ret;
        if(flag) dp[pos][mod][0]=ret;
    }
    return ret;
}
int slove(int n){    
    len=0;
    while(n){
        bit[++len]=n%10;
        n/=10;
    }
    return dfs(len,0,0,true,false);
}
int main(){
    int n;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",slove(n));
    return 0;
}