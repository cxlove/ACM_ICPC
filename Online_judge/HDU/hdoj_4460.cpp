#include <cstdio>
#include <queue>
#include <map>
#include <cstring>
#include <iostream>
using namespace std;

const int NN=1100;
const int MM=1000000;
const int INF=0x3f3f3f3f;

map<string,int> mp;
int n,m,en,head[NN];
struct Edge{
    int v,next;
} e[MM];
void add(int u,int v)
{
    e[en].v=v; e[en].next=head[u];
    head[u]=en++;
    e[en].v=u; e[en].next=head[v];
    head[v]=en++;
}

int inq[NN],dis[NN];
int bfs(int S)
{
    int ret=0;
    memset(inq,0,sizeof(inq));
    memset(dis,0x3f,sizeof(dis));
    dis[S]=0;

    queue<int> q;
    q.push(S);
    inq[S]=1;
    while (!q.empty())
    {
        int u=q.front(); q.pop();
        for (int i=head[u]; i!=-1; i=e[i].next)
        {
            int v=e[i].v;
            if (dis[v]>dis[u]+1&&!inq[v])
            {
                dis[v]=dis[u]+1;
                if (dis[v]>ret) ret=dis[v];

                    inq[v]=1;
                    q.push(v);

            }
        }
    }
    for(int i=1;i<=n;i++) if(!inq[i]) return -1;
    return ret;
}

int main()
{
    while (scanf("%d",&n)!=EOF&&n)
    {
        mp.clear();
        en=0;
        memset(head,-1,sizeof(head));

        for (int i=1; i<=n; i++)
        {
            char s[105];
            scanf("%s",s);
            string name(s);
            mp[name]=i;
        }
        scanf("%d",&m);
        while (m--)
        {
            char s[105],s2[105];
            scanf("%s%s",s,s2);
            string nam1(s);
            string nam2(s2);
            int u=mp[nam1];
            int v=mp[nam2];
            add(u,v);
        }

        int ans=-1;
        for (int i=1; i<=n; i++)
        {
            int tmp=bfs(i);
            ans=max(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}
