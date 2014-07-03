#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<stack>
#include<string>
#define LL long long
#define LD long double
#define eps 1e-7
#define inf 1<<30
#define MOD 1000000007
using namespace std;
LL c[10005][105],dp[10005];
void Init(){
c[0][0]=1;
for(int i=1;i<=10000;i++){
c[i][0]=1;
if(i<=101)
c[i][i]=1;
for(int j=1;j<=min(100,i-1);j++)
c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
}
}
int main(){
int sum[105],n,a[105],cas=0;
Init();
while(scanf("%d",&n)!=EOF){
memset(dp,0,sizeof(dp));
sum[0]=0;
for(int i=1;i<=n;i++){
scanf("%d",&a[i]);
sum[i]=sum[i-1]+a[i];
}
dp[0]=1;
for(int i=1;i<=n;i++){
for(int j=sum[i];j>=0;j--){
for(int k=1;k<=a[i];k++){
if(j<k)
continue;
dp[j]=(dp[j]+dp[j-k]*c[j][k])%MOD;
}
}
}
LL ans=0;
for(int i=1;i<=sum[n];i++)
ans=(ans+dp[i])%MOD;
printf("Case %d: %lld\n",++cas,ans);
}
return 0;
}