/*
ID:cxlove
PROB:Stars
DATA:2012.2.23
HINT:线段树
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct line{
    int left,right,mid,cnt;
}L[150000];
int n,x[15000],y[15000];
int ans[15000];
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    L[step].cnt=0;
    if(l==r)
        return;
    bulid(2*step,l,(l+r)/2);
    bulid(2*step+1,(l+r)/2+1,r);
}
int query(int step,int l,int r){
    if(L[step].left==l&&r==L[step].right)
        return L[step].cnt;
    if(r<=L[step].mid)
        return  query(2*step,l,r);
    else
        return L[2*step].cnt+query(2*step+1,L[step].mid+1,r);
}
void update(int step,int pos){
    L[step].cnt++;
    if(L[step].left==L[step].right)
        return ;
    if(pos<=L[step].mid)
        update(2*step,pos);
    else
        update(2*step+1,pos);
}
int main(){
    while(scanf("%d",&n)!=EOF){
        int l=40000,r=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&x[i],&y[i]);
            l=min(l,x[i]);
            r=max(r,x[i]);
        }
        memset(ans,0,sizeof(ans));
        bulid(1,l,r);
        for(int i=0;i<n;i++){
            ans[query(1,l,x[i])]++;
        //    cout<<query(1,l,x[i])<<endl;
            update(1,x[i]);
        }
        for(int i=0;i<n;i++)
            printf("%d\n",ans[i]);
    }
    return 0;
}
/*
5
1 1
5 1
7 1
3 3
5 5
*/
