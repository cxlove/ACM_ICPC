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
int n,s[N+5];
void Update(int x,int val){
    for(int i=x;i<=n;i+=lowbit(i))
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
    while(scanf("%d",&n)!=EOF&&n){
        mem(s,0);
        for(int i=1;i<=n;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            Update(l,1);
            Update(r+1,-1);
        }
        for(int i=1;i<=n;i++)
            printf("%d%c",sum(i),i==n?'\n':' ');
    } return 0;
}