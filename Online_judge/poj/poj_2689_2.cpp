#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 1000000+10
#define MAXN 1000000
#define PRIME 80000//开始把这个一不小心开小了，就RE了。。
#define PRIMETEMP 100000

using namespace std;

bool isprime[MAXN+10];
bool isprimetemp[MAXN+10];
long long prime[PRIME+10];
long long primetemp[PRIMETEMP+10];
long long top;
long long total;

void init(void)
{
    long long i,j;
    for(i=2;i<=MAXN;i++)
    {
        if(!isprime[i])    prime[top++]=i;
        for(j=0;j<top&&i*prime[j]<=MAXN;j++)
        {
            isprime[i*prime[j]]=true;
            if(i%prime[j]==0)    break;
        }
    }
    top--;
    isprime[1]=1;//把1，0真正的含义搞反了，导致这里以及后面悲剧
}

void getprime(long long a,long long b)
{
    memset(isprimetemp,0,sizeof(isprimetemp));
    memset(primetemp,0,sizeof(primetemp));
    long long i,k;
    total=0;
    if(b<=prime[top])
    {
        for(i=a;i<=b;i++)
        {
            if(!isprime[i])//这里别忘了是否定呀
            {
                primetemp[total++]=i;
            }
        }
        total--;
        return ;
    }
    for(i=0;i<=b-a;i++)
        isprimetemp[i]=1;
    for(i=0;prime[i]*prime[i]<=b&&i<=top;i++)
    {
        k=a/prime[i];
        if(k*prime[i]<a)k++;
        if(k<=1)k++;
        while(k*prime[i]<=b)
        {
            isprimetemp[k*prime[i]-a]=0;
            k++;
        }
    }
    for(i=0;i<=b-a;i++)
    {
        if(isprimetemp[i])
            primetemp[total++]=i+a;
    }
    total--;
}

int main(void)
{
    init();
    long long a,b;
    while(scanf("%lld %lld",&a,&b)==2)
    {
        getprime(a,b);
        long long i;
        if(total<1)//一开始写成<=，打2，3的时候居然说没有，汗。。
            puts("There are no adjacent primes.");
        else 
        {
            long long cl,cr,dl,dr;
            long long c=INF,d=0;
            for(i=1;i<=total;i++)
            {
                if(primetemp[i]-primetemp[i-1]>d)
                {
                    dl=primetemp[i-1];
                    dr=primetemp[i];
                    d=primetemp[i]-primetemp[i-1];
                }
                if(primetemp[i]-primetemp[i-1]<c)
                {
                    cl=primetemp[i-1];
                    cr=primetemp[i];
                    c=primetemp[i]-primetemp[i-1];
                }
            }
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",cl,cr,dl,dr);
        }
    }
    return 0;
}