#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define LL __int64
#define MOD 10007
using namespace std;
bool flag[10005]={0};
int prime[10005],cnt=0;
int a,b,fac[10005];
LL num[10005];
LL PowMod(int a,int b){
    LL ret=1;
    while(b){
        if(b&1)
            ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
void Prime(){
    for(int i=2;i<=1000;i++){
        if(flag[i])
            continue;
        prime[cnt++]=i;
        for(int j=2;j*i<=1000;j++)
            flag[i*j]=true;
    }
}
int idx;
LL niyuan=PowMod(4,MOD-2);
LL split(int a,int b){
    LL ret=1;
    for(int i=0;i<cnt&&prime[i]<a;i++){
        if(a%prime[i]==0){
            fac[idx]=prime[i];
            num[idx]=0;
            while(a%prime[i]==0){
                num[idx]++;
                a/=prime[i];
            }
            num[idx]=num[idx]*b;
            LL m=num[idx]+1,n=num[idx]+2;
            ret=(ret*(((((m*m)%MOD*n)%MOD*n)%MOD)*niyuan)%MOD)%MOD;
            idx++;
        }
    }
    if(a>1){
        num[idx]=b;
        LL m=num[idx]+1,n=num[idx]+2;
        ret=(ret*(((((m*m)%MOD*n)%MOD*n)%MOD)*niyuan)%MOD)%MOD;
        fac[idx++]=a;
    }
    return ret;
}
int main(){
    Prime();
    int cas=0;    
    while(scanf("%d%d",&a,&b)!=EOF){
        printf("Case %d: ",++cas);
        if(a==1){
            printf("1\n");
            continue;
        }
        idx=0;    
        printf("%I64d\n",split(a,b));
    }
    return 0;
}