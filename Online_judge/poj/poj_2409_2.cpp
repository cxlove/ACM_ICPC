#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 100005
#define inf 1<<29
#define MOD 2007
#define LL long long
using namespace std;
LL gcd(LL a,LL b){
    return b==0?a:gcd(b,a%b);
}
LL Pow(LL a,int b){
    LL ret=1;
    while(b){
        if(b&1)
           ret=ret*a;
        a=a*a;
        b>>=1;
    }
    return ret;
}
LL Polya(int n,int m){
    LL sum=0;
    for(int i=1;i<=n;i++)
        sum+=Pow(m,gcd(n,i));
    if(n&1)
        sum+=n*Pow(m,n/2+1);
    else
        sum+=n/2*Pow(m,n/2)+n/2*Pow(m,n/2+1);
    return sum/2/n;
}
int n,m;
int main(){
    while(scanf("%d%d",&m,&n)!=EOF&&n+m){
        printf("%lld\n",Polya(n,m));
    }
    return 0;
}
