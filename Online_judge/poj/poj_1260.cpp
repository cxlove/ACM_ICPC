#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 105;
int a[N],p[N],s[N],dp[N],n;
int main(){
    int t;scanf("%d",&t);
    while(t--){
        memset(dp,0x11,sizeof(dp));
        scanf("%d",&n);
        s[0]=0;
        dp[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&a[i],&p[i]);
            s[i]=s[i-1]+a[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++)
                dp[i]=min(dp[i],dp[j]+(s[i]-s[j]+10)*p[i]);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}