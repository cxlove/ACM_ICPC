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
#define M 2005
#define N 130
#define maxn 300005
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1599997
#define sqr(a) ((a)*(a)*(a))
#define Key_value ch[ch[root][1]][0]
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int hash[MOD],cnt[MOD];
int n;
void insert(int num)
{
    int tmp=((num%MOD)+MOD)%MOD;
    while(hash[tmp]!=inf&&hash[tmp]!=num) tmp=(tmp+1)%MOD;
    hash[tmp]=num;cnt[tmp]++;
}
int find(int num)
{
    int tmp=((num%MOD)+MOD)%MOD;
    while(hash[tmp]!=inf&&hash[tmp]!=num) tmp=(tmp+1)%MOD;
    if(hash[tmp]==inf) return 0;
    else return cnt[tmp];
}
int main()
{
    int a1,a2,a3,a4,a5;
    while(scanf("%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5)!=EOF)
    {
        for(int i=0;i<MOD;i++) hash[i]=inf,cnt[i]=0;
        for(int i=-50;i<=50;i++)
        {
            for(int j=-50;j<=50;j++)
            {
                for(int k=-50;k<=50;k++)
                {
                    if(i==0||j==0||k==0) continue;
                    insert(a1*sqr(i)+a2*sqr(j)+a3*sqr(k));
                }
            }
        }
        int ans=0;
        for(int i=-50;i<=50;i++)
        {
            for(int j=-50;j<=50;j++)
            {
                if(!i||!j) continue;
                ans+=find(-(a4*sqr(i)+a5*sqr(j)));
            }
        }
        printf("%d\n",ans);
    }return 0;
}

