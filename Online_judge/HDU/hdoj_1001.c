#include<stdio.h>
int main()
{
    long n,result;
    while(scanf("%ld",&n)!=EOF)
    {
        result=n%2? (n+1)/2*n: n/2*(n+1);

        printf("%ld\n\n",result);
    }
    return 0;
}
        