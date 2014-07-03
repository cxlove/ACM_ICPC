#include<iostream>
#include<cstdio>
#include<cstring>
#define LL __int64
using namespace std;
LL c[40]={1};
void Init(){
    for(int i=1;i<=35;i++){
        c[i]=0;
        for(int j=0;j<=i;j++)
            c[i]+=c[j]*c[i-j-1];
    }
}
int main(){
    Init();
    int n,cas=1;
    while(scanf("%d",&n)!=EOF&&n!=-1)
        printf("%d %d %I64d\n",cas++,n,c[n]*2);
    return 0;
}
