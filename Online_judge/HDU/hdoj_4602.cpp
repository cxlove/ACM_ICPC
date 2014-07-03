#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007LL;
LL powmod(LL a,LL b ){
    LL ret=1;
    while(b){
        if(b&1) ret=((LL)ret*a)%MOD;
        a=((LL)a*a)%MOD;
        b>>=1;
    }
    return ret;
}
int t,n,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        int c = n - k - 1;
        if(k>n ) puts("0");
        else if(n==k) printf("1\n");
        else if(c==0) printf("2\n");
        else printf("%I64d\n",((2LL*powmod(2LL,c)+(LL)c*powmod(2LL,c-1))%MOD+MOD)%MOD);
    }
    return 0;
}        