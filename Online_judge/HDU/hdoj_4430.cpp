#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
#define N 200005
#define MOD 1000000007
#define LL long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
LL Bin(LL low,LL high,int r,LL n)
{
    if(low>high) return -1;
    LL mid=(low+high)/2;
    LL tmp=mid;
    for(int x=1;x<r;x++)
    {
        if(tmp>n/mid) return Bin(low,mid-1,r,n);
        tmp++;
        tmp*=mid;
    }
    if(tmp==n) return mid;
    if(tmp<n) return Bin(mid+1,high,r,n);
    if(tmp>n) return Bin(low,mid-1,r,n);
}
int main()
{
    LL n;
    while(scanf("%I64d",&n)!=EOF)
    {
        LL best=n-1,r=1,k=n-1;
        for(int i=2;i<45;i++)
        {
            LL tk=Bin(2,n,i,n),tr=i;
            if(tk!=-1&&tk*tr<best)
            {
                best=tk*tr;
                r=tr;
                k=tk;
            }
            tk=Bin(2,n-1,i,n-1),tr=i;
            if(tk!=-1&&tk*tr<best)
            {
                best=tk*tr;
                r=tr;
                k=tk;
            }
        }
        printf("%I64d %I64d\n",r,k);
    }
    return 0;
}