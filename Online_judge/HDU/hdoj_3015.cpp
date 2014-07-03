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
#define N 100000
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
struct Node{
    int x,h;
    int r1,r2;
}a[N+5];
bool cmp1(Node a,Node b){return a.x<b.x;}
bool cmp2(Node a,Node b){return a.h<b.h;}
int n;
LL cnt[N+5],s[N+5];
void Update(LL *b,int x,int val){
    for(int i=x;i<=n;i+=lowbit(i))
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
        mem(cnt,0);mem(s,0);
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i].x,&a[i].h);
        }
        sort(a,a+n,cmp1);
        for(int i=0;i<n;i++){
            if(!i||a[i].x!=a[i-1].x) a[i].r1=i+1;
            else a[i].r1=a[i-1].r1;
        }
        sort(a,a+n,cmp2);
        for(int i=0;i<n;i++){
            if(!i||a[i].h!=a[i-1].h) a[i].r2=i+1;
            else a[i].r2=a[i-1].r2;
        }
        LL ans=0,total=0;
        for(int i=n-1;i>=0;i--){
            Update(cnt,a[i].r1,1);
            Update(s,a[i].r1,a[i].r1);
            total+=a[i].r1;
            LL s1=sum(cnt,a[i].r1);
            LL s2=sum(s,a[i].r1);
            ans+=a[i].r2*(s1*a[i].r1-s2+total-s2-(n-i-s1)*a[i].r1);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}