#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define N 100005
#define inf 1<<29
#define MOD 9973
#define LL long long
#define eps 1e-7
#define zero(a) fabs(a)<eps
#define equal(a,b) zero(a-b)
using namespace std;
struct SegmentTree{
    int left,right,mid,add,val;
}L[N*4];
struct Node{
    int left,right;
}f[N];
int a[N*2],top,cnt,n,m;
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    L[step].add=L[step].val=0;
    if(l==r)
        return;
    bulid(2*step,l,(l+r)/2);
    bulid(2*step+1,(l+r)/2+1,r);
}
void update(int step,int l,int r){
    if(L[step].add){
        L[step].val+=L[step].add;
        L[2*step].add+=L[step].add;
        L[2*step+1].add+=L[step].add;
        L[step].add=0;
    }
    if(L[step].left==l&&r==L[step].right){
        L[step].add+=1;
        return ;
    }
    if(r<=L[step].mid)
        update(2*step,l,r);
    else if(l>L[step].mid)
        update(2*step+1,l,r);
    else{
        update(2*step,l,L[step].mid);
        update(2*step+1,L[step].mid+1,r);
    }
}
int query(int step,int pos){    
    if(L[step].add){
        L[step].val+=L[step].add;
        L[2*step].add+=L[step].add;
        L[2*step+1].add+=L[step].add;
        L[step].add=0;
    }
    if(L[step].left==L[step].right&&L[step].left==pos)
        return L[step].val;
    if(pos<=L[step].mid)
        return query(2*step,pos);
    else
        return query(2*step+1,pos);
}
int find(int num){
    int low=1,high=cnt-1,mid;
    while(low<=high){
        mid=(low+high)>>1;
        if(a[mid]==num)
            return mid;
        if(a[mid]<num)
            low=mid+1;
        else
            high=mid-1;
    }
    return mid;
}
int qq[N];
int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        top=cnt=2;
        a[1]=0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&f[i].left,&f[i].right);
            f[i].right++;
            a[top++]=f[i].left;
            a[top++]=f[i].right;
        }
        for(int i=0;i<m;i++){
            scanf("%d",&qq[i]);
            a[top++]=qq[i];
        }
        a[top++]=1000000005;
        sort(a+1,a+top);
        for(int i=2;i<top;i++)
            if(a[i]!=a[cnt-1])
                a[cnt++]=a[i];
        bulid(1,1,cnt-1);
        for( int i=0;i<n;i++){
            int x=find(f[i].left),y=find(f[i].right);
            update(1,x,y-1);
        }
        printf("Case #%d:\n",++cas);
        for(int i=0;i<m;i++){
            int x=find(qq[i]);
            printf("%d\n",query(1,x));
        }

    }
    return 0;
}