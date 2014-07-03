#include<stdio.h>
#include<math.h>
double l,n,c,l1,x1,x2,mid;
double f(double x)
{
    return x-2*sin(x/2)*l1/l;
}
int main()
{
    while(scanf("%lf%lf%lf",&l,&n,&c)&&!(l<0&&n<0&&c<0))
    {
        l1=(n*c+1)*l;
        x1=0.000000000000001;
        x2=acos(-1);
        while(fabs(x1-x2)>1e-10)
        {
            mid=(x1+x2)/2;
            if(f(mid)*f(x1)>0)
                x1=mid;
            else x2=mid;
        }
        mid=(x1+x2)/2;
        printf("%.3f\n",l1/mid*(1-cos(mid/2)));
    }
    return 0;
}