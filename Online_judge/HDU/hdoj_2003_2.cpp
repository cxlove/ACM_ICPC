#include <stdio.h>
int main()
{
    double input,output;
    while( scanf("%lf",&input)!=EOF )
    {
    output = (input>=0) ? input : (input*(-1));
    printf("%.2f\n",output);
    }
    return 0;
}