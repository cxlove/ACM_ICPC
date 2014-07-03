#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define LL long long
using namespace std;
LL PowMod(LL a,LL b,LL MOD){
    LL ret=1;
    while(b){
        if(b&1) ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
LL fac[100005];
LL Get_Fact(LL p){
    fac[0]=1;
    for(int i=1;i<=p;i++)
        fac[i]=(fac[i-1]*i)%p;
}
LL Lucas(LL n,LL m,LL p){
    LL ret=1;
    while(n&&m){
        LL a=n%p,b=m%p;
        if(a<b) return 0;
        ret=(ret*fac[a]*PowMod(fac[b]*fac[a-b]%p,p-2,p))%p;
        n/=p;
        m/=p;
    }
    return ret;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL n,m,p;
        scanf("%I64d%I64d%I64d",&n,&m,&p);
        Get_Fact(p);
        printf("%I64d\n",Lucas(n+m,m,p));
    }
    return 0;
}

