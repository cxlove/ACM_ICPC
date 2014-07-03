#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MOD 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
int N,M,K;
int cnt,num[1005],pos[1005];
int dp[2][1005][105];
int LCM[1005][1005];
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
int main()
{
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=1000;j++)
        {
            LCM[i][j]=lcm(i,j);
        }
    }
    while(scanf("%d%d%d",&N,&M,&K)!=EOF)
    {
        cnt=0;
        mem(pos,-1);
        for(int i=1;i<=M;i++)
        {
            if(M%i==0)
            {
                num[cnt]=i;
                pos[i]=cnt++;
            }
        }
        mem(dp[0],-1);
        dp[0][0][0]=1;
        for(int i=1;i<=K;i++)
        {
            mem(dp[i&1],-1);
            for(int j=i-1;j<=N;j++)
            {
                for(int k=0;k<cnt;k++)
                {
                    if(dp[(i+1)&1][j][k]==-1) continue;
                    for(int r=0;r<cnt&&j+num[r]<=N;r++)
                    {
                        int l=j+num[r];
                        int s=LCM[num[r]][num[k]];
                        if(s<=M&&pos[s]!=-1)
                        {
                            s=pos[s];
                            if(dp[i&1][l][s]==-1) dp[i&1][l][s]=0;
                            dp[i&1][l][s]+=dp[(i+1)&1][j][k];
                            if(dp[i&1][l][s]>=MOD) dp[i&1][l][s]-=MOD;
                        }
                    }
                }
            }
        }
        printf("%d\n",dp[K&1][N][pos[M]]==-1?0:dp[K&1][N][pos[M]]);
    }
    return 0;
}