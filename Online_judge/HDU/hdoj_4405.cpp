#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<set>
#include<cmath>
#include<vector>
#include<map>
#include<algorithm>
#define N 210005
#define inf 100000000
#define MOD 100000007
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
#define Key_value ch[ch[root][1]][0]
#define _match(a,b) ((a)==(b))
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
double dp[200005];
int n,m;
int pos[200005];
double DP(int p){
    if(p>=n) return 0;
    if(dp[p]>0) return dp[p];
    double ret=0;
    for(int i=1;i<=6;i++){
        int j=p+i;
        while(pos[j]) j=pos[j];
        ret+=DP(j)+1;
    }
    return dp[p]=ret/6.0;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        if(n==0&&m==0) break;
        mem(pos,0);
        for(int i=0;i<m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            pos[x]=y;
        }
        for(int i=0;i<n;i++) dp[i]=-1;
        printf("%.4f\n",DP(0));
    }
    return 0;
}