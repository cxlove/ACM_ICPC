
#include <stdio.h>
#include <string.h>

#define N 105
#define M 100005
#define MAX(a, b) (a > b ? a : b)

int a[N], c[N], f[M];

void Complete(int cost, int weight, int m)
{
    for(int i = cost; i <= m; i++)
        f[i] = MAX(f[i], f[i - cost] + weight);
}

void Zero_One(int cost, int weight, int m)
{
    for(int i = m; i >= cost; i--)
        f[i] = MAX(f[i], f[i - cost] + weight);
}

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m), n + m)
    {
        for(int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        
        for(int i = 0; i < n; i++)
            scanf("%d", &c[i]);
        
        memset(f, 0, sizeof(f));
        
        for(int i = 0; i < n; i++)
        {
            int t = a[i] * c[i];
            if(t > m) Complete(a[i], a[i], m);
            else
            {
                int k = 1; 
                while(k < c[i])
                {
                    Zero_One(k * a[i], k * a[i], m);
                    c[i] -= k;
                    k *= 2;
                }
                Zero_One(c[i] * a[i], c[i] * a[i], m);
            }
        }
        int ans = 0;
        for(int i = 1; i <= m; i++)
        {
            if(f[i] == i) ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}