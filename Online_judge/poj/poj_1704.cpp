#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
int main(){
    int t,n,a[1005];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        a[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n+1);
        int ret=0;
        for(int i=n;i>0;i-=2)
            ret^=a[i]-a[i-1]-1;
        puts(ret?"Georgia will win":"Bob will win");
    }
    return 0;
}


