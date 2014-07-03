#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#define LL long long
#define N 1000000
#define inf 1<<20
using namespace std;
int main(){
    int n,p,q;
    while(scanf("%d%d%d",&n,&p,&q)!=EOF)
        if(((n-1)%(p+q))<p)
            printf("LOST\n");
        else
            printf("WIN\n");
    return 0;
}