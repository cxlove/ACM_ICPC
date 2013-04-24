#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define lson step<<1
#define rson step<<1|1
using namespace std;
const int N = 100005;
struct Seg_tree{
    int left,right;
    int x,y,cover;
}L[N<<2];
int n,m;
int a[N],b[N];
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].x=-1;
    L[step].y=-1;
    L[step].cover=0;
    if(l==r) return ;
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
}
void push_down(int step){
    if(L[step].cover){
        L[lson].x=L[rson].x=L[step].x;
        L[lson].y=L[rson].y=L[step].y;
        L[lson].cover=L[rson].cover=L[step].cover;
        L[step].cover=0;
    }
}
void update(int step,int l,int r,int x,int y){
    if(L[step].left==l&&L[step].right==r){
        L[step].x=x;
        L[step].y=y;
        L[step].cover=1;
        return ;
    }
    push_down(step);
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) update(lson,l,r,x,y);
    else if(l>m) update(rson,l,r,x,y);
    else{
        update(lson,l,m,x,y);
        update(rson,m+1,r,x,y);
    }
}
void query(int step,int pos){
    if(L[step].left==pos&&pos==L[step].right){
        if(L[step].x==-1) printf("%d\n",b[pos]);
        else{
            printf("%d\n",a[L[step].x+pos-L[step].y]);
        }
        return ;
    }
    push_down(step);
    int m=(L[step].left+L[step].right)>>1;
    if(pos<=m) query(lson,pos);
    else query(rson,pos);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    bulid(1,1,n);
    while(m--){
        int t,x,y,k;
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d%d",&x,&y,&k);
            update(1,y,y+k-1,x,y);
        }
        else{
            scanf("%d",&k);
            query(1,k);
        }
    }
    return 0;
}