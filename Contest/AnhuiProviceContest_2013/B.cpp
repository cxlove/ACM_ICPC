#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define lson step<<1
#define rson step<<1|1
#define inf 1<<20
using namespace std;
const int N = 100005;
struct Seg_tree{
    int left,right;
    int cover,len,lazy;
    int left_num,left_cnt;
    int right_num,right_cnt;
    int dist(){return right-left+1;}
}L[N<<2];
void push_up(int step){
    if(L[lson].cover!=-inf&&L[rson].cover!=-inf&&L[lson].cover==L[rson].cover)
        L[step].cover=L[lson].cover;
    else L[step].cover=-inf;
    L[step].left_num=L[lson].left_num;
    L[step].left_cnt=L[lson].left_cnt;
    L[step].right_num=L[rson].right_num;
    L[step].right_cnt=L[rson].right_cnt;
    if(L[lson].dist()==L[lson].left_cnt&&L[rson].left_num==L[lson].left_num)
        L[step].left_cnt+=L[rson].left_cnt;
    if(L[rson].dist()==L[rson].right_cnt&&L[lson].right_num==L[rson].right_num)
        L[step].right_cnt+=L[lson].right_cnt;
    L[step].len=max(L[lson].len,L[rson].len);
    if(L[lson].right_num==L[rson].left_num)
        L[step].len=max(L[step].len,L[rson].left_cnt+L[lson].right_cnt);
}
void update(int step,int l,int r,int d);
void push_down(int step){
    int l=L[step].left,r=L[step].right,m=(l+r)>>1;
    if(L[step].lazy){
        update(lson,l,m,L[step].lazy);
        update(rson,m+1,r,L[step].lazy);
        L[step].lazy=0;
    }
}
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].lazy=0;
    if(l==r){
        L[step].cover=0;
        L[step].len=1;
        L[step].left_num=0;
        L[step].left_cnt=1;
        L[step].right_num=0;
        L[step].right_cnt=1;
        return ;
    }
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
    push_up(step);
}
void update(int step,int l,int r,int d){
    if(l>r) return ;
    if(L[step].left==l&&L[step].right==r){
        L[step].lazy+=d;
        if(L[step].cover!=-inf) L[step].cover+=d;
        L[step].left_num+=d;
        L[step].right_num+=d;
        return ;
    }
    push_down(step);
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) update(lson,l,r,d);
    else if(l>m) update(rson,l,r,d);
    else{
        update(lson,l,m,d);
        update(rson,m+1,r,d);
    }
    push_up(step);
}
int query(int step,int l,int r){
    if(l>r) return 0;
    if(L[step].left==l&&L[step].right==r){
        return L[step].len;
    }
    push_down(step);
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) return query(lson,l,r);
    else if(l>m) return query(rson,l,r);
    else {
        int ans=max(query(lson,l,m),query(rson,m+1,r));
        if(L[lson].right_num==L[rson].left_num){
            ans=max(ans,min(m-l+1,L[lson].right_cnt)+min(r-m,L[rson].left_cnt));
        }
        return ans;
    }
}
int main(){
    int n,q,cas=0;
    while(scanf("%d%d",&n,&q)!=EOF){
        printf("Case #%d:\n",++cas);
        bulid(1,1,n-1);
        while(q--){
            char str[10];
            scanf("%s",str);
            if(str[0]=='A'){
                int l,r,a,d;
                scanf("%d%d%d%d",&l,&r,&a,&d);
                if(l&&a) update(1,l,l,a);
                if(d) update(1,l+1,r,d);
                if(r<n-1) update(1,r+1,r+1,-(a+(r-l)*d));
            }
            else{
                int l,r;
                scanf("%d%d",&l,&r);
                printf("%d\n",query(1,l+1,r)+1);
            }
        }
    }
    return 0;
}