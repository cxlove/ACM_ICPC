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
struct Node{int id,num;bool operator<(const Node n)const {return num<n.num;}}a[N];
int sum[N];
int n;
void Update(int pos,int val){
    while(pos<=n){
        sum[pos]+=val;
        pos+=lowbit(pos);
    }
}
LL Sum(int pos){
    LL ret=0;
    while(pos>0){
        ret+=sum[pos];
        pos-=lowbit(pos);
    }
    return ret;
}
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=1;i<=n;i++) scanf("%d",&a[i].num),a[i].id=i;
        sort(a+1,a+1+n);
        LL ans=0;
        mem(sum,0);
        for(int i=1;i<=n;i++){
            Update(a[i].id,1);
            ans+=(LL)(Sum(n)-Sum(a[i].id));
        }
        printf("%lld\n",ans);
    }
    return 0;
}


