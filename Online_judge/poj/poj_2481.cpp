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
#define N 100001  
#define maxn 300005  
#define eps 1e-12
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
#define lowbit(x) ((-(x))&(x))
#pragma comment(linker, "/STACK:1024000000,1024000000")  
using namespace std;  
struct Node{int id,l,r;bool operator<(const Node n)const{return l!=n.l?l<n.l:r>n.r;}}a[N];
int s[N+5];
int ans[N];
void Update(int x,int val){
    for(int i=x;i<=N;i+=lowbit(i)) s[i]+=val;
}
int sum(int x){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i)) ret+=s[i];
    return ret;
}
int main(){
    int n;
    //freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].l,&a[i].r);
            a[i].l++;a[i].r++;
            a[i].id=i;
        }
        sort(a,a+n);
        mem(s,0);
        for(int i=0;i<n;i++){
            if(i&&a[i].l==a[i-1].l&&a[i].r==a[i-1].r) ans[a[i].id]=ans[a[i-1].id];
            else ans[a[i].id]=sum(N)-sum(a[i].r-1);
            Update(a[i].r,1);
        }
        for(int i=0;i<n-1;i++) printf("%d ",ans[i]);printf("%d\n",ans[n-1]);
    }
    return 0;
}

