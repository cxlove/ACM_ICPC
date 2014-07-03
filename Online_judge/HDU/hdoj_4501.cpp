#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#define LL long long
using namespace std;
int n,v1,v2,k;
int dp[101][101][101][6];
int main(){
    while(cin>>n>>v1>>v2>>k){
        memset(dp,0,sizeof(dp));
        for(int t=1;t<=n;t++){
            int a,b,val;
            cin>>a>>b>>val;
            for(int i=v1;i>=0;i--){
                for(int j=v2;j>=0;j--){
                    for(int r=k;r>=0;r--){
                        dp[t][i][j][r]=dp[t-1][i][j][r];
                        if(i>=a) dp[t][i][j][r]=max(dp[t-1][i-a][j][r]+val,dp[t][i][j][r]);
                        if(j>=b) dp[t][i][j][r]=max(dp[t-1][i][j-b][r]+val,dp[t][i][j][r]);
                        if(r) dp[t][i][j][r]=max(dp[t-1][i][j][r-1]+val,dp[t][i][j][r]);
                    }
                }
            }          
        }
        int ans=0;
        for(int i=0;i<=v1;i++) for(int j=0;j<=v2;j++) for(int r=0;r<=k;r++)ans=max(ans,dp[n][i][j][r]);
        cout<<ans<<endl;
    }
    return 0;
}