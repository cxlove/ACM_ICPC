/*
ID:18756941
PROB:friday
LANG:C++
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 1005
#define M 12885
#define eps 1e-7
#define LL long long
#define LD long double
using namespace std;
int main(){
    int n,m,dp[N],cost[N];
    while(scanf("%d",&n)!=EOF&&n){   
        memset(dp,0,sizeof(dp));                      
        for(int i=0;i<n;i++)
            scanf("%d",&cost[i]);
        scanf("%d",&m);
        int mmin=m;
        dp[m]=1;
        sort(cost,cost+n);
        for(int i=0;i<n;i++)
            for(int j=5;j<=m;j++)
                if(dp[j]){
                     if(j-cost[i]>=5)
                         dp[j-cost[i]]=1;
                     mmin=min(mmin,j-cost[i]);
                }
        printf("%d\n",mmin);                          
    }
    return 0;
}
        
