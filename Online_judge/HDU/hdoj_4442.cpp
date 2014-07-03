#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define LL long long
#define MOD 31536000
using namespace std;
struct Node
{
    LL a,b;
    bool operator<(const Node n)const
    {
        return b*n.a>n.b*a;
    }
}p[100005];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%I64d%I64d",&p[i].a,&p[i].b);
        }
        sort(p,p+n);
        LL ans=0;
        for(int i=0;i<n;i++)
        {
            ans=(ans+p[i].a+ans*p[i].b)%MOD;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
