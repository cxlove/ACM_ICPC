#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 500;
int a[N][N],n;
int dp[N][N];
int main(){
    while(cin>>n){
        memset(a,-1,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                cin>>a[i][j];
        dp[1][1]=a[1][1];
        for(int i=1;i<n;i++){
            for(int j=1;j<=i;j++){
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]+a[i+1][j]);
                dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+a[i+1][j+1]);
            }
        }
        int ans=-1;
        for(int i=1;i<=n;i++)
            ans=max(ans,dp[n][i]);
        cout<<ans<<endl;
    }
    return 0;
}