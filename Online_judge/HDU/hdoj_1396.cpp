#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL __int64
LL f[510];
using namespace std;
int main(){
    f[1]=1;f[2]=5;f[3]=13;
    for(int i=4;i<=500;i++){
        f[i]=f[i-1]+(i*i+3*i-2)/2;
        for(int j=i-3;j>=1;j-=2)
            f[i]+=j;
    }
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%d\n",f[n]);
    return 0;
}