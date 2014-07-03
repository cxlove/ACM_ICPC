#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define MAXN 1005
int a[MAXN];
struct coordinate
{double l,r;
}c[MAXN];
int cmp(const void *a,const void *b)
{
    struct coordinate *aa=(struct coordinate *)a;
    struct coordinate *bb=(struct coordinate *)b;
    return (((aa->r)>(bb->r))?1:-1);
}
int main()
{
    int i,j,l,n,sum,t=0;
    double x,y,dx,d;
    while(scanf("%d%lf",&n,&d),n||d)
    {
        sum=0;
        t++;
        l=1;
        if(d<=0)
            l=0;
        for(i=0;i<n;i++)
        {
            scanf("%lf%lf",&x,&y);
            if(y>d)
                l=0;
            else{
                dx=sqrt((d*d)-y*y);
                c[i].l=x-dx;
                c[i].r=x+dx;
            }
        }
        if(!l)
            printf("Case %d: -1\n",t);
        else{
            memset(a,0,sizeof(int)*n);
            qsort(c,n,sizeof(c[0]),cmp);
            for(i=0;i<n;i++)
            {
                if(!a[i]){
                    sum++;
                    a[i]=1;
                    for(j=i+1;j<n;j++)
                    {
                        if(c[j].l<=c[i].r)
                            a[j]=1;
                    }
                }
            }
            printf("Case %d: %d\n",t,sum);
        }
    }
    return 0;
}