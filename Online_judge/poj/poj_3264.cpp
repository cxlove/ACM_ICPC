#include<iostream>
#include<cstdio>
using namespace std;
struct line
{
    int left,right,mid,mmax,mmin;
}L[300010];
int num[1000001];
int Max,Min;
void bulid(int step,int l,int r)
{
    L[step].left=l;
    L[step].right=r;
    L[step].mid=(l+r)/2;
    if(l==r)
        return;
    bulid(2*step,l,(l+r)/2);
    bulid(2*step+1,(l+r)/2+1,r);
}
int query_max(int step,int a,int b)
{
    if(L[step].left==L[step].right)
        return L[step].mmax=num[L[step].left];
    if(L[step].mid<a)
        return query_max(2*step+1,a,b);
    else if(L[step].mid>=b)
        return query_max(2*step,a,b);
    else
        return L[step].mmax=max(query_max(2*step,a,L[step].mid),query_max(2*step+1,L[step].mid+1,b));
}
int query_min(int step,int a,int b)
{
    if(L[step].left==L[step].right)
        return L[step].mmin=num[L[step].left];
    if(L[step].mid<a)
        return query_min(2*step+1,a,b);
    else if(L[step].mid>=b)
        return query_min(2*step,a,b);
    else
        return L[step].mmin=min(query_min(2*step,a,L[step].mid),query_min(2*step+1,L[step].mid+1,b));
}
int find_max(int step,int a,int b)
{
    if(L[step].left==a&&L[step].right==b)
        return L[step].mmax;
    if(b <= L[step].mid) 
        return find_max(2*step,a,b);     
    else if(L[step].mid < a) 
        return find_max(2*step+1,a,b);
    else
        return max(find_max(2*step,a,L[step].mid) , find_max(2*step+1,L[step].mid+1,b));
}
int find_min(int step,int a,int b)
{
    if(L[step].left==a&&L[step].right==b)
        return L[step].mmin;
    if(b <= L[step].mid) 
        return find_min(2*step,a,b);     
    else if(L[step].mid < a) 
        return find_min(2*step+1,a,b);
    else
        return min(find_min(2*step,a,L[step].mid) , find_min(2*step+1,L[step].mid+1,b));
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&num[i]);
    bulid(1,1,n);
    query_max(1,1,n);
    query_min(1,1,n);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",find_max(1,a,b)-find_min(1,a,b));     
    }
    return 0;
}