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
struct Node{
    int cost,val;
}tmp;
vector<Node>a[11];
int n,m,k,kind;
int dp[15][10005]={0};
int main(){
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(int i=1;i<=k;i++)
            a[i].clear();
        for(int i=0;i<=k;i++)
            for(int j=0;j<=m;j++)
                dp[i][j]=-inf;
        dp[0][0]=0;
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&kind,&tmp.cost,&tmp.val);
            a[kind].push_back(tmp);
        }
        for(int i=1;i<=k;i++)
            for(int r=0;r<a[i].size();r++)
                for(int j=m;j>=0;j--)
                    if(j>=a[i][r].cost)
                        dp[i][j]=max(max(dp[i][j],dp[i-1][j-a[i][r].cost]+a[i][r].val),dp[i][j-a[i][r].cost]+a[i][r].val);
        int ans=0;
        for(int i=0;i<=m;i++) 
            ans=max(dp[k][i],ans);
        if(ans==0)
            printf("Impossible\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}