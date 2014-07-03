#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int k,ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&k);
            ans+=k*k;
        }
        printf("%d\n",ans);
    }
    return 0;
}