#include <stdio.h>

void main()
{ 
int num,i;
double u,v,w,l,t;
for(;scanf(" %d",&num) != EOF;)
   for(;num-- && scanf(" %lf %lf %lf %lf",&u,&v,&w,&l) != EOF;)
   {
    for(i=t=0;i<1000000;i++)
    {
     t+=l/(u+w);
     l-=l*(v+u)/(u+w);
     t+=l/(v+w);
     l-=l*(v+u)/(v+w);
    }
    printf("%.3lf\n",t*w);
   }
}
 

