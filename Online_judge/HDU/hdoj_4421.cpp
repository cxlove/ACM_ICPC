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
#define M 60005
#define N 605
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
#define MOD 1000000009
#define sqr(a) ((a)*(a))
using namespace std;
int pre[64*510];
int b[505][505],n;
void Init()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(int i=0;i<(n+10)*64;i++) pre[i]=i;
}
int find(int x)
{
    return pre[x]=(x==pre[x]?x:find(pre[x]));
}
void Union(int x,int y)
{
    int ra=find(x),rb=find(y);
    pre[ra]=pre[rb]=pre[x]=pre[y]=min(ra,rb);
}
bool slove()
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
            if(b[i][j] != b[j][i]) return 0;
        if(b[i][i] != 0) return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int m=n*32;
            if(i%2==1&&j%2==1)
            {
                for(int k=0;k<32;k++)
                {
                    if( ((  b[i][j]>>k ) & 1 )==0 )
                    {
                        int u=(i+1)*32+k,v=(j+1)*32+k;
                        if(find(u)==find(1)||find(v)==find(1)||find(u)==find(v+m)) return false;
                        Union(u,0);Union(v,0);
                        Union(u+m,1);Union(v+m,1);
                    }
                }
            }
            else if(i%2==0&&j%2==0)
            {
                for(int k=0;k<32;k++)
                {
                    if(((b[i][j]>>k)&1))
                    {
                        int u=(i+1)*32+k,v=(j+1)*32+k;
                        if(find(u)==find(0)||find(v)==find(0)||find(u)==find(v+m)) return false;
                        Union(u,1);Union(v,1);
                        Union(u+m,0);Union(v+m,0);
                    }
                }
            }
            else
            {
                for(int k=0;k<32;k++)
                {
                    int u=(i+1)*32+k,v=(j+1)*32+k;
                    if(((b[i][j]>>k)&1))
                    {
                        if(find(u)==find(v)) return false;
                        Union(u,v+m);Union(v,u+m);
                    }
                    else
                    {
                        if(find(u)==find(v+m)) return false;
                        Union(u,v);Union(u+m,v+m);
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        Init();
        puts(slove()?"YES":"NO");
    }
    return 0;
}


