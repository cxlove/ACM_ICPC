#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
int main(){
    LL f[55];
    f[1]=3;f[2]=f[3]=6;
    for(int i=4;i<=50;i++)
        f[i]=f[i-1]+f[i-2]*2;
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%I64d\n",f[n]);
    return 0;
}