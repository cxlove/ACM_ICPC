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
    int a,b;
    while(scanf("%d",&a)!=EOF&&a)
        if(a&1)
            puts("ailyanlu");
        else
            puts("8600");
    return 0;
}