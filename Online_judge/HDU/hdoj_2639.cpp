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
int val[105],cost[105],n,v,k;
int dp[1005][35];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int tmp[65],cnt=0;
        scanf("%d%d%d",&n,&v,&k);
        for(int i=0;i<n;i++)
            scanf("%d",&val[i]);
        for(int i=0;i<n;i++)
            scanf("%d",&cost[i]);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=v;j>=cost[i];j--){
                cnt=0;
                for(int r=0;r<k;r++){
                    tmp[cnt++]=dp[j][r];
                    tmp[cnt++]=dp[j-cost[i]][r]+val[i];
                }
                sort(tmp,tmp+cnt,cmp);
                for(int r=0,t=0;r<k&&t<cnt;t++)
                    if(r==0||tmp[t]!=dp[j][r-1]){
                        dp[j][r]=tmp[t];
                        r++;
                    }
            }
        }
        printf("%d\n",dp[v][k-1]);
    }
    return 0;
}