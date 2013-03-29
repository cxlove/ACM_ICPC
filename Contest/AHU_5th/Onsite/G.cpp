#include<ctime>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#define LL long long 
using namespace std;
int n,k;
LL l,r;
double dp[1005][1005];
LL get(LL m){
    LL ret=1;
    while(m){
        m/=10;
        ret*=10;
    }
    return ret/10;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            scanf("%I64d%I64d",&l,&r);
            LL ret=0;
            for(LL i=get(l);i<=r&&i>0;i*=10){
                ret+=min(i,r-i+1);
                if(i<l) ret-=min(i,l-i);
            }
            double p=ret*1.0/(r-l+1),q=1-p;
            for(int j=0;j<i;j++){
                dp[i][j]+=dp[i-1][j]*q;
                dp[i][j+1]+=dp[i-1][j]*p;
            }
        }
        scanf("%d",&k);
        k=(int)ceil(n*k*0.01);
        double ans=0;
        for(int i=k;i<=n;i++)
            ans+=dp[n][i];
        printf("%.6f\n",ans);
    }
    //printf("%.6lf",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}