#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 55
#define inf 1<<29
//#define MOD 9973
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
LL dp[21][3],n; 
int len,bit[21];
//dp[i][0]表示长度为i，包括49的个数
//dp[i][1]表示长度为i，没有49但是开头为9的个数
//dp[i][2]表示长度为i，没有49
void Init(){
    memset(dp,0,sizeof(dp));
    dp[0][2]=1;
    for(int i=1;i<20;i++){
        dp[i][0]=(LL)dp[i-1][0]*10+dp[i-1][1];
        dp[i][1]=dp[i-1][2];
        dp[i][2]=(LL)dp[i-1][2]*10-dp[i-1][1];
    }
}
int main(){
    Init();
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d",&n);
        len=0;
        n++;
        while(n){
            bit[++len]=n%10;
            n/=10;
        }
        bit[len+1]=0;
        LL ans=0;
        bool flag=false;
        for(int i=len;i;i--){
            ans+=(LL)dp[i-1][0]*bit[i];
            if(flag)
                ans+=(LL)dp[i-1][2]*bit[i];
            if(!flag&&bit[i]>4)
                ans+=dp[i-1][1];
            if(bit[i]==9&&bit[i+1]==4)
                flag=true;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}