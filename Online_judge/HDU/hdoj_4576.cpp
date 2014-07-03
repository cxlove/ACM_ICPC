
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
using namespace std;
double dp[2][220];
int main()
{
    int n,m,l,r;
    while(scanf("%d%d%d%d",&n,&m,&l,&r) == 4)
    {
        if(n == 0 && m == 0 && l == 0 && r == 0)break;
        dp[0][0] = 1;
        for(int i = 1;i < n;i++)dp[0][i] = 0;
        int now = 0;
        while(m--)
        {
            int v;
            scanf("%d",&v);
            for(int i = 0;i < n;i++)
                dp[now^1][i] = 0.5*dp[now][(i-v+n)%n] + 0.5*dp[now][(i+v)%n];
            now ^= 1;
        }
        double ans = 0;
        for(int i = l-1;i < r;i++)
            ans += dp[now][i];
        printf("%.4lf\n",ans);
    }
    return 0;
}