#include<stdio.h>
#include<string.h>
__int64 num[1005];
int n;
int fun()
{
    __int64 sum=0;
    for(int i=1;i<=n;++i)
    sum=sum^num[i];
    if(sum)
    return 0;
    else
    return 1;
}
int main()
{
    while(scanf("%d",&n)!=-1&&n)
    {
        for(int i=1; i<=n; i++)
            scanf("%I64d",&num[i]);
        if(n%2==0&&fun())
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}