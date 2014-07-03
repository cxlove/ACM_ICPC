#include<iostream>
#include<cstdio>
#include <queue>
#include<cstring>
#include<algorithm>
#define N 100005
#define lson step<<1
#define rson step<<1|1
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))

using namespace std;
struct Node
{
    int left,right,c;
    int mx,mn;
}L[N*4];
int n,m,val[N];
void Push_Up(int step)
{
    L[step].mx=MAX(L[lson].mx,L[rson].mx);
    L[step].mn=MIN(L[lson].mn,L[rson].mn);
    if(L[lson].c==L[rson].c) L[step].c=L[lson].c;
    else L[step].c=-1;
}
void Push_Down(int step)
{
    L[lson].c=L[lson].mx=L[lson].mn=L[step].c;
    L[rson].c=L[rson].mx=L[rson].mn=L[step].c;
    L[step].c=-1;
}
void Bulid(int step,int l,int r)
{
    L[step].left=l;
    L[step].right=r;
    if(l==r)
    {
        L[step].mx=L[step].mn=L[step].c=val[l];
        return ;
    }
    int m=(l+r)/2;
    Bulid(lson,l,m);
    Bulid(rson,m+1,r);
    Push_Up(step);
}
void Update(int step,int l,int r,int c)
{
    if(L[step].left==l&&r==L[step].right)
    {
        L[step].c=L[step].mx=L[step].mn=c;
        return;
    }
    if(L[step].c!=-1) Push_Down(step);
    int m=(L[step].left+L[step].right)/2;
    if(r<=m) Update(lson,l,r,c);
    else if(l>m) Update(rson,l,r,c);
    else
    {
        Update(lson,l,m,c);
        Update(rson,m+1,r,c);
    }
    Push_Up(step);
}
int Query(int step,int l,int r,int c)
{
    if(L[step].mx<c||L[step].mn>c) return 0;
    if(L[step].left==L[step].right) return L[step].c==c?1:0;
    //if(L[step].c!=-1) Push_Down(step);
    if(L[step].c!=-1) return (L[step].c==c)?(r-l+1):0;
    if(L[step].left==l&&L[step].right==r)
    {
        if(L[step].c!=-1) return (L[step].c==c)?(L[step].right-L[step].left+1):0;
    }
    int m=(L[step].left+L[step].right)/2;
    if(r<=m) return Query(lson,l,r,c);
    else if(l>m) return Query(rson,l,r,c);
    else return Query(lson,l,m,c)+Query(rson,m+1,r,c);
}
inline void scanf_(int &num){
    char in;
    bool neg=false;
    while(((in=getchar()) > '9' || in<'0') && in!='-') ;
    if(in=='-'){
        neg=true;
        while((in=getchar()) >'9' || in<'0');
    }
    num=in-'0';
    while(in=getchar(),in>='0'&&in<='9')
        num*=10,num+=in-'0';
    if(neg)
        num=0-num;
}
inline void printf_(int num){
    bool flag=false;
    if(num<0){
        putchar('-');
        num=-num;
    }
    int ans[10],top=0;
    while(num!=0){
        ans[top++]=num%10;
        num/=10;
    }
    if(top==0)
        putchar('0');
    for(int i=top-1;i>=0;i--){
        char ch=ans[i]+'0';
        putchar(ch);
    }
    putchar('\n');
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++) scanf_(val[i]);
        Bulid(1,0,n-1);
        while(m--)
        {
            int k,l,r,c;
            scanf_(k);scanf_(l);scanf_(r);scanf_(c);
            if(k==1) Update(1,l,r,c);
            else printf_(Query(1,l,r,c));
        }
    }
    return 0;
}
