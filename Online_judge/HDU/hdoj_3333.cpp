/*
ID:cxlove
PROB:Turing Tree 
DATA:2012.2.24
HINT:线段树+离散化
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL __int64
using namespace std;
struct line{
    int left,right,mid;
    LL sum;
}L[150000];
struct Node{
    int start,end;
    int idx;
}Q[100005];
int n,val[30005],p[30005],pcount,vis[30005],q;
LL ans[100000];
bool cmp(Node n1,Node n2){
    return n1.end<n2.end;
}
int Bin(int pp){
    int low=0,high=pcount-1,mid;
    while(low<=high){
        mid=(low+high)/2;
        if(p[mid]==pp)
            return mid;
        if(p[mid]>pp)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
void bulid(int step,int l,int r){
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    L[step].sum=0;
    if(l==r)
        return;
    bulid(2*step,l,(l+r)/2);
    bulid(2*step+1,(l+r)/2+1,r);
}
void update(int step,int pos,int v){
    if(L[step].left==L[step].right){
        L[step].sum+=v;
        return ;
    }
    if(pos<=L[step].mid)
        update(2*step,pos,v);
    else
        update(2*step+1,pos,v);
    L[step].sum=L[2*step].sum+L[step*2+1].sum;
}
LL query(int step,int l,int r){
    if(L[step].left==l&&L[step].right==r)
        return L[step].sum;
    if(r<=L[step].mid)
        return query(2*step,l,r);
    else if(l>L[step].mid)
        return query(2*step+1,l,r);
    else return (LL)query(2*step,l,L[step].mid)+query(2*step+1,L[step].mid+1,r);
}        
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&val[i]);
            p[i-1]=val[i];
        }
        bulid(1,1,n);
        sort(p,p+n);
        pcount=0;
        for(int i=0;i<n;i++)
            if(i==0||p[i]!=p[i-1])
                p[pcount++]=p[i];
        memset(vis,-1,sizeof(vis));
        scanf("%d",&q);
        for(int i=0;i<q;i++){
            scanf("%d%d",&Q[i].start,&Q[i].end);
            Q[i].idx=i;
        }
        sort(Q,Q+q,cmp);
/*
        int j=0;
        for(int i=1;i<=n;i++){ 
            int temp=Bin(val[i]); 
            if(vis[temp]!=-1)
                update(1,vis[temp],-val[i]); 
            update(1,i,val[i]); 
            vis[temp]=i; 
            for(;j<q;j++){ 
                if(i==Q[j].end)        
                    ans[Q[j].idx]=query(1,Q[j].start,Q[j].end);
                else break; 
            } 
        } 
    */        
        int end=0;
        for(int i=0;i<q;i++){
            for(int j=end+1;j<=Q[i].end;j++){
                int temp=Bin(val[j]);
                if(vis[temp]!=-1)
                    update(1,vis[temp],-val[j]);
                update(1,j,val[j]);
                vis[temp]=j;
            }
            ans[Q[i].idx]=query(1,Q[i].start,Q[i].end);
            end=Q[i].end;
        }
    
        for(int i=0;i<q;i++)
            printf("%I64d\n",ans[i]);
    }
    return 0;
}
/*
2
3
1 1 4
2
1 2
2 3
5
1 1 2 1 3
3
1 5
2 4
3 5
*/



