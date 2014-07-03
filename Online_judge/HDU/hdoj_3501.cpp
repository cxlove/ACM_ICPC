#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 100005
#define inf  1<<30
#define MOD 1000000007
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
bool flag[40000];
int cnt=0,prime[40000];
void Prime(){
    for(int i=2;i<=sqrt(1000000001.0);i++){
        if(flag[i])
            continue;
        prime[cnt++]=i;
        for(int j=2;j*i<=sqrt(1000000001.0);j++)
            flag[i*j]=true;
    }
}
LL n,temp;
int fac[10005],tot;
LL get_sum(int k){
    LL a=k,b=k+1;
    if(!(a&1))
        a/=2;
    else
        b/=2;
    return (a*b)%MOD;
}
LL ans=0;
void dfs(LL num,int pre,int idx,int m){
    if(pre==m){
        LL tmp=(num*get_sum((temp-1)/num))%MOD;
        if(m&1)
            ans=(ans+tmp)%MOD;
        else
            ans=(ans-tmp+MOD)%MOD;
        return ;
    }
    if(idx>=tot)
        return ;
    dfs(num,pre,idx+1,m);
    dfs(num*fac[idx],pre+1,idx+1,m);
}
int main(){
    Prime();
    while(scanf("%lld",&n)!=EOF&&n){
        tot=0;
        temp=n;
        for(int i=0;i<cnt&&prime[i]<=n;i++)
            if(n%prime[i]==0){
                fac[tot++]=prime[i];
                while(n%prime[i]==0)
                    n/=prime[i];
            }
        if(n>1)
            fac[tot++]=n;
        ans=0;
        for(int i=1;i<=tot;i++)
            dfs(1,0,0,i);
        printf("%lld\n",ans);
    }
    return 0;
}