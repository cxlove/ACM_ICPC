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
    int t,n,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int k,ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&k);
            if(i%3==0){
                if(i%2==0) ans^=k;
            }
            else if(i%3==2) ans^=k;
        }
        printf("Case %d: ",++cas);
        if(ans==0) puts("Bob");
        else puts("Alice");
    }
    return 0;
}