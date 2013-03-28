/*
ID:cxlove
Prob:D Dinner Hall
Algorithm:greed 
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct Node
{
    int s,k;
    bool operator<(const Node n) const
    {
        return s!=n.s?s<n.s:k>n.k;
    }
}a[70000];
int n;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        int in=0,out=0;
        for(int i=0;i<n;i++)
        {
            int h,m,s;
            char str[100];
            scanf("%d:%d:%d %s",&h,&m,&s,str);
            a[i].s=h*3600+m*60+s;
            a[i].k=(str[0]=='E'?1:(str[0]=='X'?-1:'0'));
            if(a[i].k==1) in++;
            else if(a[i].k==-1) out++;
        }
        sort(a,a+n);
        int s=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(a[i].k==1) s++;
            else if(a[i].k==-1) s--;
            else
            {
                if(in==n/2) s--;
                else s++,in++;
            }
            ans=max(ans,s);
        }
        printf("%d\n",ans);
    }
    return 0;
}