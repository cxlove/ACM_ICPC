/*
ID:18756941
PROB:friday
LANG:C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 3405
#define M 12885
#define eps 1e-7
#define LL long long
#define LD long double
using namespace std;
int zeroonepack(int n,int maxweight,int *val,int *cost){
    int dp[M];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
        for(int j=maxweight;j>=cost[i];j--)
            dp[j]=max(dp[j],dp[j-cost[i]]+val[i]);
    int ans=0;
    for(int i=0;i<=maxweight;i++)
        ans=max(ans,dp[i]);
    return ans;
}
int n,maxweight;
int cost[N],val[N];
int main(){
    int t;
    while(scanf("%d%d",&n,&maxweight)!=EOF){     
        for(int i=0;i<n;i++)
            scanf("%d%d",&cost[i],&val[i]);
        printf("%d\n",zeroonepack(n,maxweight,val,cost));
    }
    return 0;
}
        
