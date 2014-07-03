#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<math.h>
using namespace std;
#define LL __int64
#define MIN(a,b) a < b ? a : b
#define MAX(a,b) a > b ? a : b
struct T
{
    int sec1;
    int sec2;
}stu[500010];
 
int cmp(T a,T b)
{
    if(a.sec1 == b.sec1)
    {
        return a.sec2<b.sec2;
    }
    else
    {
        return a.sec1<b.sec1;
    }
}
 
int main()
{
    int n,a,b,c,d;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d:%d %d:%d",&a,&b,&c,&d);
            stu[i].sec1 = a*60+b;
            stu[i].sec2 = c*60+d;
        }
        sort(stu,stu+n,cmp);
        int from,to;
        int ans=0;
        from=stu[0].sec1;
        to = stu[0].sec2;
        for(int i=1; i<n;i++)
        {
            if(stu[i].sec1<=to)
            {
                if(stu[i].sec2>to)
                {
                    to = stu[i].sec2;
                }
            }
            else
            {
                ans+=to-from;
                to=stu[i].sec2;
                from=stu[i].sec1;
            }
        }
        ans+=to-from;
        printf("%d\n",24*60-ans);
    }
    return 0;
}