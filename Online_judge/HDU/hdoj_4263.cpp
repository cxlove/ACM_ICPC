#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define blue 0
#define red 1
using namespace std;

const int NN=1100;
const int MM=11000000;

int n,m,k;
struct Edge{
    int u,v,color;
    Edge() {}
    Edge(int _u,int _v,int _color): u(_u),v(_v),color(_color) {}
} e[MM];

int blue_first(const Edge a,const Edge b)
{
    return (a.color<b.color);
}

int red_first(const Edge a,const Edge b)
{
    return (b.color<a.color);
}

int p[NN];
int find(int x)
{
    if (p[x]!=x) p[x]=find(p[x]);
    return p[x];
}

int main()
{
    int i,x,y,u,v,cnt,r_edge,b_edge;
    char st[4];

    while (scanf("%d%d%d",&n,&m,&k),n|m|k)
    {
        for (i=0; i<m; i++)
        {
            scanf("%s%d%d",st,&u,&v);
            if (st[0]=='B') e[i]=Edge(u,v,0);
            if (st[0]=='R') e[i]=Edge(v,u,1);
        }
        //blue_first
        sort(e,e+m,blue_first);
        for (i=1; i<=n; i++) p[i]=i;
        cnt=1; b_edge=0;
        for (i=0; i<m && cnt<n; i++)
        {
            x=find(e[i].u);
            y=find(e[i].v);
            if (x==y) continue;
            p[x]=y;
            if (e[i].color==blue) b_edge++;
            cnt++;
        }
        if (b_edge<k) { puts("0"); continue; }
        //red_first
        sort(e,e+m,red_first);
        for (i=1; i<=n; i++) p[i]=i;
        cnt=1; b_edge=0;
        for (i=0; i<m && cnt<n; i++)
        {
            x=find(e[i].u);
            y=find(e[i].v);
            if (x==y) continue;
            if (e[i].color==blue) b_edge++;
            cnt++;
        }
        if (b_edge>k) { puts("0"); continue; }

        puts("1");
    }
    return 0;
}
