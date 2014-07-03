#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define lson step<<1
#define rson step<<1|1
#define inf 1<<29
using namespace std;
const int N = 86500;
struct Node{
    int l,r,s;
    bool operator<(const Node n)const{
        return l<n.l;
    }
}a[10000];
struct Seg{
    int left,right,mn,lazy;
}L[N<<2];
int n,s,e;
void push_up(int step){
    L[step].mn=min(L[lson].mn,L[rson].mn);
}
void push_down(int step){
    if(L[step].lazy!=inf){
        L[lson].lazy=min(L[step].lazy,L[lson].lazy);
        L[rson].lazy=min(L[step].lazy,L[rson].lazy);
        L[lson].mn=min(L[step].lazy,L[lson].mn);
        L[rson].mn=min(L[step].lazy,L[rson].mn);
        L[step].lazy=inf;        
    }
}
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].lazy=inf;
    if(l==r){
        if(l==0) L[step].mn=0;
        else L[step].mn=inf;
        return;
    }
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
    push_up(step);
}
int query(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r)
        return L[step].mn;
    int m=(L[step].left+L[step].right)>>1;
    push_down(step);
    if(r<=m) return query(lson,l,r);
    else if(l>m) return query(rson,l,r);
    else return min(query(lson,l,m),query(rson,m+1,r));
}
void update(int step,int l,int r,int val){
    if(L[step].left==l&&L[step].right==r){
        L[step].lazy=min(L[step].lazy,val);
        L[step].mn=min(L[step].mn,val);
        return ;
    }
    push_down(step);
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) update(lson,l,r,val);
    else if(l>m) update(rson,l,r,val);
    else{
        update(lson,l,m,val);
        update(rson,m+1,r,val);
    }
    push_up(step);
}
int main(){
    scanf("%d%d%d",&n,&s,&e);
    int t=s-1;
    s-=t;e-=t;
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&a[i].l,&a[i].r,&a[i].s);
        a[i].l-=t;a[i].r-=t;
    }
    sort(a,a+n);
    bulid(1,s-1,e);
    for(int i=0;i<n;i++){
        int t=query(1,a[i].l-1,e)+a[i].s;
        update(1,a[i].l,a[i].r,t);
    }
    int ans=query(1,e,e);
    printf("%d\n",ans==inf?-1:ans);
    return 0;
}