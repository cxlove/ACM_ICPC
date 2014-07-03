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
#define inf 1<<30
#define M 60005
#define N 10005
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
#define sqr(a) ((a)*(a))
using namespace std;
struct Point
{
    int x,y;
}p[1005];
int pre[1005],flag[1005];
char str[10];
int dist(Point p1,Point p2)
{
    return sqr(p1.x-p2.x)+sqr(p1.y-p2.y);
}
int find(int x)
{
    return pre[x]=(x==pre[x]?x:find(pre[x]));
}
int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    for(int i=1;i<=n;i++)
    {
        pre[i]=i;
        flag[i]=false;
    }
    while(scanf("%s",str)!=EOF)
    {
        int u,v;
        if(str[0]=='O')
        {
            scanf("%d",&u);
            if(flag[u]) continue;
            flag[u]=true;
            for(int i=1;i<=n;i++)
            {
                if(flag[i]&&i!=u&&d*d>=dist(p[i],p[u]))
                {
                    int ra=find(u),rb=find(i);
                    if(ra!=rb) pre[ra]=rb;
                }
            }
        }
        else
        {
            scanf("%d%d",&u,&v);
            if(!flag[u]||!flag[v]) printf("FAIL\n");
            else
            {
                int ru=find(u),rv=find(v);
                puts(ru==rv?"SUCCESS":"FAIL");
            }
        }
    }
    return 0;
}





