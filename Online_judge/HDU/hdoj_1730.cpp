#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 10005
#define LL long long
#define inf 1<<29
#define eps 1e-7
using namespace std;
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int ret=0,p,q;
        while(n--){
            scanf("%d%d",&p,&q);
            ret^=abs(p-q)-1;
        }
        if(ret==0)
            puts("BAD LUCK!");
        else
            puts("I WIN!");
    }
    return 0;
}
