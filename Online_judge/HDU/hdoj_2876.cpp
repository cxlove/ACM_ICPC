#include <stdio.h>
int main()
{
int a,b,x,y,t;
    scanf("%d",&t);
while(t--)
{
        scanf("%d %d %d %d",&a,&b,&x,&y);
   if(double((x*x*1.0)/(a*a*1.0) + (y*y*1.0)/(b*b*1.0) ) <1)
    printf("In ellipse\n");
   else
    printf("%d\n",a*a*b*b);
}
return 0;
}