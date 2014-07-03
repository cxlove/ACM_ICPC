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
LL s[1005];
void Update(int x,int val){
    for(int i=x;i<=m;i+=lowbit(i)) s[i]+=val;
}
LL sum(int x){
    LL ret=0;
    for(int i=x;i>0;i-=lowbit(i)) ret+=s[i];
    return ret;
}
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<k;i++) scanf("%d%d",&a[i].u,&a[i].v);
        sort(a,a+k);
        LL ans=0;
        mem(s,0);
        for(int i=0;i<k;i++){
            ans+=sum(m)-sum(a[i].v);
            Update(a[i].v,1);
        }
        printf("Test case %d: %I64d\n",++cas,ans);
    }
    return 0;
}
