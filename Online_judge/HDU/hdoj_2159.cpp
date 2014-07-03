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
int dp[105][105];
int n,m,k,s;
int a[105],b[105];
int main(){
    while(scanf("%d%d%d%d",&n,&m,&k,&s)!=EOF){
        for(int i=0;i<k;i++)
            scanf("%d%d",&a[i],&b[i]);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<k;i++)
            for(int j=1;j<=s;j++)
                for(int r=b[i];r<=m;r++)
                    dp[j][r]=max(dp[j][r],dp[j-1][r-b[i]]+a[i]);
        int i;
        for(i=0;i<=m;i++)
            if(dp[s][i]>=n)
                break;
        printf("%d\n",i>m?-1:m-i);
    }
    return 0;
}