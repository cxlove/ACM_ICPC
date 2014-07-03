#include <iostream>
#include <cmath>
#include <cstdio>
#define MAX 1000000
#define mmin 1e-9
using namespace std;
int main()
{
    double a;
    int l;
    while(scanf("%lf%d",&a,&l)!=EOF)
    {
        int fz = 1,fm = 1,cfz = fz,cfm = fm;
        double cmin = MAX;
        while(fz <= l && fm <= l)
        {
            double c = fabs(a - (double)fz / fm);
            if(c < cmin)
            {
                cfm = fm;
                cfz = fz;
                cmin = c;
            }
            if((double)fz / fm > a)  fm++;
            else    fz ++;
        }
        printf("%d %d\n",cfz,cfm);
    }
    return 0;
}

