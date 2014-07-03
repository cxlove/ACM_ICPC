#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf (1ull<<63)-1
#define N 10005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define eps 1e-9
#define zero(a) fabs(a)<eps
#define LL long long
#define lson (step<<1)
#define rson (step<<1|1)
#define MOD 1000000007
#define mp(a,b) make_pair(a,b)
using namespace std;
int t,cas=0,n,k;
LL a[50],ans;
void dfs(int idx,int cnt,LL num){
    if(ans>num) ans=num;
    if(idx==n||cnt==k) return;
    LL tmp=num;
    for(int i=idx;i<n;i++) tmp&=a[i];
    if(tmp>=ans) return;
    dfs(idx+1,cnt+1,num&a[idx]);
    dfs(idx+1,cnt,num);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%I64d",&a[i]);
        sort(a,a+n);
        ans=inf;
        dfs(0,0,inf);
        printf("Case #%d: %I64d\n",++cas,ans);
    }
    return 0;
}