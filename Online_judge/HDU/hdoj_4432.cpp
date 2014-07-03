#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#define LL long long
using namespace std;
int prime[40005],cnt=0,flag[40005];
void Prime()
{
    prime[cnt++]=1;
    for(int i=2;i<=40000;i++)
    {
        if(flag[i]) continue;
        prime[cnt++]=i;
        for(int j=2;i*j<=40000;j++) flag[i*j]=true;
    }
}
int fac[1000000],tot;
int n,k;
int ans;
int slove(int num)
{
    int ret=0;
    while(num)
    {
        int tmp=num%k;
        ret+=tmp*tmp;
        num/=k;
    }
    return ret;
}
void print(int num)
{
    int a[10000],cnt=0;
    while(num)
    {
        a[cnt++]=num%k;
        num/=k;
    }
    for(int i=cnt-1;i>=0;i--)
    {
        if(a[i]<10)
        printf("%d",a[i]);
        else printf("%c",(char)(a[i]+'A'-10));
    }
    printf("\n");
}
int main()
{
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        tot=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                fac[tot++]=i;
                if(i*i!=n)
                    fac[tot++]=n/i;
            }
        }
        ans=0;
        for(int i=0;i<tot;i++)
        {
            ans+=slove(fac[i]);
        }
        print(ans);
    }
    return 0;
}
