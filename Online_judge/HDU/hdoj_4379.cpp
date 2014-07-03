#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<iostream>
#include<map>
#include<math.h>
using namespace std;
#define INF 0x7fffffff
int main()
{
    int i,j,k;
    long long l,A,B,MOD;
    long long n;
    while(scanf("%I64d%I64d%I64d%I64d%I64d",&n,&l,&A,&B,&MOD)!=EOF)
    {
        A%=MOD;
        __int64 a=(A+B)%MOD;
        __int64 MM=l/2;
        __int64 MAX=0;
        __int64 MIN=l+1;
        __int64 s=0;
        for(i=1;i<=n;i++)
        {
            if(a<=MM)
            {
               s++;
               if(MAX<a)
               MAX=a;
            }
            else
            {
               if(MIN>a)
               MIN=a;
            }
            a+=A;
            if(a>=MOD)
            a-=MOD;
        }
        if(MIN+MAX<=l)
        s++;
        printf("%I64d\n",s);
    }
    return 0;
}