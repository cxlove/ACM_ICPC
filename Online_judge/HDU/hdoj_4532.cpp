#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define MOD 1000000007
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int mul(int a,int b){return (LL)a*b%MOD;}
int mul(int a,int b,int c,int d){return mul(mul(mul(a,b),c),d);}
const int N=500;
int fac,sum,dp[50][N];
int c[N][N];
int main(){
    for(int i=0;i<N;i++){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
    }
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        int n,a;
        fac=1;sum=0;
        scanf("%d",&n);
        mem(dp,0);dp[0][0]=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a);
            for(int j=1;j<=a;j++)
                fac=mul(fac,j);
            //上一轮有j个位置不合法
            for(int j=0;j<=sum;j++){
                //这一轮分为k组
                for(int k=1;k<=a;k++){
                    //上一轮r个不合法的位置解除
                    for(int r=0;r<=j&&r<=k;r++){
                        int now=j+(a-k)-r;
                        dp[i][now]=((LL)dp[i][now]+mul(dp[i-1][j],c[a-1][k-1],c[j][r],c[sum+1-j][k-r]))%MOD;
                    }
                }
            }
            sum+=a;
        }
        printf("Case %d: %d\n",++cas,mul(dp[n][0],fac));
    }
}