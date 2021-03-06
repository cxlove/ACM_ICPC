#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<cmath>
#define LL  long long
#define MOD 29
#define eps 1e-6
#define N 100010
#define zero(a)  fabs(a)<eps
using namespace std;
int PowMod(int a,int b){
    int ret=1;
    while(b){
        if(b&1)
            ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF&&n)
        printf("%d\n",((((PowMod(2,2*n+1)+28)*(PowMod(3,n+1)+28)*(PowMod(22,n+1)+28))%MOD)*PowMod(2,MOD-2)*PowMod(21,MOD-2))%MOD);
    return 0;
}