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
#define N 20000
#define maxn 300005  
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
using namespace std;  
struct Node{int v,x;bool operator<(const Node n)const{return v<n.v;}}a[N+5];
LL cnt[N+5],s[N+5];
int n;
void Update(LL *b,int x,LL val){
    for(int i=x;i<=N;i+=lowbit(i))
        b[i]+=val;
}
LL sum(LL *b,int x){
    LL ret=0;
    for(int i=x;i>0;i-=lowbit(i))
        ret+=b[i];
    return ret;
}
int main(){
    //freopen("in.txt","r",stdin);

    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d%d",&a[i].v,&a[i].x);
        sort(a,a+n);
        mem(cnt,0);
        mem(s,0);
        LL ans=0,total=0;
        for(int i=0;i<n;i++){
            Update(cnt,a[i].x,1);
            Update(s,a[i].x,a[i].x);
            total+=a[i].x;
            LL s1=sum(cnt,a[i].x);
            LL s2=sum(s,a[i].x);
            ans+=a[i].v*(s1*a[i].x-s2-a[i].x*(i+1-s1)+total-s2);
        }
        printf("%lld\n",ans);
    }
    return 0;
}