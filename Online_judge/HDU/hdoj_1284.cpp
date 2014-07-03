#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL __int64
LL f[40000];
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int t=n/3;
        LL ans=0;
        for(int i=0;i<=t;i++){
            ans+=(n-3*i)/2+1;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}