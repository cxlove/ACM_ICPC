#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1005;
int n,a[N]={-1},dp[N];
int main(){
    while(cin>>n){
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>a[i];
            for(int j=0;j<i;j++)
                if(a[i]>a[j])
                    dp[i]=max(dp[i],dp[j]+1);
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}