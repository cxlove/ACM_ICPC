#include <cstdio>
#include <stack>
#include <cstring>
#include <iostream>
using namespace std;

const int NN=250;
const int MM=100000;
const int INF=0x3f3f3f3f;

int n,m,en,head[NN];
struct Edge{
    int v,w,next;
    Edge() {}
    Edge(int _v,int _w,int _next): v(_v),w(_w),next(_next) {}
} e[MM];
void add(int u,int v,int d)
{
    //printf("EDGE %d %d %d\n",u,v,d);
    e[en]=Edge(v,d,head[u]);
    head[u]=en++;
}

int cou[NN],dis[NN];
bool inq[NN];
bool spfa()
{
    stack<int> q;
    for (int i=0; i<=n; i++)
    {
        dis[i]=0;
        cou[i]=0;
        q.push(i);
        inq[i]=1;
    }

    int u,v;
    while (!q.empty())
    {
        u=q.top(); q.pop();
        inq[u]=0;
        for (int i=head[u]; i!=-1; i=e[i].next)
        {
            int v=e[i].v;
            if (dis[v]>dis[u]+e[i].w)
            {
                dis[v]=dis[u]+e[i].w;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v]=1;
                }
                if (++cou[v]>n) return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int s,k,d;
    char ope[8];
    while (scanf("%d",&n)!=EOF && n)
    {
        en=0;
        memset(head,-1,sizeof(head));

        scanf("%d",&m);
        while (m--)
        {
            scanf("%d%d%s%d",&s,&k,&ope,&d);
            if (ope[0]=='g')
            {
                add(s+k,s-1,-1-d);
            }
            else
            {
                add(s-1,s+k,d-1);
            }
        }
        if (spfa()) puts("lamentable kingdom");
        else        puts("successful conspiracy");
    }
    return 0;
}
