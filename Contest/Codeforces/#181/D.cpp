#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#define LL long long
#define mp(a,b) make_pair(a,b)
using namespace std;
const int MOD = 7340033;
int dp[40][1005];
int gao(int n,int m){
    int cnt=0;
    while(n>1&&n%2) n/=2,cnt++;
    return dp[cnt][m];
}
void Init(){
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<40;i++){
        int d[1005];
        dp[i][0]=1;
        memset(d,0,sizeof(d));
        for(int j=0;j<=1000;j++)
            for(int k=0;k<=1000-j;k++)
                d[j+k]=((LL)d[j+k]+(LL)dp[i-1][j]*dp[i-1][k])%MOD;
        for(int j=0;j<=1000;j++)
            for(int k=0;k<=1000-j;k++)
                dp[i][j+k+1]=((LL)dp[i][j+k+1]+(LL)d[j]*d[k])%MOD;
    }
}
int main(){
    int t;
    //freopen("input.txt","r",stdin);
    Init();
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        printf("%d\n",gao(n,m));
    }
    return 0;
}