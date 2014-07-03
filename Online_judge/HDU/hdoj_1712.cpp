/*
ID:cxlove
PROB:ACboy needs your help 
DATA:2012.3.1
HINT:分组背包
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[105],dp[105];
int main(){
    int n,m;
    while(cin>>n>>m,n+m!=0){
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++)
                cin>>a[j];
            for(int j=m;j>=0;j--)
                for(int k=1;k<=j;k++)
                    dp[j]=max(dp[j],dp[j-k]+a[k]);
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}
/*
2 2
1 2
1 3
2 2
2 1
2 1
2 3
3 2 1
3 2 1
*/


