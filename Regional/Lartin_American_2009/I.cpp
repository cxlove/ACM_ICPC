/*
ID:cxlove
Prob:I Isosceles Triangles
Algorithm:burte force
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include<map>
#define LL long long
#define sqr(a) ((LL)(a)*(a))
using namespace std;
struct Point
{
    int x,y;
}p[1000];
int n;
LL D(Point p1,Point p2)
{
    return sqr(p1.x-p2.x)+sqr(p1.y-p2.y);
}
LL c[1000];
int cnt;
int main()
{
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
        }
        LL ans=0;
        for(int i=0;i<n;i++)
        {
            cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                c[cnt++]=D(p[i],p[j]);
            }
            sort(c,c+cnt);
            int s=1;
            for(int i=1;i<cnt;i++)
            {
                if(c[i]!=c[i-1])
                {
                    ans+=(LL)s*(s-1)/2;
                    s=1;
                }
                else s++;
            }
            ans+=(LL)s*(s-1)/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
