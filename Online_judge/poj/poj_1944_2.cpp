#include <stdio.h>
#include <iostream>
#include <string.h>
#include<algorithm>
using namespace std;
const int inf=1<<30;
int N,P,next[1005],ans,sum;
struct EDGE
{
    int l,r;
}edge[10010];
bool cmp(EDGE A,EDGE B)
{
    if (A.l == B.l)
        return A.r<B.r;
    return A.l<B.l;
}
int main()
{
    while (scanf("%d%d",&N,&P)!=EOF)
    {
        for (int  i = 0; i < P; i++)
        {
                int u,v;
                scanf("%d%d",&u,&v);
                if (u > v)
                {
                    edge[i].l=v;
                    edge[i].r=u;
                }
                else 
                {
                    edge[i].l=u;
                    edge[i].r=v;
                }
        }
        sort (edge,edge+P,cmp);
        ans=inf;
        for (int cur=1;cur<=N;cur++)
        {
            memset(next,0,sizeof(next));
            sum=0;
            for (int i=0;i<P;i++)
            {
                if (edge[i].l<cur&&edge[i].r>=cur)
                {
                    if (edge[i].l>next[1])
                        next[1]=edge[i].l;
                    if (next[edge[i].r]<N+1)
                        next[edge[i].r]=N+1;
                }
                else
                {
                    if (next[edge[i].l]<edge[i].r)
                        next[edge[i].l]=edge[i].r;
                }
            }
            int right,left;
            for (int i=1;i<=N;i++)
            {
                if(next[i]>0)
                {
                    left=i;
                    right=next[i];
                    break;
                }
            }
            sum+=right-left;
            for (int i=left+1;i<=N;i++)
            {
                if (next[i]==0)
                    continue;
                if (i>right)
                {
                    sum+=next[i]-i;
                    left=i;
                    right=next[i];
                }
                else if(next[i]>right)
                {
                    sum+=next[i]-right;
                    left=i;
                    right=next[i];
                }
                if (sum>ans) break;
            }
            if (sum<ans)
                ans=sum;
        }
        printf("%d\n",ans);
    }
}