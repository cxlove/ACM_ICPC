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
#define inf 1600005  
#define M 40  
#define N 200005  
#define maxn 300005  
#define eps 1e-7
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL unsigned long long  
#define MOD 2012  
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;  
int dp[1000005];
int main(){
dp[0]=1;dp[1]=2;
for(int i=3;i<=1000000;i++) dp[i]=(dp[i-1]+dp[i-2])%3;
    int n;
    while(cin>>n){
        if(dp[n]) puts("no");
        else puts("yes");
    }
    return 0;
}


