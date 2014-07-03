#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    double l1,l2,v1,v2;
    scanf("%d",&t);
    for(;t--;)
    {
        scanf("%lf%lf%lf%lf",&l1,&l2,&v1,&v2);
        if(l1<10)
        {
            printf("0\n");
            continue;
        }
        double s=v2*cos(1)*1.55741*(l1-10)/v1/sin(1);
        if(s>l2)
            s=l2;
        printf("%.0f\n",s);
    }
    return 0;
}        