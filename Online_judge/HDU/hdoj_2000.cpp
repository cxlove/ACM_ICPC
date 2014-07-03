#include <stdio.h>
#include <stdlib.h>
int main()
{
    char ch[3],temp;
    int i,n,j;
    while(scanf("%s",ch )!=EOF)
        {
        for(i=0;i<3;i++)
        {
            for(j=0;j<2;j++)
        {
            if(ch[j]>ch[j+1])
            {
                temp=ch[j];
                ch[j]=ch[j+1];
                ch[j+1]=temp;
            }
        }
        }
        for(i=0;i<3;i++)
        if(i!=2)printf("%c ",ch[i]);
        else printf("%c\n",ch[i]);
        }
}