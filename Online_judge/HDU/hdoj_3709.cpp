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
LL dp[20][20][2005];
//dp[i][j][k]表示考虑i位数字，支点为j，力矩和为k
int bit[20],len;
LL dfs(int pos,int central,int pre,bool limit){
    if(pos<=0) return pre==0;
    if(pre<0)  return 0;
    if(!limit&&dp[pos][central][pre]!=-1) return dp[pos][central][pre];
    int end=limit?bit[pos]:9;
    LL ret=0;
    for(int i=0;i<=end;i++)
        ret+=dfs(pos-1,central,pre+i*(pos-central),limit&&(i==end));
    if(!limit)
        dp[pos][central][pre]=ret;
    return ret;
}
LL slove(LL n){
    len=0;
    while(n){
        bit[++len]=n%10;
        n/=10;
    }
    LL ans=0;
    for(int i=1;i<=len;i++)
        ans+=dfs(len,i,0,true);
    return ans-len+1;
}
int main(){
    LL l,r;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d",&l,&r);
        memset(dp,-1,sizeof(dp));
        printf("%I64d\n",slove(r)-slove(l-1));
    }
    return 0;
}
