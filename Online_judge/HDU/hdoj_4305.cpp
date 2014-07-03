#include <cstdio>
#include <cstring>
#include <cmath>
const int MAXN = 305;
const int MOD = 10007;

int n, r;
int x[MAXN], y[MAXN];
int g[MAXN][MAXN];
bool visit[MAXN];

inline int dist(int x0, int y0, int x1, int y1)
{
    return (x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1);
}

inline int min(int x, int y)
{
    return x < y ? x : y;
}

inline int max(int x, int y)
{
    return x > y ? x : y;
}

inline int abs(int x)
{
    return x >= 0 ? x : -x;
}

inline int gcd(int a,int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a%b);
}

inline void swap(int &x, int &y)
{
    int t;
    t = x;
    x = y;
    y = t;
}

void dfs(int x)
{
    if(!visit[x])
    {
        visit[x] = true;
        for(int i=0; i<n; ++i)
        {
            if(g[x][i])
            {
                dfs(i);
            }
        }
    }
}

int gauss(int r, int c)
{
    bool flag = false;
    int coe = 1;
    int i=0, t=0;
    for(int j=0; j<c; ++j)
    {
        int index = i;
        for(int k=i; k<r; ++k)
        {
            if(g[k][j] > 0)
            {
                index = k;
                break;
            }
        }
        if(g[index][j])
        {
            if(index != i)
            {
                for(int k=j; k<c; ++k)
                {
                    swap(g[i][k], g[index][k]);
                }
                flag = !flag;
            }
            for(int k=i+1; k<r; ++k)
            {
                if(g[k][j])
                {
                    coe = (coe * g[i][j]) % MOD;
                    ++ t;
                    for(int l=c-1; l>=j; --l)
                    {
                        g[k][l] = (g[k][l] * g[i][j] - g[i][l] * g[k][j]) % MOD;
                        if(g[k][l] < 0)
                        {
                            g[k][l] += MOD;
                        }
                    }
                }
            }
            ++ i;
        }
    }
    for(i=1;i<MOD;++i)
    {
        if((coe * i) % MOD == 1)
        {
            break;
        }
    }
    int result = i;
    for(i=0; i<r; ++i)
    {
        result = (result * g[i][i]) % MOD;
    }
    if(flag)
    {
        result = MOD - flag;
    }
    return result;
}

int main()
{
    int t, r;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d",&n,&r);
        r *= r;
        for(int i=0; i<n; ++i)
        {
            scanf("%d%d",&x[i],&y[i]);
        }
        memset(g, 0, sizeof(g));
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                if(dist(x[i], y[i], x[j], y[j]) <= r)
                {
                    g[i][j] = g[j][i] = 1;
                    for(int k=0; k<n; ++k)
                    {
                        if(k!=i && k!=j)
                        {
                            if(x[k] > min(x[i], x[j]) && x[k] < max(x[i], x[j]) && (x[k] - x[i]) * (y[j] - y[i]) == (x[j] - x[i]) * (y[k] - y[i]))
                            {
                                g[i][j] = g[j][i] = 0;
                                break;
                            }
                        }
                    }
                }
            }
        }
        memset(visit, false, sizeof(visit));
        dfs(0);
        bool flag = true;
        for(int i=0; i<n; ++i)
        {
            if(!visit[i])
            {
                flag = false;
                break;
            }
        }
        if(!flag)
        {
            printf("-1\n");
            continue;
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=i+1; j<n; ++j)
            {
                if(g[i][j])
                {
                    ++ g[i][i];
                    ++ g[j][j];
                    g[i][j] = g[j][i] = MOD - 1;
                }
            }
        }
        printf("%d\n", gauss(n - 1, n - 1));
    }
    return 0;
}
