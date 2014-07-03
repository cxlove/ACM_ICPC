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
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        if(n%(m+1)==0)
            puts("second");
        else
            puts("first");
    }
    return  0;
}