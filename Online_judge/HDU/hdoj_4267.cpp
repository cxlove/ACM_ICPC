#include <stdio.h>

#define L(x) (x<<1)
#define R(x) (x<<1|1)
#define MID(x,y) ((x+y)>>1)

typedef __int64 LL;

const int M = 50003;

int v[M];

struct Tnode
{
    int l,r;
    int sum,delta;
}TT[56][M<<2];

void Build(Tnode* T,int u,int l,int r)
{
    T[u].l = l , T[u].r = r;
    if(l == r-1)
    {
        T[u].sum = T[u].delta = 0;
        return ;
    }
    int mid = MID(l,r);
    Build(T,L(u),l,mid);
    Build(T,R(u),mid,r);
    T[u].sum = T[u].delta = 0;
}

void Updata(Tnode* T,int u,int l,int r,int up)
{
    if(T[u].l == l && T[u].r == r)
    {
        T[u].delta += up;
        return ;
    }
    else
        T[u].sum += up*(r-l);
    int mid = MID(T[u].l,T[u].r);
    if(l >= mid)
        Updata(T,R(u),l,r,up);
    else
        if(r <= mid)
            Updata(T,L(u),l,r,up);
        else
        {
            Updata(T,L(u),l,mid,up);
            Updata(T,R(u),mid,r,up);
        }
}

int Query(Tnode* T,int u,int l,int r)
{
    int delta = T[u].delta;
    if(T[u].l == l && T[u].r == r)
        return T[u].sum + delta*(r-l);
    T[L(u)].delta += delta;
    T[R(u)].delta += delta;
    T[u].sum += delta*(T[u].r-T[u].l);
    T[u].delta = 0;
    int mid = MID(T[u].l,T[u].r);
    if(l >= mid)
        return Query(T,R(u),l,r);
    else
        if(r <= mid)
            return Query(T,L(u),l,r);
        else
            return Query(T,L(u),l,mid) + Query(T,R(u),mid,r);
}

int id(int a,int k)              //返回要更新的是哪颗线段树
{
    return k*(k-1)/2 + a%k +1;
}

int main()
{
    int n,Q,cmd,a,b,k,t;
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&v[i]);
        for(k=1;k<=10;k++)
            for(int i=0;i<k;i++)
                Build(TT[id(i,k)],1,1/k,n/k+1);
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%d",&cmd);
            if(cmd == 1)
            {
                scanf("%d%d%d%d",&a,&b,&k,&t);
                Updata(TT[id(a,k)],1,a/k,a/k+(b-a)/k+1,t);  
            }
            else
            {
                scanf("%d",&a);
                int tmp = 0;
                for(k=1;k<=10;k++)
                    tmp += Query(TT[id(a,k)],1,a/k,a/k+1);
                printf("%d\n",tmp+v[a]);
            }
        }
    }
    return 0;
}