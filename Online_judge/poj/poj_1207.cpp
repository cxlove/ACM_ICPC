#include<stdio.h>
 
int main()
{
    int n,m,time,max,key,i,temp,sign;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&m);
        sign=0;
        if(n>m)
        {
            sign=1;
            temp=m;
            m=n;
            n=temp;
        }
        max=0;
        for(i=n;i<=m;++i)
        {
            key=i;
            time=1;
            while(key!=1)
            {
                if(key%2)
                {
                    key=key*3+1;
                }
                else 
                {
                    key=key/2;
                }
                ++time;
            }
            if(time>max)
            {
                max=time;
            }
        }
        if(sign)
        {
            printf("%d %d %d\n",m,n,max);
        }
        else printf("%d %d %d\n",n,m,max);
    }
    //system("pause");
    return 0;
}