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
int a,b,t,dp[25][10005];
int main(){
    while(cin>>a>>b>>t){
        t/=15;
        b+=t/2;
        mem(dp,0);dp[0][a]=1;
        int up=a+(t+1)/2*3;
        for(int i=1;i<=(t+1)/2;i++){
            for(int j=up;j>=a;j--){
                if(j>=1)dp[i][j]+=dp[i-1][j-1];
                if(j>=2)dp[i][j]+=dp[i-1][j-2];
                if(j>=3)dp[i][j]+=dp[i-1][j-3];
            }
        }
        LL ans=0;
        for(int i=a;i<=up;i++)
            if(i>b)
                ans+=dp[(t+1)/2][i];
        cout<<ans<<endl;
    }
    return 0;
}