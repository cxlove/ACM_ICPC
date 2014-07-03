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
#define inf 1<<25
using namespace std;
int dp[105][1005];
int n,m,l;
int a[105],b[105];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&l);
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i],&b[i]);
        for(int i=0;i<=m;i++)
            for(int j=0;j<=l;j++)
                dp[i][j]=-inf;
        dp[0][0]=0;
        for(int i=0;i<n;i++)
            for(int j=m;j>=1;j--)
                for(int r=l;r>=a[i];r--)
                    if(dp[j-1][r-a[i]]!=-inf)
                        dp[j][r]=max(dp[j][r],dp[j-1][r-a[i]]+b[i]);
        int ans=0;
        for(int i=0;i<=l;i++)
            ans=max(ans,dp[m][i]);
        printf("%d\n",ans);
    }
    return 0;
}