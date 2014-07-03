#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#define inf 110000000
#define M 10005
#define N 10005
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define MOD 1000000007
using namespace std;
LL n,a,b,t[100005];
int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        scanf("%I64d%I64d%I64d",&n,&a,&b);
        LL ans=n*b+2*a;
        for(int i=0;i<n;i++) scanf("%I64d",&t[i]);
        for(int i=1;i<n;i++){
            if(t[i]-t[i-1]==1) continue;
            ans+=min(2*a,(t[i]-t[i-1]-1)*b);
        }
        printf("Case #%d: %I64d\n",++cas,ans);
    }
    return 0;
}