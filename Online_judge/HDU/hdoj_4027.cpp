#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define LL long long
using namespace std;
struct Line{
       int left,right,mid;
       LL sum;
}L[500000];
LL a[100005];
LL bulid(int step,int l,int r){
     L[step].left=l;
     L[step].right=r;
     L[step].mid=(l+r)/2;
     if(l==r)
         return L[step].sum=a[l];
     return L[step].sum=bulid(2*step,l,(l+r)/2)+bulid(2*step+1,(l+r)/2+1,r);
}
LL update(int step,int l,int r){  
     if(L[step].sum==r-l+1)
          return L[step].sum;
     if(L[step].left==L[step].right)
          return L[step].sum=sqrt((double)L[step].sum);
     if(r<=L[step].mid)
         return L[step].sum=update(2*step,l,r)+L[2*step+1].sum;
     else if(l>L[step].mid)
         return L[step].sum=update(2*step+1,l,r)+L[step*2].sum;
     else
         return L[step].sum=update(2*step,l,L[step].mid)+update(2*step+1,L[step].mid+1,r);
}
LL query(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r)
         return L[step].sum;
    if(r<=L[step].mid)
        return query(2*step,l,r);
    else if(l>L[step].mid)
        return query(2*step+1,l,r);
    else return query(2*step,l,L[step].mid)+query(2*step+1,L[step].mid+1,r);
}
int main(){
    int n,cas=0;
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        bulid(1,1,n);
        int q;
        scanf("%d",&q);
        printf("Case #%d:\n",++cas);
        while(q--){
            int k,x,y;
            scanf("%d%d%d",&k,&x,&y);
            if(x>y)
               swap(x,y);
            if(k)
               printf("%I64d\n",query(1,x,y));
            else
               update(1,x,y);
        }
        puts("");
    }
    return 0;
}

 

