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
    while(scanf("%d%d",&a,&b)!=EOF){
        if(a>b)
            swap(a,b);
        if(a==(int)((sqrt(5.0)+1)*(b-a)/2))
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}