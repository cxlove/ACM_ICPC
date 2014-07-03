#include <stdio.h>
#include <string.h>
const int inf=1<<30;
int N,P,next[1005],ans,sum;
struct EDGE
{
    int l,r;
}edge[10010];
int cmp(struct EDGE A,struct EDGE B)
{
    if (A.l == B.l)
        return A.r<B.r;
    return A.l<B.l;
}
int main()
{
	int cur,i; int u,v;
	 int right,left;
    while (scanf("%d%d",&N,&P)!=EOF)
    {
        for (  i = 0; i < P; i++)
        {
               
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
        qsort (edge,P,sizeof(edge[0]),cmp);
        ans=inf;
        for ( cur=1;cur<=N;cur++)
        {
            memset(next,0,sizeof(next));
            sum=0;
            for ( i=0;i<P;i++)
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
		//	for(i=0;i<P;i++)
		//		printf("%d\n",next[i]);
			
           
            for ( i=1;i<=N;i++)
            {
                if(next[i]>0)
                {
                    left=i;
                    right=next[i];
                    break;
                }
            }
            sum+=right-left;
            for ( i=left+1;i<=N;i++)
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
		//	printf("%d\n",sum);system("pause");
            if (sum<ans)
                ans=sum;
        }
        printf("%d\n",ans);
    }
}