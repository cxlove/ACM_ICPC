#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define eps 1e-10
#define N (1<<7)+5
#define inf 1<<20
#define zero(a) (fabs(a)<eps)
#define lson (step<<1)
#define rson (step<<1|1)
using namespace std;
double p[N][N];
double dp[10][N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n!=-1){
        for(int i=0;i<(1<<n);i++)
            for(int j=0;j<(1<<n);j++)
                scanf("%lf",&p[i][j]);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<(1<<n);i++) dp[0][i]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<(1<<n);j++){
                for(int k=0;k<(1<<n);k++){
                    if(((j>>(i-1))^1)==(k>>(i-1)))
                        dp[i][j]+=dp[i-1][k]*dp[i-1][j]*p[j][k];
                }
            }
        }
        double ans=0;
        int idx=-1;
        for(int i=0;i<(1<<n);i++)
            if(dp[n][i]>ans){
                ans=dp[n][i];
                idx=i+1;
            }
        printf("%d\n",idx);
    }
    return 0;
}


