#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf 110000
#define M 10005
#define N 10005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-9
#define zero(a) fabs(a)<eps
#define LL long long
#define MOD 1000000007
using namespace std;
map<LL,LL>dp[45];
map<LL,LL>::iterator it;
LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}
LL lcm(LL a,LL b){
    return a/gcd(a,b)*b;
}
void DP(){
    dp[1][1]=1;
    for(int i=2;i<=40;i++){
        dp[i]=dp[i-1];
        dp[i][i]++;
        for(it=dp[i-1].begin();it!=dp[i-1].end();it++)
            dp[i][lcm(i,it->first)]+=it->second;
    }
}
LL n,m;
int main(){
    DP();
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%I64d%I64d",&n,&m);
        LL ans=0;
        for(it=dp[n].begin();it!=dp[n].end();it++)
            if(it->first>=m) 
                ans+=it->second;
        printf("Case #%d: %I64d\n",++cas,ans);
    }
    return  0;
}


