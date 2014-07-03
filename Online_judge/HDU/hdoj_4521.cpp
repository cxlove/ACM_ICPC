#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#include <cmath>
#define LL long long 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pii pair<int,int>
#define sqr(a) ((double)(a)*(a))
#define pi acos(-1.0)
#define lson step<<1
#define rson step<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int N = 100005;
const int M = 100001;
struct Seg{
    int left,right,mx;
}L[N<<2];
int n,d,a[N],dp[N];
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mx=0;
    if(l==r) return ;
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
}
void update(int step,int pos,int val){
    if(L[step].left==L[step].right){
        L[step].mx=max(L[step].mx,val);
        return ;
    }
    int m=(L[step].left+L[step].right)>>1;
    if(pos<=m) update(lson,pos,val);
    else update(rson,pos,val);
    L[step].mx=max(L[lson].mx,L[rson].mx);
}
int query(int step,int l,int r){
    if(l>r) return 0;
    if(L[step].left==l&&L[step].right==r)
        return L[step].mx;
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) return query(lson,l,r);
    else if(l>m) return query(rson,l,r);
    else return max(query(lson,l,m),query(rson,m+1,r));
}
int main(){
    while(scanf("%d%d",&n,&d)!=EOF){
        bulid(1,1,M);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]++;
        }
        int ans=1;
        for(int i=1;i<=d+1;i++) dp[i]=1;
        for(int i=d+2;i<=n;i++){
            update(1,a[i-d-1],dp[i-d-1]);
            //cout<<a[i-d-1]<<" "<<dp[i-d-1]<<" "<<query(1,1,a[i]-1)<<endl;
            dp[i]=query(1,1,a[i]-1)+1;
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}