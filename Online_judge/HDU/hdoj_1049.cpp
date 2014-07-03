#include<stdio.h>
int main()
{
    int n,u,d;
    while(scanf("%d%d%d",&n,&u,&d),n)
    {
        int t=(n-u)/(u-d);
        if(t*(u-d)<(n-u)) t++;
        t*=2;
        t++;
        printf("%d\n",t);
    }    
    return 0;
}