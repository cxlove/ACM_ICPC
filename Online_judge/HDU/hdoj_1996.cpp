#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
int main(){
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        LL ans=1;
        for(int i=1;i<=n;i++)
            ans=ans*3;
        printf("%I64d\n",ans);
    }
    return 0;
}