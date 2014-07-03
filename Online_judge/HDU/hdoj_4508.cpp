#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100005
#define lson step<<1
#define rson step<<1|1
#define LL long long 
#define MOD 1000000007
using namespace std;
int dp[100005];
int n,m,a[100],b[100],t;
int main(){
    while( cin>>n){
        for(int i=0;i<n;i++) cin>>a[i]>>b[i];
        cin>>m;
        mem(dp,0);
        for(int i=0;i<n;i++){
            for(int j=b[i];j<=m;j++)
                dp[j]=max(dp[j],dp[j-b[i]]+a[i]);
        }
        cout<<(*max_element(dp,dp+m+1))<<endl;
    }
    return 0;
}