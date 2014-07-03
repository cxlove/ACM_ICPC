#include<stdio.h>
#include<string.h>
int main()
{
    int n, m, i, mul, a[9];
    while(scanf("%d", &n))
    {
        if(n == 0)
            break;
        m = n;
        memset(a, 0, sizeof(a));
        for(i=0; n; i++, n/=10)
        {
            a[i] = n % 10;
            if(a[i]>=3)
                a[i]--;
            if(a[i] >=8)
                a[i]--;

        }
        mul = a[--i];
        for(; i>=1; i--)
            mul = mul*8 + a[i-1];
        printf("%d: %d\n", m, mul);
    }
    return 0;
}