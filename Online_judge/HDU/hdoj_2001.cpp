#include<stdio.h>

#include<math.h>
int main()
{
double a,b,c,d;
double r;
while(scanf("%lf %lf %lf %lf",&a,&b,&c,&d)!=EOF)
{
r=sqrt((a-c)*(a-c)+(b-d)*(b-d));
printf("%.2f\n",r);
}
return 0;
}