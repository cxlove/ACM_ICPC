#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#define lowbit(x) ((x)&(-(x)))
#define lson (step<<1)
#define rson (step<<1|1)
using namespace std;
const int N = 200005;
struct Query{
    int k,x,y;
    void init(){
        char str[10];
        scanf("%s%d%d",str,&x,&y);
        if(str[0]=='a') k=0;
        else if(str[0]=='f') k=2;
        else k=1;
    }
}ask[N];
struct Seg_tree{
    int left,right,mx;
}L[N<<2];
int m,q,X[N];
set<int>s[N];
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mx=-1;
    if(l==r) return ;
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
}
inline void push_up(int step){
    L[step].mx=max(L[lson].mx,L[rson].mx);
}
void update(int step,int pos){
    if(L[step].left==L[step].right){
        L[step].mx=((int)s[pos].size()==0)?-1:(*(--s[pos].end()));
        return ;
    }
    int m=(L[step].left+L[step].right)>>1;
    if(pos<=m) update(lson,pos);
    else update(rson,pos);
    push_up(step);
}
int query(int step,int l,int r,int y){
    if(l>r) return -1;
    if(L[step].mx<=y) return -1;
    if(L[step].left==L[step].right) return L[step].left;
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) return query(lson,l,r,y);
    else if(l>m) return query(rson,l,r,y);
    else{
        int t=query(lson,l,m,y);
        if(t>=0) return t;
        return query(rson,m+1,r,y); 
    }
}
int main(){
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        ask[i].init();    
        X[i]=ask[i].x;
    }
    sort(X,X+q);
    m=unique(X,X+q)-X;
    bulid(1,1,m);
    for(int i=0;i<q;i++){
        int k=ask[i].k,x=lower_bound(X,X+m,ask[i].x)-X+1,y=ask[i].y;
        if(k==0){
            s[x].insert(y);
            update(1,x);
        }
        else if(k==1){
            s[x].erase(s[x].find(y));
            update(1,x);
        }
        else{
            int pos=query(1,x+1,m,y);
            if(pos==-1) printf("-1\n");
            else{
                printf("%d %d\n",X[pos-1],*s[pos].upper_bound(y));
            }
        }
    }
    return 0;
}
