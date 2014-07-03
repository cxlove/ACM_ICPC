#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 1<<28
#define M 100005
#define N 50005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
using namespace std;
int  dp[505][505],d[505];
int main(){
    int n,u,v;
    while(scanf("%d",&n)!=EOF){
        mem(dp,0);mem(d,0);
        for(int i=0;i<n;i++){
            scanf("%d%d",&u,&v);
            if(u+v>=n) continue;
            int l=u+1,r=n-v;
            dp[l][r]=min(dp[l][r]+1,n-u-v);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++)
                d[i]=max(d[i],d[j-1]+dp[j][i]);
        }
        printf("%d\n",d[n]);
    }
    return 0;
}
