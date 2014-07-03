#include<iostream>
#include<cstdio>
using namespace std;
struct line
{
    int right,left,mid,col;
}L[300030];
void bulid(int step,int l,int r)
{
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    L[step].col=1;
    if(l==r) return;
    bulid(2*step,l,(l+r)/2);
    bulid(2*step+1,(l+r)/2+1,r);
}
void update(int step,int l,int r,int c)
{
    if(l<=L[step].left&&r>=L[step].right)
    {
        L[step].col=c;
        return;
    }
    if(L[step].col)
    {
        L[2*step].col=L[step*2+1].col=L[step].col;
        L[step].col=0;
    }
    if(l<=L[step].mid) update(2*step,l,r,c);
    if(L[step].mid<r)    update(2*step+1,l,r,c);
}
int query(int step)
{
    if(L[step].col)
        return L[step].col*(L[step].right-L[step].left+1);
    return query(2*step)+query(2*step+1);
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int Case=1;Case<=t;Case++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        bulid(1,1,n);
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            update(1,a,b,c);
        }
        printf("Case %d: The total value of the hook is %d.\n",Case,query(1));
    }
    return 0;
}

