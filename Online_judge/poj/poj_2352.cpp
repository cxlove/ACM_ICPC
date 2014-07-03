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
struct Node{int x,y;bool operator<(const Node n)const {return y!=n.y?y<n.y:x<n.x;}}a[N];
int sum[32005],n=32001;
void Update(int pos,int val){
    while(pos<=n){
        sum[pos]+=val;
        pos+=lowbit(pos);
    }
}
int Sum(int pos){
    int ret=0;
    while(pos>0){
        ret+=sum[pos];
        pos-=lowbit(pos);
    }
    return ret;
}
int ans[32005];
int main(){
    int m;
    while(scanf("%d",&m)!=EOF){
        for(int i=1;i<=m;i++) scanf("%d%d",&a[i].x,&a[i].y);
        sort(a+1,a+1+m);
        mem(ans,0);mem(sum,0);
        for(int i=1;i<=m;i++){
            ans[Sum(a[i].x+1)]++;
            Update(a[i].x+1,1);
        }
        for(int i=0;i<m;i++) printf("%d\n",ans[i]);
    }
    return 0;
}


