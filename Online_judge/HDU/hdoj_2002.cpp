 #include<stdio.h>
 #define PI 3.1415927
 int main()
 {
     double r;
     while(scanf("%lf",&r)!=EOF)
     printf("%.3lf\n",r/3*4*r*r*PI);
     return 0;
 }