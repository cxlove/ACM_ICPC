/*
ID:cxlove
PROB:Sequence operation 
DATA:2012.2.26
HINT:线段树
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct line{
    int left,right,mid;
    int cover,sum;
    int l0,r0,m0,l1,r1,m1;
    int dis(){return right-left+1;}
}L[500000];
int n,q,val[100005];
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    
    if(l==r){
        L[step].sum=val[l];
        L[step].l0=L[step].r0=L[step].m0=(val[l]==0?1:0);
        L[step].l1=L[step].r1=L[step].m1=(val[l]==1?1:0);
        L[step].cover=val[l];
        return;
    }
    bulid(2*step,l,(l+r)/2);
    bulid(2*step+1,(l+r)/2+1,r);
    L[step].cover=(L[2*step].cover==L[2*step+1].cover?L[2*step].cover:-1);
    L[step].sum=L[2*step].sum+L[2*step+1].sum;
    L[step].l0=L[2*step].l0+(L[2*step].l0==L[2*step].dis()?L[2*step+1].l0:0);
    L[step].r0=L[2*step+1].r0+(L[2*step+1].r0==L[2*step+1].dis()?L[2*step].r0:0);
    L[step].m0=max(max(L[2*step].m0,L[2*step+1].m0),L[2*step].r0+L[2*step+1].l0);
    L[step].l1=L[2*step].l1+(L[2*step].l1==L[2*step].dis()?L[2*step+1].l1:0);
    L[step].r1=L[2*step+1].r1+(L[2*step+1].r1==L[2*step+1].dis()?L[2*step].r1:0);
    L[step].m1=max(max(L[2*step].m1,L[2*step+1].m1),L[2*step].r1+L[2*step+1].l1);
}
void update(int step,int l,int r,int k){
    if(L[step].left==l&&L[step].right==r){
        L[step].cover=k;
        L[step].l0=L[step].r0=L[step].m0=(k==0?L[step].dis():0);
        L[step].l1=L[step].r1=L[step].m1=(k==1?L[step].dis():0);
        L[step].sum=k*L[step].dis();
        return ;
    }
    if(L[step].cover!=-1){
        L[step*2].cover=L[2*step+1].cover=L[step].cover;
        L[step*2].l0=L[step*2].r0=L[step*2].m0=(L[step*2].cover==0?L[step*2].dis():0);
        L[step*2].l1=L[step*2].r1=L[step*2].m1=(L[step*2].cover==1?L[step*2].dis():0);
        L[step*2].sum=L[2*step].cover*L[step*2].dis();
        L[step*2+1].l0=L[step*2+1].r0=L[step*2+1].m0=(L[step*2+1].cover==0?L[step*2+1].dis():0);
        L[step*2+1].l1=L[step*2+1].r1=L[step*2+1].m1=(L[step*2+1].cover==1?L[step*2+1].dis():0);
        L[step*2+1].sum=L[2*step+1].cover*L[step*2+1].dis();
        L[step].cover=-1;
    }
    if(r<=L[step].mid)
        update(2*step,l,r,k);
    else if(l>L[step].mid)
        update(2*step+1,l,r,k);
    else{
        update(2*step,l,L[step].mid,k);
        update(2*step+1,L[step].mid+1,r,k);
    }
    L[step].sum=L[2*step].sum+L[2*step+1].sum;
    L[step].l0=L[2*step].l0+(L[2*step].l0==L[2*step].dis()?L[2*step+1].l0:0);
    L[step].r0=L[2*step+1].r0+(L[2*step+1].r0==L[2*step+1].dis()?L[2*step].r0:0);
    L[step].m0=max(max(L[2*step].m0,L[2*step+1].m0),L[2*step].r0+L[2*step+1].l0);
    L[step].l1=L[2*step].l1+(L[2*step].l1==L[2*step].dis()?L[2*step+1].l1:0);
    L[step].r1=L[2*step+1].r1+(L[2*step+1].r1==L[2*step+1].dis()?L[2*step].r1:0);
    L[step].m1=max(max(L[2*step].m1,L[2*step+1].m1),L[2*step].r1+L[2*step+1].l1);
}
void getnot(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r&&L[step].cover!=-1){
        L[step].cover=1-L[step].cover;
        L[step].l0=L[step].r0=L[step].m0=(L[step].cover==0?L[step].dis():0);
        L[step].l1=L[step].r1=L[step].m1=(L[step].cover==1?L[step].dis():0);
        L[step].sum=L[step].cover*L[step].dis();
        return ;
    }
    if(L[step].cover!=-1){
        L[step*2].cover=L[2*step+1].cover=L[step].cover;
        L[step*2].l0=L[step*2].r0=L[step*2].m0=(L[step*2].cover==0?L[step*2].dis():0);
        L[step*2].l1=L[step*2].r1=L[step*2].m1=(L[step*2].cover==1?L[step*2].dis():0);
        L[step*2].sum=L[2*step].cover*L[step*2].dis();
        L[step*2+1].l0=L[step*2+1].r0=L[step*2+1].m0=(L[step*2+1].cover==0?L[step*2+1].dis():0);
        L[step*2+1].l1=L[step*2+1].r1=L[step*2+1].m1=(L[step*2+1].cover==1?L[step*2+1].dis():0);
        L[step*2+1].sum=L[2*step+1].cover*L[step*2+1].dis();
        L[step].cover=-1;
    }
    if(r<=L[step].mid)
        getnot(2*step,l,r);
    else if(l>L[step].mid)
        getnot(2*step+1,l,r);
    else{
        getnot(2*step,l,L[step].mid);
        getnot(2*step+1,L[step].mid+1,r);
    }
    L[step].sum=L[2*step].sum+L[2*step+1].sum;
    L[step].l0=L[2*step].l0+(L[2*step].l0==L[2*step].dis()?L[2*step+1].l0:0);
    L[step].r0=L[2*step+1].r0+(L[2*step+1].r0==L[2*step+1].dis()?L[2*step].r0:0);
    L[step].m0=max(max(L[2*step].m0,L[2*step+1].m0),L[2*step].r0+L[2*step+1].l0);
    L[step].l1=L[2*step].l1+(L[2*step].l1==L[2*step].dis()?L[2*step+1].l1:0);
    L[step].r1=L[2*step+1].r1+(L[2*step+1].r1==L[2*step+1].dis()?L[2*step].r1:0);
    L[step].m1=max(max(L[2*step].m1,L[2*step+1].m1),L[2*step].r1+L[2*step+1].l1);
}
int query1(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r)
        return L[step].sum;
    if(L[step].cover!=-1){
        L[step*2].cover=L[2*step+1].cover=L[step].cover;
        L[step*2].l0=L[step*2].r0=L[step*2].m0=(L[step*2].cover==0?L[step*2].dis():0);
        L[step*2].l1=L[step*2].r1=L[step*2].m1=(L[step*2].cover==1?L[step*2].dis():0);
        L[step*2].sum=L[step*2].cover*L[step*2].dis();
        L[step*2+1].l0=L[step*2+1].r0=L[step*2+1].m0=(L[step*2+1].cover==0?L[step*2+1].dis():0);
        L[step*2+1].l1=L[step*2+1].r1=L[step*2+1].m1=(L[step*2+1].cover==1?L[step*2+1].dis():0);
        L[step*2+1].sum=L[2*step+1].cover*L[step*2+1].dis();
        L[step].cover=-1;
    }
    if(r<=L[step].mid)
        return query1(2*step,l,r);
    else if(l>L[step].mid)
        return query1(2*step+1,l,r);
    else
        return query1(2*step,l,L[step].mid)+query1(2*step+1,L[step].mid+1,r);
}
int query2(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r)
        return L[step].m1;
    if(L[step].cover!=-1){
        L[step*2].cover=L[2*step+1].cover=L[step].cover;
        L[step*2].l0=L[step*2].r0=L[step*2].m0=(L[step*2].cover==0?L[step*2].dis():0);
        L[step*2].l1=L[step*2].r1=L[step*2].m1=(L[step*2].cover==1?L[step*2].dis():0);
        L[step*2].sum=L[step*2].cover*L[step*2].dis();
        L[step*2+1].l0=L[step*2+1].r0=L[step*2+1].m0=(L[step*2+1].cover==0?L[step*2+1].dis():0);
        L[step*2+1].l1=L[step*2+1].r1=L[step*2+1].m1=(L[step*2+1].cover==1?L[step*2+1].dis():0);
        L[step*2+1].sum=L[2*step+1].cover*L[step*2+1].dis();
        L[step].cover=-1;
    }
    if(r<=L[step].mid)
        return query2(2*step,l,r);
    else if(l>L[step].mid)
        return query2(2*step+1,l,r);
    else {
        int l1=min(L[2*step].r1,L[step].mid-l+1);
        int r1=min(L[2*step+1].l1,r-L[step].mid);
        return max(max(query2(2*step,l,L[step].mid),query2(2*step+1,L[step].mid+1,r)),l1+r1);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)
            scanf("%d",&val[i]);
        bulid(1,0,n-1);
    //    for(int i=1;i<30;i++)
    //        printf("left:%d right:%d l1:%d r1:%d m1:%d\n",L[i].left,L[i].right,L[i].l1,L[i].r1,L[i].m1);
        while(q--){
            int kind,a,b;
            scanf("%d%d%d",&kind,&a,&b);
            switch(kind){
            case 0:{
                update(1,a,b,0);
                break;
                   }
            case 1:{
                update(1,a,b,1);
                break;
                   }
            case 2:{
                getnot(1,a,b);
                break;
                   }
            case 3:{
                printf("%d\n",query1(1,a,b));
                break;
                   }
            case 4:{
                printf("%d\n",query2(1,a,b));
                break;
                   }
            }
        }
    }
    return 0;
}
/*
1
10 10
0 0 0 1 1 0 1 0 1 1
1 0 2
3 0 5
2 2 2
4 0 4
0 3 6
2 3 7
4 2 8
1 0 5
0 5 6
3 3 9
*/
        