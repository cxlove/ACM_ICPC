#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#define LL long long
#define test puts("OK");
using namespace std;
const int MOD  = 1000000007;
const int N = 20005;
int a[N]={1},n,b[N];
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=0;
        for(int i=1;i<n;i++)
            a[i]=((LL)a[i-1]*n)%MOD;
        b[n-1]=1;
        for(int i=n-2;i>=0;i--)
            b[i]=((LL)b[i+1]*(i+1))%MOD;
        for(int i=0;i<n;i++){
            ans=((LL)ans+(LL)a[i]*b[i])%MOD;
        }
        if(ans<0) while(true);
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}