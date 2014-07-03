#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define eps 1e-10
#define N 100005
#define inf 1<<20
#define zero(a) (fabs(a)<eps)
#define lson (step<<1)
#define rson (step<<1|1)
using namespace std;
int n,t,m;
double a[1005][30];
double dp[35][35];
int main(){
    while(scanf("%d%d%d",&n,&t,&m)!=EOF&&n+t+m){
        double sum=1;
        for(int i=1;i<=t;i++){
            double tmp=1;
            for(int j=1;j<=n;j++){
                scanf("%lf",&a[i][j]);
                tmp*=1-a[i][j];
            }
            sum*=1-tmp;
        }
        double temp=1;
        for(int i=1;i<=t;i++){
            memset(dp,0,sizeof(dp));
            dp[0][0]=1;
            for(int j=1;j<=n;j++){
                for(int k=0;k<j;k++){
                    dp[j][k+1]+=dp[j-1][k]*a[i][j];
                    dp[j][k]+=dp[j-1][k]*(1-a[i][j]);
                }
            }
            double tmp=0;
            for(int j=1;j<m;j++) tmp+=dp[n][j];
            temp*=tmp;
        }
        printf("%.3f\n",sum-temp);
    }
    return 0;
}











