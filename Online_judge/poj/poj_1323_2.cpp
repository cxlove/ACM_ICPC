#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a[1101];
int b[1101];
int comp(const void *x,const void *y)
{
    int *p=(int *)x;
    int *q=(int *)y;
    return *q-*p;
}
int main()
{
int m,n;
int i,j;
int sum,times;
int flag;
int cases=0;
while(scanf("%d%d",&m,&n)&&m!=0||n!=0)
{
    cases++;
    sum=0;
    memset(a,0,sizeof(a));
    for(i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        a[b[i]]=1;
    }
    qsort(b,n,sizeof(int),comp);
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=m*n;j>b[i];j--)
        {
            if(a[j]==0) 
            {
                a[j]=1;
                flag=1;
                break;
            }
        }
        if(flag==0) sum++;
    }
    printf("Case %d: %d\n",cases,sum);
}
return 0;
}
