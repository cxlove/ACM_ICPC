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
#define N 500005  
#define maxn 300005  
#define eps 1e-7
#define zero(a) fabs(a)<eps  
#define Min(a,b) ((a)<(b)?(a):(b))  
#define Max(a,b) ((a)>(b)?(a):(b))  
#define pb(a) push_back(a)  
#define mp(a,b) make_pair(a,b)  
#define mem(a,b) memset(a,b,sizeof(a))  
#define LL long long  
#define MOD 2012  
#define lson step<<1
#define rson step<<1|1
#define sqr(a) ((a)*(a))  
#define Key_value ch[ch[root][1]][0]  
#define test puts("OK");  
#define pi acos(-1.0)
#define lowbit(x) ((x)&(-(x)))
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std; 
struct Node{int u,v;bool operator <(const Node n)const {return u!=n.u?u<n.u:v<n.v;}}a[1000005];
int n,m,k;
int s[105][105];
void Update(int x,int y,int val){
    for(int i=x;i<=100;i+=lowbit(i))
        for(int j=y;j<=100;j+=lowbit(j))
            s[i][j]+=val;
}
int sum(int x,int y){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j>0;j-=lowbit(j))
            ret+=s[i][j];
    return ret;
}
int main(){
    int x,y;
    while(scanf("%d",&k)!=EOF&&k){
        mem(s,0);
        scanf("%d%d",&n,&m);
        for(int i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            Update(x,y,1);
        }
        scanf("%d%d",&x,&y);
        int ans=0;
        for(int i=x;i<=n;i++)
            for(int j=y;j<=m;j++){
                ans=max(ans,sum(i,j)+sum(i-x,j-y)-sum(i,j-y)-sum(i-x,j));
            }
        printf("%d\n",ans);
    }
    return 0;
}
