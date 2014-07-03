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
    int n,k,cas=0;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        printf("Case %d: ",++cas);
        if((k==1&&n%2==1)||n<=k)
            puts("first");
        else
            puts("second");
    }
    return 0;
}