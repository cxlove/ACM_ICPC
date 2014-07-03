#include <cstdio>
#include <cstring>
#include <iostream>
#include<vector>
#include<algorithm>
#define N 110005
#define pb(a) push_back(a)
#define LL long long
#define lson step<<1
#define rson step<<1|1
using namespace std;
struct Node{
    int left,right,mid;
    int num;
}L[N*5];
void Bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    L[step].num=0;
    if(l==r) return;
    Bulid(lson,l,L[step].mid);
    Bulid(rson,L[step].mid+1,r);
}
void update(int step,int pos){
    L[step].num++;
    if(L[step].left==L[step].right) return;
    if(pos<=L[step].mid) update(lson,pos);
    else update(rson,pos);
}
int query(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r) return L[step].num;
    if(r<=L[step].mid) return query(lson,l,r);
    else if(l>L[step].mid) return query(rson,l,r);
    else return query(lson,l,L[step].mid)+query(rson,L[step].mid+1,r);
}
int a[N],b[N];
int main(){
    int n,k;
    while(scanf("%d",&n)!=EOF&&n){
        int pos=1;
        Bulid(1,1,n);
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]);b[a[i]]=i;}
        LL ans=n;
        if(b[1]!=1) ans+=min(b[1]-1,n-b[1]+1);
        pos=b[1];
        update(1,b[1]);
    //    cout<<ans<<endl;
        for(int i=2;i<=n;i++){
            int c,d;
            if(pos<b[i]) {d=query(1,pos+1,b[i]);c=b[i]-pos-d-1;}
            else {d=query(1,b[i],pos-1);c=pos-b[i]-d;}
            ans+=min(c,n-i+1-c);
         //   cout<<pos<<" "<<d<<" "<<c<<" "<<ans<<endl;
            pos=b[i];
            update(1,b[i]);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
