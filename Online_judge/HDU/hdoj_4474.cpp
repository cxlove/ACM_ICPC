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
#define inf 100000005
#define M 200005
#define N 100005
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
#define Key_value ch[ch[root][1]][0]
//#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int flag[10];
int n,k;
int vis[10005];
void bfs()
{
    mem(vis,0);
    queue<pair<string,int> >que;
    que.push(mp("",0));
    while(!que.empty())
    {
        pair<string,int>u=que.front();
        que.pop();
        for(int i=0;i<10;i++)
        {
            if(i==0&&u.second==0) continue;
            if(flag[i]) continue;
            pair<string,int>v=u;
            v.first+=(char)(i+'0');
            v.second=(v.second*10+i)%n;
            if(v.second == 0) {cout<<v.first<<endl;return ;}
            if(vis[v.second]==0)
            {
                vis[v.second]=1;
                que.push(v);
            }
        }
    }
    printf("-1\n");
}
int main()
{
    int cas=0;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        mem(flag,0);
        for(int i=0;i<k;i++)
        {
            int m;
            scanf("%d",&m);
            flag[m]=1;
        }
        printf("Case %d: ",++cas);
        if(k==0){printf("%d\n",n);continue;}
        bfs();
    }
    return 0;
}
