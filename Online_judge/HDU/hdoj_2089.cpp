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
int dp[10][3];
//dp[i][0],表示不存在不吉利数字
//dp[i][1],表示不存在不吉利数字，且最高位为2
//dp[i][2],表示存在不吉利数字
void Init(){
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=6;i++){
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1];
        dp[i][1]=dp[i-1][0];
        dp[i][2]=dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];
    }
}
int slove(int n){
    int len=0,bit[10];
    int tmp=n;
    while(n){
        bit[++len]=n%10;
        n/=10;
    }
    bit[len+1]=0;
    int ans=0;
    bool flag=false;
    for(int i=len;i;i--){
        ans+=dp[i-1][2]*bit[i];
        if(flag)
            ans+=dp[i-1][0]*bit[i];
        if(!flag&&bit[i]>4)
            ans+=dp[i-1][0];
        if(!flag&&bit[i+1]==6&&bit[i]>2)
            ans+=dp[i][1];
        if(!flag&&bit[i]>6)
            ans+=dp[i-1][1];
        if(bit[i]==4||(bit[i+1]==6&&bit[i]==2))
            flag=true;
    }
//    cout<<ans<<endl;
    return tmp-ans;
}
int main(){
    int l,r;
//    freopen("d.out","r",stdin);
//    freopen("2.out","w",stdout);
    Init();
    while(scanf("%d%d",&l,&r)!=EOF&&l+r)
        printf("%d\n",slove(r+1)-slove(l));
    return 0;
}
/*
6965 24465
5706 28146
3284 16828
*/