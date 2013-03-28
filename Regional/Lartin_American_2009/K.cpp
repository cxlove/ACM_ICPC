/*
ID:cxlove
Prob:K Klingon Levels
Algorithm:segment tree
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#define lson step<<1
#define rson step<<1|1
using namespace std;
int a[10005];
struct Node
{
    int left,right;
    int lazy,m;
}L[4500];
int n;
void bulid(int step,int l,int r)
{
    L[step].left=l;
    L[step].right=r;
    L[step].lazy=L[step].m=0;
    if(l==r) return ;
    int m=(l+r)>>1;
    bulid(lson,l,m);
    bulid(rson,m+1,r);
}
void push_down(int step)
{
    if(L[step].lazy)
    {
        L[lson].lazy+=L[step].lazy;
        L[rson].lazy+=L[step].lazy;
        L[lson].m+=L[step].lazy;
        L[rson].m+=L[step].lazy;
        L[step].lazy=0;
    }
}
void update(int step,int l,int r,int val)
{
    if(L[step].left==l&&L[step].right==r)
    {
        L[step].lazy+=val;
        L[step].m+=val;
        return ;
    }
    push_down(step);
    int m=(L[step].left+L[step].right)>>1;
    if(r<=m) update(lson,l,r,val);
    else if(l>m) update(rson,l,r,val);
    else
    {
        update(lson,l,m,val);
        update(rson,m+1,r,val);
    }
    L[step].m=min(L[lson].m,L[rson].m);
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%d",&n)!=EOF&&n)
    {
        bulid(1,1,1005);
        for(int i=0; i<n; i++)
        {
            int k;
            scanf("%d",&k);
            for(int j=0; j<k; j++)
            {
                scanf("%d",&a[j]);
            }
            sort(a,a+k);
            a[k]=1001;a[k+1]=1003;
            update(1,1,a[0]-1+5,k);
            int s=a[0];
            for(int j=1;j<=k;j++)
            {
                if(a[j]==a[j-1]) continue;
                int l=j,r=k-l;
                update(1,s+5,a[j]-1+5,abs(l-r));
                s=a[j];
            }
        }
        printf("%d\n",L[1].m);
    }
    return 0;
}