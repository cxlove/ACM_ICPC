#include<iostream>  
#include<cstdio>  
#include<map>  
#include<cstring>  
#include<cmath>  
#include<vector>  
#include<stack>
#include<algorithm>  
#include<set>  
#include<string>  
#include<queue>  
#define inf 1600005  
#define M 40  
#define N 10005
#define maxn 2000005  
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
#define vi vector<int> 
using namespace std;
int n,m;
int pre[10000005];
int find(int x){
    return pre[x]=pre[x]==x?pre[x]:find(pre[x]);
}
LL PowMod(LL a,LL b){
    LL ret=1;
    while(b){
        if(b&1) ret=(ret*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ret;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        int cnt=0;
        for(int i=0;i<=n;i++)
            pre[i]=i;
        while(m--){
            int l,r;
            scanf("%d%d",&l,&r);
            l--;
            int ra=find(l),rb=find(r);
            if(ra!=rb){
                cnt++;
                pre[ra]=rb;
            }
        }
        printf("%I64d\n",PowMod(26,n-cnt));
    }
    return 0;
}