/*
ID:cxlove
PROB:Girl Love Value 
DATA:2012.3.7
HINT:DP+贪心
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node{
    int l,b;
}a[1005];
int dp[1005][1005];
bool cmp(Node n1,Node n2){
    //return n1.b!=n2.b?n1.b>n2.b:n1.l>n2.l;
    return n1.b>n2.b;
}
int main(){
    int n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i].l);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i].b);
        sort(a+1,a+1+n,cmp);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i&&j<=k;j++)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+a[i].l-(j-1)*a[i].b);
        printf("%d\n",dp[n][k]);
    }
    return 0;
}