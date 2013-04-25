#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define lowbit(i) (i&(-i))
using namespace std;
const int N = 100005;
struct Node{
    int left,right;
    int mx;
}L[N<<2];
int n,q,m;
int a[N];
int b[N],c[N],s[N];
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    if(l==r){
        L[step].mx=c[l];
        return ;
    }
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
    L[step].mx=max(L[lson].mx,L[rson].mx);
}
int query(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r)
        return L[step].mx;
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) return query(lson,l,r);
    else if(l>m) return query(rson ,l,r);
    else return max(query(lson,l,m),query(rson,m+1,r));
}
int main(){
    while(scanf("%d",&n)!=EOF){
        if(!n) break ;
        scanf("%d",&q);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        m=0;
        b[0]=-(1<<25);s[0]=0;
        for(int i=1;i<=n;i++){
            if(a[i]==b[m]) c[m]++,s[m]++;
            else b[++m]=a[i],c[m]=1,s[m]=s[m-1]+1;
        }
        bulid(1,1,m);
        while(q--){
            int l,r;
            scanf("%d%d",&l,&r);
            int L=upper_bound(b+1,b+1+m,a[l])-b;
            int R=lower_bound(b+1,b+1+m,a[r])-b-1;
            //cout<<L<<" "<<R<<endl;
            int ans=0;
            if(L<=R) ans=query(1,L,R);
            ans=max(ans,min(r-l+1,s[L-1]-l+1));
            ans=max(ans,min(r-l+1,r-s[R]));
            printf("%d\n",ans);
        }
    }
    return 0;
}
