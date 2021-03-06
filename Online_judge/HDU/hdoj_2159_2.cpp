/*
ID:cxlove
PROB:FATE
DATA:2012.3.1
HINT:二维费用背包
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int n,m,k,s;
    int dp[105][105];
    int val[105],cost[105];
    while(cin>>n>>m>>k>>s){
        for(int i=0;i<k;i++)
            cin>>val[i]>>cost[i];
        memset(dp,0,sizeof(dp));
        int ans=-1;
        for(int r=0;r<k;r++){
            for(int i=0;i<s;i++)
                for(int j=0;j<=m-cost[r];j++){
                    dp[i+1][j+cost[r]]=max(dp[i+1][j+cost[r]],dp[i][j]+val[r]);
                    if(dp[i+1][j+cost[r]]>=n)
                        ans=max(ans,m-j-cost[r]);

                }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
10 10 1 10
1 1
10 10 1 9
1 1
9 10 2 10
1 1
2 2
*/
