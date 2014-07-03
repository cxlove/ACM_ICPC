#include<cstdio>
using namespace std;
int pre[50005],w[50005];
int ans;
int Find(int x)
{
    if(x==pre[x]) return x;
    int t=pre[x];
    pre[x]=Find(pre[x]);
    w[x]=(w[t]+w[x])%300;
    return pre[x];
}
void Union(int x,int y,int num)
{
    int fax=Find(x);
    int fay=Find(y);
    pre[fax]=fay;
    w[fax]=(w[y]-w[x]+300+num)%300;
}
int main()
{
    int n,m,a,b,x;
    for(;scanf("%d%d",&n,&m)!=EOF;)
    {
        for(int i=0;i<=n;++i)
        {
            pre[i]=i;w[i]=0;
        }
        ans=0;
        for(;m--;)
        {
            scanf("%d%d%d",&a,&b,&x);
            int fax=Find(a);
            int fay=Find(b);
            if(fax==fay)
            {
                if((w[a]-w[b]+300)%300!=x)
                    ans++;
            }
            else
                Union(a,b,x);
        }
        printf("%d\n",ans);
    }
    return 0;
}    