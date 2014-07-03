#include<cstdio>
#include<iostream>
using namespace std;
const int mm=24222;
const int mn=111;
int v[mn],c[mn];
int f[mm],g[mm];
int n,m,mv,mx;
void CompletePack(int v)
{
    for(int i=v;i<=mv;++i)f[i]=min(f[i],f[i-v]+1);
}
void ZeroOnePack(int v,int d)
{
    for(int i=mv;i>=v;--i)f[i]=min(f[i],f[i-v]+d);
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        for(mx=i=0;i<n;++i)scanf("%d",&v[i]),mx=max(mx,v[i]);
        for(i=0;i<n;++i)scanf("%d",&c[i]);
        mx=mx*mx;
        mv=m+mx;
        for(i=0;i<=mv;++i)f[i]=g[i]=mm;
        f[0]=g[0]=0;
        for(i=0;i<n;++i)
            if(c[i])
            {
                if(c[i]*v[i]>=mv)CompletePack(v[i]);
                else
                {
                    j=1;
                    while(j<c[i])
                    {
                        ZeroOnePack(v[i]*j,j);
                        c[i]-=j;
                        j<<=1;
                    }
                    ZeroOnePack(v[i]*c[i],c[i]);
                }
            }
        for(i=0;i<n;++i)
            for(j=v[i];j<=mv;++j)
                g[j]=min(g[j],g[j-v[i]]+1);
        for(i=m;i<=mv;++i)f[m]=min(f[m],f[i]+g[i-m]);
        printf("%d\n",f[m]<mm?f[m]:-1);
    }
    return 0;
}