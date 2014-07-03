#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INF 1000000000

typedef struct
{
    int num,c,d;
}DP;

int map[105][105];
DP a[25];
int dp[(1<<17)+1][25];

int main()
{
    int n,m,mon,T,i,x,j,k,p,s,y,z,h,ok;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&mon);
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                map[i][j]=INF;
            }
            map[i][i]=0;
        }
        for (i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            x--;y--;
            map[x][y]=min(map[x][y],z);
            map[y][x]=map[x][y];
        }
        for (k=0;k<n;k++)
        {
            for (i=0;i<n;i++)
            {
                for (j=0;j<n;j++)
                {
                    if (i==j || j==k || i==k) continue;
                    map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
                }
            }
        }
        scanf("%d",&h);
        ok=-1;
        for (i=0;i<h;i++)
        {
            scanf("%d%d%d",&a[i].num,&a[i].c,&a[i].d);
            a[i].num--;
            if (a[i].num==0) ok=i;
        }
        if (ok==-1)
        {
            a[h].num=0;
            a[h].c=0;
            a[h].d=0;
            ok=h;
            h++;
        }
        memset(dp,-1,sizeof(dp));
        if (mon-a[ok].d>=0) dp[(1<<ok)][ok]=a[ok].c-a[ok].d+mon;
        dp[0][ok]=mon;
        for (i=0;i<(1<<h);i++)
        {
            for (j=0;j<h;j++)
            {
                if (dp[i][j]==-1) continue;
                for (k=0;k<h;k++)
                {
                    if (k==j || (i & (1<<k))!=0) continue;
                    p=i | (1<<k);
                    if (dp[i][j]>=a[k].d+map[a[j].num][a[k].num])
                    {
                        dp[p][k]=max(dp[p][k],dp[i][j]+a[k].c-a[k].d-map[a[j].num][a[k].num]);
                    }
                }
            }
        }
        for (i=0;i<h;i++)
        {
            if (dp[(1<<h)-1][i]-map[a[i].num][0]>=0) break;
        }
        if (i<h) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
