#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<queue>
#define inf 100000005
#define M 200005
#define N 405
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
#define sqr(a) ((a)*(a))
#define Key_value ch[ch[root][1]][0]
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
struct Point
{
    int x,y;
    bool operator<(const Point p)const
    {
        return x<p.x;
    }
}p[105],q[1005];
int n,m;
int cnt[105][105];
LL xmul(Point p,Point p1,Point p2)
{
    return (LL)(p1.x-p.x)*(p2.y-p.y)-(LL)(p2.x-p.x)*(p1.y-p.y);
}
int main()
{
    int cas=0;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        for(int i=0;i<m;i++) scanf("%d%d",&q[i].x,&q[i].y);
        mem(cnt,0);
        sort(p,p+n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=0;k<m;k++)
                {
                    if(q[k].x>=p[i].x&&q[k].x<=p[j].x&&xmul(p[i],p[j],q[k])<0)
                       cnt[i][j]++;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if((cnt[i][j]+cnt[j][k]-cnt[i][k])&1) ans++;
                }
            }
        }
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
