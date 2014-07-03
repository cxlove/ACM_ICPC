#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MOD 1000000007 
#define LL long long
using namespace std;
int prime[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,
    47,53,59,61,67,71,73,79,83,89,97,101},cnt=25;
LL n,m;
LL eular(LL num){
    LL ret=1;
    for(int i=0;i<cnt&&prime[i]<=num;i++)
        if(num%prime[i]==0){
            ret*=(prime[i]-1);
            num/=prime[i];
            while(num%prime[i]==0){
                num/=prime[i];
                ret*=prime[i];
            }
        }
        if(num>1)
            ret*=(num-1);
        return ret%MOD;
}
LL Pow(LL a,LL b){
    LL ret=1;
    while(b){
        if(b&1)
            ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
LL Polya(){
    LL sum=0,i;
    for(i=1;i*i<n;i++){
        if(n%i==0){
            sum=(sum+eular(i)*Pow(m,n/i))%MOD;
            sum=(sum+eular(n/i)*Pow(m,i))%MOD;
        }
    }
    if(i*i==n)
        sum=(sum+eular(i)*Pow(m,i))%MOD;
    if(n&1)
        sum=(sum+n*Pow(m,n/2+1))%MOD;
    else
        sum=(sum+n/2*(Pow(m,n/2)+Pow(m,n/2+1)))%MOD;
    return (sum*Pow(2*n,MOD-2))%MOD;
}
int main(){
    LL t,cas=0;
    scanf("%I64d",&t);
    while(t--){
        scanf("%I64d%I64d",&m,&n);
        printf("Case #%I64d: %I64d\n",++cas,Polya());
    }
    return 0;
}
