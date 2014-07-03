#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
int dp[20][8200],n,s,a[20];
int slove(int idx,int remain){
    if(dp[idx][remain]!=-1)
        return dp[idx][remain];
    if(remain==0)
        return dp[idx][remain]=1;
    dp[idx][remain]=0;
    for(int i=1;i<=a[idx]&&i<=remain;i++)
        if(!slove((idx+1)%(2*n),remain-i))
            dp[idx][remain]=1;
    return dp[idx][remain];
}
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        scanf("%d",&s);
        for(int i=0;i<2*n;i++)
            scanf("%d",&a[i]);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",slove(0,s));
    }
    return 0;
}

