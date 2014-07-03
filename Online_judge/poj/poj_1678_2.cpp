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
int num[10005],n,t,a,b;
int dp[10005];
int DP(int m){
    if(dp[m]!=-inf)
        return dp[m];
    int ans=-inf;
    for(int i=m+1;i<n;i++){
        if(num[i]-num[m]>=a&&num[i]-num[m]<=b)
             ans=max(ans,DP(i));
    }
    if(ans==-inf)
        return dp[m]=num[m];
    return dp[m]=num[m]-ans;
}
int slove(){
    int ans=-inf;
    for(int i=0;i<n;i++)
        if(num[i]>=a&&num[i]<=b)
             ans=max(ans,DP(i));
    return ans==-inf?0:ans;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&a,&b);
        for(int i=0;i<n;i++){
            dp[i]=-inf;
            scanf("%d",&num[i]);
        }
        sort(num,num+n);
        printf("%d\n",slove());
    }
    return 0;
}









