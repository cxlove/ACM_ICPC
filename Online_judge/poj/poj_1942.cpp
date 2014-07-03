#include <stdio.h>
int main(int argc, char *argv[])
{   long long i,j,k;
    double m,n,sum,num,x,y,z,max;
    while(1)
    {
        scanf("%lf %lf",&m,&n);
        if(m==0&&n==0)
            break;
        z=1;
        if(m!=0&&n!=0)
        {
            max=m>n?m:n;
            for(i=max+1;i<=m+n;i++)
            {
                z=z*i/(i-max);
            }
        }
        printf("%.0lf\n",z);
    }
    return 0;
}