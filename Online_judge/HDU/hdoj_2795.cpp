#include<iostream>
#include<cstdio>
using namespace std;
struct line{
    int left,right,mid,val;
}L[600005];
int n,h,w,ans;
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].val=w;
    if(l==r) return;
    bulid(2*step,l,(l+r)/2);
    bulid(2*step+1,(l+r)/2+1,r);
}
void query(int step,int wide){
    if(L[step].left==L[step].right){
        if(L[step].val<wide)
            return ;
        L[step].val-=wide;
        ans=L[step].left;
        return ;
    }
    if(L[2*step].val>=wide)
        query(2*step,wide);
    else
        query(2*step+1,wide);
    L[step].val=max(L[2*step].val,L[2*step+1].val);
}
int main(){
    while(scanf("%d%d%d",&h,&w,&n)!=EOF){
        h=min(200000,h);
        bulid(1,1,h);
        while(n--){
            int a;
            scanf("%d",&a);
            ans=-1;
            query(1,a);
            printf("%d\n",ans);
        }
    }
    return 0;
}
    