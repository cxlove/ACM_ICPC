#include<cstdio>
#include<cstring>
#include<ctime>
#define N 16
int n,s[1<<N]={0},t;
double p[N][N];
double dp[1<<N]={0};
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    for(int i=1;i<(1<<N);i++)
        s[i]=s[i>>1]+(i&1);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%lf",&p[i][j]);
        memset(dp,0,sizeof(dp));
        dp[(1<<n)-1]=1;
        for(int i=(1<<n)-1;i>0;i--){
            for(int j=0;j<n;j++){
                if(!(i&(1<<j))) continue;
                for(int k=0;k<n;k++){
                    if(!(i&(1<<k))||j==k) continue;
                    int c=s[i];
                    c=c*(c-1)/2;
                    dp[i-(1<<k)]+=dp[i]*p[j][k]*1.0/c;
                }
            }
        }
        for(int i=0;i<n;i++)
            printf("%.6f%c",dp[1<<i],i==n-1?'\n':' ');
    }
    //printf("%.6lf",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}