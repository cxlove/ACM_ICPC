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
int pre[N],r[N];
int p1,p2,p;
bool vis[N];
int dp[N][N/2];
int cnt;   //最后分为几个集合
int a[N][2];  //a[i][0],a[i][1]分别表示把第i个集合分成的两个部分
vector<int> b[N][2];
int find(int x)
{
    if(x!=pre[x])
    {
        int f=pre[x];
        pre[x]=find(pre[x]);
        r[x]=r[x]^r[f];
    }
    return pre[x];
}
void Init()
{
    for(int i=1;i<=p1+p2;i++) pre[i]=i,r[i]=0;
    mem(vis,false);
    cnt=1;
    mem(a,0);
    for(int i=0;i<N;i++)
    {
        b[i][0].clear();
        b[i][1].clear();
    }
}
int main()
{
    while(scanf("%d%d%d",&p,&p1,&p2)!=EOF&&p+p1+p2)
    {
        Init();
        while(p--)
        {
            int u,v;char str[10];
            scanf("%d%d%s",&u,&v,str);
            int k=(str[0]=='n');
            int ra=find(u),rb=find(v);
            if(ra!=rb)
            {
                pre[ra]=rb;
                r[ra]=r[u]^r[v]^k;
            }
        }
        for(int i=1;i<=p1+p2;i++)
        {
            if(!vis[i])
            {
                int f=find(i);
                for(int j=i;j<=p1+p2;j++)
                {
                    if(find(j)==f)
                    {
                        vis[j]=true;
                        b[cnt][r[j]].pb(j);
                        a[cnt][r[j]]++;
                    }
                }
                cnt++;
            }
        }
        mem(dp,0);
        dp[0][0]=1;
        for(int i=1;i<cnt;i++)
        {
            for(int j=p1;j>=0;j--)
            {
                    if(j-a[i][0]>=0)
                        dp[i][j]+=dp[i-1][j-a[i][0]];
                    if(j-a[i][1]>=0)
                        dp[i][j]+=dp[i-1][j-a[i][1]];
            }
        }
        if(dp[cnt-1][p1]!=1){printf("no\n");continue;}
        else
        {
            vector<int>ans;ans.clear();
            for(int i=cnt-1;i>=1;i--)
            {
                if(p1-a[i][0]>=0&&p2-a[i][1]>=0&&dp[i-1][p1-a[i][0]]==1)
                {
                    for(int j=0;j<b[i][0].size();j++)
                    {
                        ans.pb(b[i][0][j]);
                    }
                    p1-=a[i][0];p2-=a[i][1];
                }
                else if(p1-a[i][1]>=0&&p2-a[i][0]>=0&&dp[i-1][p1-a[i][1]]==1)
                {
                    for(int j=0;j<b[i][1].size();j++)
                    {
                        ans.pb(b[i][1][j]);
                    }
                    p1-=a[i][1];p2-=a[i][0];
                }
            }
            sort(ans.begin(),ans.end());
            for(int i=0;i<ans.size();i++) printf("%d\n",ans[i]);
            printf("end\n");
        }
    }
    return 0;
}
