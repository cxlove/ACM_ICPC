/*
ID:cxlove
PROB:POJ 3370
DATA:2012.4.6
HINT:鸽巢原理
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
int main(){
    int t,m,k;
    scanf("%d",&t);
    while(t--){
        LL sum=0,mmax=0;
        scanf("%d",&m);
        while(m--){
            scanf("%d",&k);
            sum+=k;
            mmax=max(mmax,(LL)k);
        }
        if(mmax>1+sum-mmax)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
