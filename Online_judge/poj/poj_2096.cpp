#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double dp[1005][1005];
int n,m;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        dp[n][m]=0;
        for(int i=n-1;i>=0;i--)
           dp[i][m]=dp[i+1][m]+(double)n/(n-i);
        for(int i=m-1;i>=0;i--)
           dp[n][i]=dp[n][i+1]+(double)m/(m-i);
        for(int i=n-1;i>=0;i--)
           for(int j=m-1;j>=0;j--){
               dp[i][j]=dp[i+1][j]*(n-i)*j/(double)(n*m-i*j)+dp[i][j+1]*i*(m-j)/(double)(n*m-i*j)+dp[i+1][j+1]*(n-i)*(m-j)/(double)(n*m-i*j)+(n*m)/(double)(n*m-i*j);
           }
        printf("%.4f\n",dp[0][0]);
    }
    return 0;
}
