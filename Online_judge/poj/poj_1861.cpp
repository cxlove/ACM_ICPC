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
#define mem(a,b) memset(a,b,sizeof(a))
#define LL long long
#define lson step<<1
#define rson step<<1|1
#define MOD 1000000009
#define sqr(a) ((a)*(a))
using namespace std;
struct Node
{
    int u,v,w;
    bool operator<(const Node n)const
    {
        return w<n.w;
    }
}a[15005];
int n,m;
int pre[1005];
int find(int x)
{
    return pre[x]=(x==pre[x]?x:find(pre[x]));
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++) pre[i]=i;
        for(int i=0;i<m;i++) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
        sort(a,a+m);
        int ans=0,cnt=0;
        vector<int>v;v.clear();
        for(int i=0;i<m;i++)
        {
            int ra=find(a[i].u),rb=find(a[i].v);
            if(ra!=rb)
            {
                ans=max(ans,a[i].w);
                cnt++;
                pre[ra]=rb;
                v.pb(i);
            }
        }
        printf("%d\n%d\n",ans,cnt);
        for(int i=0;i<v.size();i++)
        {
            printf("%d %d\n",a[v[i]].u,a[v[i]].v);
        }
    }
    return 0;
}




