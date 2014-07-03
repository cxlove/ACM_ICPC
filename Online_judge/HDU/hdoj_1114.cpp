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
#define eps 1e-6
#define LL long long
#define LD long double
#define pi acos(-1.0)
#define inf 1<<30
using namespace std;
int t,m,a,b,n;
int cost[505],val[505],dp[10005];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&a,&b,&n);
        m=b-a;
        for(int i=0;i<n;i++)
            scanf("%d%d",&val[i],&cost[i]);
        for(int i=0;i<=m;i++)
            dp[i]=inf;
        dp[0]=0;
        for(int i=0;i<n;i++)
            for(int j=cost[i];j<=m;j++)
                if(dp[j-cost[i]]!=inf)
                    dp[j]=min(dp[j],dp[j-cost[i]]+val[i]);
        if(dp[m]!=inf)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
        else
            printf("This is impossible.\n");
    }
    return 0;
}