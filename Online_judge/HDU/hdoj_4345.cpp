#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
bool flag[1005];
int cnt=0,prime[1005];
LL dp[1001][501];
void Init(){
    memset(flag,false,sizeof(flag));
    for(int i=2;i<=1000;i++){
        if(flag[i])  continue;
        prime[cnt++]=i;
        for(int j=2;j*i<=1000;++j)
            flag[i*j]=true;
    }
}
LL DP(int n,int idx){
    if(dp[n][idx]!=-1)
        return dp[n][idx];
    if(idx>=cnt)
        return dp[n][idx]=1;
    dp[n][idx]=DP(n,idx+1);
    int p=prime[idx];
    while(p<=n){
        dp[n][idx]=(LL)dp[n][idx]+DP(n-p,idx+1);
        p*=prime[idx];
    }
    return dp[n][idx];
}
int main(){
    Init();
    int n;
    memset(dp,-1,sizeof(dp));
    while(scanf("%d",&n)!=EOF)
        printf("%I64d\n",DP(n,0));
    return 0;
}
