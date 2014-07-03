#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
int main(){
    LL f[55]={0};
    f[1]=1;f[2]=2;
    for(int i=3;i<=50;i++)
        f[i]=f[i-1]+f[i-2];
    int t,a,b;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&a,&b);
        printf("%I64d\n",f[b-a]);
    }
    return 0;
}