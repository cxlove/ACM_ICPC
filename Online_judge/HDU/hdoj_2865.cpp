/*
ID:cxlove
PROB:poj 2888 Magic Bracelet
DATA:2012.4.11
HINT:有限制的Polya，矩阵快速幂乘，取模逆元，各种经典
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define LL long long
#define N 1000000000
#define MOD 1000000007
using namespace std;
LL n,m,k;
bool flag[40000]={0};
int prime[40000],cnt=0;
void Prime(){
    for(int i=2;i<=sqrt(N+1.0);i++){
        if(flag[i]) continue;
        prime[cnt++]=i;
        for(int j=2;j*i<=sqrt(N+1.0);j++)
            flag[i*j]=true;
    }
}
int eular(int m){
    int sum=1;
    for(int i=0;i<cnt&&prime[i]<=m;i++)
        if(m%prime[i]==0){
            sum*=(prime[i]-1);
            m/=prime[i];
            while(m%prime[i]==0){
                sum*=prime[i];
                m/=prime[i];
            }
        }
        if(m>1)
            sum*=(m-1);
        return sum%MOD;
}
LL Pow(LL a,LL b){
    LL ret=1;
    a=a%MOD;
    while(b){
        if(b&1)
            ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
LL slove(LL p,LL k){
    LL ans=Pow(p-1,k);
    if(k&1)
        ans=(ans+MOD-(p-1))%MOD;
    else
        ans=(ans+p-1)%MOD;
    return ans;

}
int polya(){
    int sum=0;
    int i=1;
    for(;i*i<n;i++)
        if(n%i==0)
            sum=(sum+eular(i)*slove(m-1,n/i)+eular(n/i)*slove(m-1,i))%MOD;
    if(i*i==n)
        sum=(sum+eular(i)*slove(m-1,i))%MOD;
    return (sum*Pow(n%MOD,MOD-2))%MOD;
}
int main(){    
    Prime();
    while(scanf("%I64d%I64d",&n,&m)!=EOF)
        printf("%d\n",(m*polya())%MOD);
    return 0;
}