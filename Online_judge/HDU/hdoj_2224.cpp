#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define inf 1<<25
using namespace std;
int n,x[201],y[201];
double dp[201][201],dist[201][201];
double Dist(int i,int j){
    return sqrt(1.0*(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dist[i][j]=Dist(i,j);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dp[i][j]=inf;
        dp[1][1]=0;
        dp[1][2]=dist[1][2];
        for(int i=2;i<n;i++)
            for(int j=1;j<i;j++){
                dp[j][i+1]=min(dp[j][i+1],dp[j][i]+dist[i][i+1]);
                dp[i][i+1]=min(dp[i][i+1],dp[j][i]+dist[j][i+1]);
            }
            printf("%.2f\n",dp[n-1][n]+dist[n-1][n]);
    }
    return 0;
}
