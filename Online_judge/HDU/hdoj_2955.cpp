#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-10
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1LL<<60
using namespace std;
int t,n,m,ans;
int cost[105];
double val[105],p,dp[10005];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%lf%d",&p,&n);
        m=0;
        for(int i=0;i<n;i++){
            scanf("%d%lf",&cost[i],&val[i]);
            m+=cost[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1.0;
        for(int i=0;i<n;i++)
            for(int j=m;j>=cost[i];j--)
                dp[j]=max((double)dp[j],(double)dp[j-cost[i]]*(1-val[i]));
        for(int i=m;i>=0;i--)
            if(dp[i]>=(1-p)){
                ans=i;
                break;
            }
        printf("%d\n",ans);
    }
    return 0;
}