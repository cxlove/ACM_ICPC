#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#define ls rt<<1
#define rs rt<<1|1
#define lson l,m,ls
#define rson m,r,rs
using namespace std;
const int mm=22222;
const int mn=mm<<2;
int ot[]={1,2,4,3,5,6,7};
struct seg
{
    int x,y1,y2,val;
}g[mm];
int len[mn][8],y[mm],L,R;
long long ans[8];
int t[mn][4],val;
void build()
{
    memset(len,0,sizeof(len));
    memset(t,0,sizeof(t));
    memset(ans,0,sizeof(ans));
}
void updata(int l,int r,int rt)
{
    if(L<=y[l]&&R>=y[r])val<0?--t[rt][-val]:++t[rt][val];
    else
    {
        int m=(l+r)>>1;
        if(L<y[m])updata(lson);
        if(R>y[m])updata(rson);
    }
    int ste=(t[rt][1]>0)|((t[rt][2]>0)<<1)|((t[rt][3]>0)<<2);
    if(ste>0)
    {
        for(int i=1;i<8;++i)len[rt][i]=0;
        len[rt][ste]=y[r]-y[l];
        for(int i=1;i<8;++i)
            if((i|ste)!=ste)
            {
                int tmp=(len[rt<<1][i]+len[rt<<1|1][i]);
                len[rt][i|ste]+=tmp;
                len[rt][ste]-=tmp;
            }
    }
    else if(l>=r)memset(len[rt],0,sizeof(len[rt]));
    else for(int i=1;i<8;++i)len[rt][i]=(len[rt<<1][i]+len[rt<<1|1][i]);
}
bool cmp(seg a,seg b)
{
    return a.x<b.x;
}
int main()
{
    int i,j,m,n,t,cs=0;
    char co[8];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;++i)
        {
            scanf("%s%d%d%d%d",co,&g[i].x,&y[i],&g[i+n].x,&y[i+n]);
            if(co[0]=='R')j=1;
            if(co[0]=='G')j=2;
            if(co[0]=='B')j=3;
            g[i].y1=y[i],g[i].y2=y[i+n],g[i].val=j;
            g[i+n].y1=y[i],g[i+n].y2=y[i+n],g[i+n].val=-j;
        }
        sort(y,y+n+n);
        sort(g,g+n+n,cmp);
        for(m=i=0;i<n+n;++i)
            if(y[m]<y[i])y[++m]=y[i];
        build();
        for(i=0;i<n+n;++i)
        {
            L=g[i].y1,R=g[i].y2,val=g[i].val;
            updata(0,m,1);
            if(g[i].x<g[i+1].x)
                for(j=1;j<8;++j)
                    ans[j]+=(long long)(g[i+1].x-g[i].x)*(long long)len[1][j];
        }
        printf("Case %d:\n",++cs);
        for(j=1;j<8;++j)
            printf("%I64d\n",ans[ot[j-1]]);
    }
    return 0;
}