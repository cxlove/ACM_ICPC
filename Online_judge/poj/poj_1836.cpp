#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1005;
int n,dp[N][2];
double h[N];
int main(){
    while(scanf("%d",&n)!=EOF){
        memset(dp,0x11,sizeof(dp));
        h[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%lf",&h[i]);
        dp[0][0]=0.0;
        int ans=n-1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(h[i]>h[j]) 
                    dp[i][0]=min(dp[i][0],dp[j][0]+i-j-1);
                if(h[i]>=h[j])
                    dp[i][1]=min(dp[i][1],dp[j][0]+i-j-1);
                if(h[i]<h[j])
                    dp[i][1]=min(dp[i][1],dp[j][1]+i-j-1);
            }
            //cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
            ans=min(ans,min(dp[i][0],dp[i][1])+n-i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
