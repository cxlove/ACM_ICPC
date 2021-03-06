#include <cstdio>
using namespace std;
const int max=807020306;
const double eps=1e-6;
int main()
{
    int t=0;
    scanf("%d",&t);
    double y=0,l=0,r=100,m=0;
    while (t--) {
        scanf("%lf",&y);
        l=0,r=100;
        if (y<6||y>max) {
            printf("No solution!\n");
        }
        else {
            while (r-l>eps) {
                m=(l+r)/2;
                if (y-(8*m*m*m*m+7*m*m*m+2*m*m+3*m+6)>=-eps) {
                    l=m;
                }
                else {
                    r=m;
                }
            }
            printf("%.4f\n",m);
        }
    }
    return 0;
}
