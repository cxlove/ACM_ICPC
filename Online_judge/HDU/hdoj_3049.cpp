#include<iostream>
#include<cstdio>
#include<cstring>
#define LL __int64
#define MOD 1000003
using namespace std;
LL PowMod(LL a,LL b){
    LL ret=1;
    while(b){
        if(b&1)
            ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
int main(){
    int t,cas=0,n,a[40005];
    scanf("%d",&t);
    while(t--){
        int i;
        scanf("%d",&n);
        for( i=0;i<n;i++)
            scanf("%d",&a[i]);
        LL ans=0;
        for(i=0;i<n;i++)
            ans+=PowMod(2,a[i]);
        ans=(ans*PowMod(n,MOD-2))%MOD;
        printf("Case %d:%I64d\n",++cas,ans);
    }
    return 0;
}
