#include<iostream>
#include<cstdio>
#include<cstring>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100005
#define lson step<<1
#define rson step<<1|1
#define LL long long 
#define MOD 1000000007
using namespace std;
LL n,t,k,a[10005];
LL powmod(LL a,LL b){
    LL ret=1;
    while(b){
        if(b&1) ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>t>>k;
        for(int i=0;i<n;i++)
            cin>>a[i];
        LL p=powmod(k,t);
        for(int i=0;i<n;i++)
            cout<<(p*a[((i-t)%n+n)%n])%MOD<<(i==n-1?'\n':' ');
    }
    return 0;
}
