#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 30
#define inf 1<<29
#define MOD 2007
#define LL long long
using namespace std;
int mason[8]={3,7,31,127,8191,131071,524287,2147483647};
int cnt[8]={2,3,5,7,13,17,19,31};
int dp[1<<8];
int change(int num){
    int ret=0;
    for(int i=0;i<8;i++){
        if(num%mason[i]==0){
            num/=mason[i];
            if(num%mason[i]==0)  return 0;
            ret|=1<<i;
        }
    }
    if(num!=1)  return 0;
    return ret;
}
int clac(int state){
    int sum=0;
    for(int i=0;i<8;i++)
        if(state&(1<<i))
           sum+=cnt[i];
    return sum;
}
int main(){
    int n,a[100];
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            a[i]=change(a[i]);
            if(!a[i])  i--,n--;
        }
        if(n==0){
            puts("NO");
            continue;
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<(1<<8);j++)
                if(!(j&a[i]))
                    dp[j|a[i]]|=dp[j];
        }
        int ans=0;
        for(int i=0;i<(1<<8);i++)
            if(dp[i])
                ans=max(ans,clac(i));
        printf("%d\n",ans);
    }
    return 0;
}





