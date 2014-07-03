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
int fib[50];
int main(){
    fib[0]=1;fib[1]=2;
    for(int i=2;i<45;i++)
        fib[i]=fib[i-1]+fib[i-2];
    int n;
    while(scanf("%d",&n)!=EOF&&n){
        int i=0;
        for(i=0;i<45;i++)
            if(fib[i]==n)
                break;
        if(i<45)
            puts("Second win");
        else
            puts("First win");
    }
    return 0;
}