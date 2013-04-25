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
#define inf 0x3f3f3f3f  
#define M 40    
#define N 200005  
#define maxn 2000005    
#define eps 1e-7  
#define zero(a) fabs(a)<eps    
#define Min(a,b) ((a)<(b)?(a):(b))    
#define Max(a,b) ((a)>(b)?(a):(b))    
#define pb(a) push_back(a)    
#define mp(a,b) make_pair(a,b)    
#define mem(a,b) memset(a,b,sizeof(a))    
#define LL long long    
#define MOD 1000000007  
#define lson step<<1  
#define rson step<<1|1  
#define sqr(a) ((a)*(a))    
#define Key_value ch[ch[root][1]][0]    
#define test puts("OK");    
#define pi acos(-1.0)  
#define lowbit(x) ((x)&(-(x)))  
#pragma comment(linker, "/STACK:1024000000,1024000000")    
#define vi vector<int>   
using namespace std;  
LL dp[2][N];
int a[N],n;
map<pair<int,int>,int>mm;
LL dfs(int k,int x){
    if(x!=1&&dp[k][x]!=-1)
        return dp[k][x];
    if(mm.find(mp(k,x))!=mm.end())
        return  dp[k][x]=-2;
    mm[mp(k,x)]=1;
    if(k){
        if(x-a[x]<=0)
            dp[k][x]=a[x];
        else{
            LL m=dfs(0,x-a[x]);
            if(m==-2) dp[k][x]=-2;
            else dp[k][x]=m+a[x];
        }
    }
    else{
        if(x+a[x]>n)
            dp[k][x]=a[x];
        else{
            LL m=dfs(1,x+a[x]);
            if(m==-2) dp[k][x]=-2;
            else dp[k][x]=m+a[x];
        }
    }
    return dp[k][x];
}
int main(){
    mem(dp,-1);
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<n;i++){
        mm.clear();a[1]=i;
        LL ans=dfs(1,i+1);
        if(ans==-2) printf("-1\n");
        else printf("%I64d\n",ans+i);
    }
    return 0;
}