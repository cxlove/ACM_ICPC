#include <stdio.h>
#include <stdlib.h>

int main()
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    {
        if(n<0)n=-n;
     printf("%.2f\n",n);
    }
   return 0;
}