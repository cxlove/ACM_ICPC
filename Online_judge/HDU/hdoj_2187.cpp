

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
struct node{
    int p,m;
}kk[1100];
int cmp(const void*a,const void*b)
{
    struct node*c=(struct node*)a;
    struct node*d=(struct node*)b;
    return c->p-d->p;
}
int main()
{
    int t;
    int v,n,i,cnt;
    double pp;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&v,&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&kk[i].p,&kk[i].m);
        qsort(kk,n,sizeof(struct node),cmp);
        cnt=pp=0;
        while(1){
            pp+=kk[cnt].m;
            v-=kk[cnt].m*kk[cnt].p;
            if(v<0)
            {
                pp-=kk[cnt].m;
                v+=kk[cnt].m*kk[cnt].p;
                pp+=v*1.0/kk[cnt].p;
                v=0;
            }
            cnt++;
            if(cnt==n||v==0)break;
        }
        printf("%.2lf\n",pp);
    }
    return 0;
}