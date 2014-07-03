#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
LL dp[20][3]={0},n;
void DP(){
    dp[0][0]=1;
    for(int i=1;i<20;i++){
        dp[i][0]=dp[i-1][0]*10-dp[i-1][1];   //没有49
        dp[i][1]=dp[i-1][0];                 //没有49，最高位为9
        dp[i][2]=dp[i-1][1]+dp[i-1][2]*10;   //有49
    }
}
int main(){
    DP();
    int t,a[20];
    char str[25];
    scanf("%d",&t);
    while(t--){
        scanf("%I64d",&n);
        n++;
        int len=0;
        memset(a,0,sizeof(a));
        while(n){
            a[++len]=n%10;
            n/=10;
        }
        LL ans=0;
        bool flag=false;
        for(int i=len;i>=1;i--){
            ans+=dp[i-1][2]*a[i];
            if(flag)
                ans+=dp[i-1][0]*a[i];
            if(!flag&&a[i]>4) ans+=dp[i-1][1];
            if(a[i+1]==4&&a[i]==9) flag=true;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}