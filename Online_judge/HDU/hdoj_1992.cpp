#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
LL f[1001][6];
int main(){
    int t,n,cas=0;
    scanf("%d",&t);
    f[1][0]=f[1][1]=f[1][2]=f[1][3]=f[1][5]=1;
    f[1][4]=0;
    for(int i=2;i<=1000;i++){
        f[i][0]=f[i-1][5];
        f[i][1]=f[i-1][5]+f[i-1][3];
        f[i][2]=f[i-1][4]+f[i-1][5];
        f[i][3]=f[i-1][5]+f[i-1][1];
        f[i][4]=f[i-1][2];
        f[i][5]=f[i-1][0]+f[i-1][1]+f[i-1][2]+f[i-1][3]+f[i-1][5];
    }
    while(t--){
        scanf("%d",&n);
        printf("%d %d\n",++cas,f[n][5]);
    }
    return 0;
}
    