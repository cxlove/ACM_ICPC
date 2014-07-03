#include <iostream>
#include <cmath>
#include <cstdio>
#define MAX 100000
#define mmin 1e-9
using namespace std;
int main()
{
    double a;
    int l;
    while(cin >> a >> l)
    {
        int n = 1,d = 1,cn = n,cd = d;
        double cmin = MAX;
        while(n <= l && d <= l)
        {
            double cf = fabs(a - (double)n / d);
            if(cf < mmin)
            {
                cd = d;
                cn = n;
                break;
            }
            if(cf < cmin)
            {
                cd = d;
                cn = n;
                cmin = cf;
            }
            if((double)n / d > a)  d++;
            else    n ++;
        }
        printf("%d %d\n",cn,cd);
    }
    return 0;
}

