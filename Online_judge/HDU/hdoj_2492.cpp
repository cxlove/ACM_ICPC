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
int n;
int a[N+5];
int s[N+5];
int l[N+5][2],r[N+5][2];
void Update(int x,int val){
    for(int i=x;i<=N;i+=lowbit(i))
        s[i]+=val;
}
int sum(int x){
    int ret=0;
    for(int i=x;i>0;i-=lowbit(i))
        ret+=s[i];
    return ret;
}
int main(){
    //freopen("in.txt","r",stdin);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        mem(s,0);
        for(int i=1;i<=n;i++){
            l[a[i]][0]=sum(a[i]);
            l[a[i]][1]=sum(N)-sum(a[i]-1);
            Update(a[i],1);
        }
        mem(s,0);
        for(int i=n;i>0;i--){
            r[a[i]][0]=sum(a[i]);
            r[a[i]][1]=sum(N)-sum(a[i]-1);
            Update(a[i],1);
        }
        LL ans=0;
        for(int i=1;i<=n;i++){
            ans+=(LL)l[a[i]][0]*r[a[i]][1]+(LL)l[a[i]][1]*r[a[i]][0];
        }
        printf("%I64d\n",ans);

    } return 0;
}