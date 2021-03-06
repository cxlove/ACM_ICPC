#include<iostream>
#include<cstdio>
using namespace std;
struct line
{
    int left,right,mid,mmax;
}L[600010];
int n,m,num[200005];
int bulid(int step,int l,int r)
{
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    if(l==r)
        return L[step].mmax=num[l];
    return L[step].mmax=max(bulid(2*step,l,(l+r)/2),bulid(2*step+1,(l+r)/2+1,r));
}
void update(int step,int a,int b)
{
    L[step].mmax=max(b,L[step].mmax);
    if(L[step].left==L[step].right)
        return;
    if(L[step].mid<a)
        update(2*step+1,a,b);
    else
        update(2*step,a,b);
}
int find(int step,int l,int r)
{
    if(L[step].left==l&&L[step].right==r)
        return L[step].mmax;
    if(L[step].mid<l)
        return find(2*step+1,l,r);
    else if(L[step].mid>=r)
        return find(2*step,l,r);
    else
        return max(find(2*step,l,L[step].mid),find(2*step+1,L[step].mid+1,r));
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&num[i]);
        bulid(1,1,n);
        while(m--)
        {
            char ch;
            int a,b;
            scanf(" %c%d%d",&ch,&a,&b);
            if(ch=='Q')
                printf("%d\n",find(1,a,b));
            else
                update(1,a,b);
        }
    }
    return 0;
}

