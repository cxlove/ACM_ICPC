#include <iostream>

#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
    int n,i;
    while(~scanf("%d",&n)){
        double a[n],sum=0,avr;
        for(i=0;i<n;i++)
            scanf("%lf",&a[i]);
        sort(a,a+n);
        for(i=1;i<n-1;i++)
            sum+=a[i];
        avr=sum/(n-2);
        printf("%.2lf\n",avr);
    }
    return 0;
}