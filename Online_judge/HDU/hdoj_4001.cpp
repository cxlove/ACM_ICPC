#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
typedef __int64 ll;
struct Blockock
{
    int a,b,c,d;
} block[1001];
int n;
ll dp[1001],ans;
int cmp(const void *aa,const void *bb)
{
    struct Blockock *e = (Blockock *)aa;
    struct Blockock *f = (Blockock *)bb;
    if(e->a!=f->a) return e->a - f->a;
    if(e->b!=f->b) return e->b - f->b;
    return f->d - e->d;
}
int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d %d %d",&block[i].a,&block[i].b,&block[i].c,&block[i].d);
            if(block[i].a<block[i].b)
            {
                int temp=block[i].a;
                block[i].a=block[i].b;
                block[i].b=temp;
            }
        }
        qsort(block+1,n,sizeof(block[0]),cmp);
        ans=0;
        for(int i=1; i<=n; i++)
        {
            dp[i]=block[i].c;
            for(int j=1; j<i; j++)
            {
                if(block[i].d==0&&block[i].a>=block[j].a&&block[i].b>=block[j].b)
                    dp[i]=max(dp[j]+block[i].c,dp[i]);
                if(block[i].d==1&&block[i].a>=block[j].a&&block[i].b>=block[j].b&&(block[i].a>block[j].a||block[i].b>block[j].b))
                    dp[i]=max(dp[j]+block[i].c,dp[i]);
                if(block[i].d==2&&block[i].a>block[j].a&&block[i].b>block[j].b)
                    dp[i]=max(dp[j]+block[i].c,dp[i]);
            }
            if(dp[i]>ans)
                ans=dp[i];
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
