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
using namespace std;
struct Point
{
    double x,y;
}p[105];
struct Node
{
    int u,v;
    double d;
    bool operator<(const Node n1)const
    {
        return d<n1.d;
    }
    Node(){}
    Node(int _u,int _v,double _d):u(_u),v(_v),d(_d){}
}e[10005];
int pre[105];
double dist(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
int find(int x)
{
    return pre[x]=(x==pre[x]?x:find(pre[x]));
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                e[cnt++]=Node(i,j,dist(p[i],p[j]));
            }
        }
        sort(e,e+cnt);
        for(int i=0;i<n;i++) pre[i]=i;
        double ans=0;
        for(int i=0;i<cnt;i++)
        {
            int ru=find(e[i].u),rv=find(e[i].v);
            if(ru!=rv)
            {
                pre[ru]=rv;
                ans+=e[i].d;
            }
        }
        printf("%.2f\n",ans);
    }
    return 0;
}







