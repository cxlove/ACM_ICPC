#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL __int64
LL f[40000];
using namespace std;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF)
        printf("%I64d\n",(LL)(n*n*n+5*n+6)/6);
    return 0;
}