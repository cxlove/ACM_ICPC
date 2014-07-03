/*
ID:cxlove
PROB:Bone Collector 
DATA:2012.2.29
HINT:01背包
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
    int t,n,w,a[1005],b[1005],dp[1005];
    cin>>t;
    while(t--){
        cin>>n>>w;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            for(int j=w;j>=b[i];j--)
                dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
        cout<<dp[w]<<endl;
    }
    return 0;
}
/*
1
5 10
1 2 3 4 5
5 4 3 2 1
*/