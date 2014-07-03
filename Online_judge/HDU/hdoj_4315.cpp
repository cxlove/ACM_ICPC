#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n,k,b[1005],a[1005];
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        a[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i]-a[i-1]-1;
        }
        if(k==1){
            puts("Alice");
            continue;
        }
        if(k==2&&n&1){
        }
        else
            b[1]++;
        int ret=0;
        for(int i=n;i>=1;i-=2)
            ret^=b[i];
        if(ret)
            puts("Alice");
        else
            puts("Bob");
    }
    return 0;
}