#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL __int64
LL f[55];
using namespace std;
int main(){
    f[1]=1;f[2]=2;
    for(int i=3;i<=50;i++)
        f[i]=(f[i-1]+f[i-2]);
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%I64d\n",f[n]);
    return 0;
}