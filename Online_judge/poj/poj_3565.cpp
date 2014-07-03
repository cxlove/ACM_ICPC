#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int n;
struct node
{
    int x, y;
};
node ants[110], tree[110];
double map[110][110];
double lx[110],ly[110];
int sx[110],sy[110];
int match[110];

const double eps = 1e-5;
const double INF = 99999999.0;

int dfs(int a)
{
    sx[a]=1;
    for(int i=1;i<=n;i++)
    {
        if(sy[i]==0 && abs(lx[a]+ly[i]-map[a][i])<=eps)
        {
            sy[i]=1;
            if(match[i]==0 || dfs(match[i])==1)
            {
                match[i]=a;
                return 1;
            }
        }
    }
    return 0;
}

void km()
{
    for(int i=1;i<=n;i++)
    {
        lx[i]=INF;
        ly[i]=0;
        for(int j=1;j<=n;j++)
        {
            if(lx[i]>map[i][j])
                lx[i]=map[i][j];
        }
    }
    memset(match, 0, sizeof(match));
    for(int u=1;u<=n;u++)
    {
        while(1)
        {
            memset(sx, 0, sizeof(sx));
            memset(sy, 0, sizeof(sy));
            if(dfs(u))
                break;
            double dmin = INF;
            for(int i=1;i<=n;i++)
            {
                if(sx[i])
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(!sy[j])
                        {
                            dmin =(double) (map[i][j]-lx[i]-ly[j])<dmin?(map[i][j]-lx[i]-ly[j]):dmin;
                        }
                    }
                }
            }
            for(int i=1; i<=n;i++)
            {
                if(sx[i])
                    lx[i]+=dmin;
                if(sy[i])
                    ly[i]-=dmin;
            }
        }
    }
}

int main()
{

    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>ants[i].x>>ants[i].y;
        }
        for(int i=1;i<=n;i++)
        {
            cin>>tree[i].x>>tree[i].y;
        }
        memset(map, 0, sizeof(map));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                map[i][j]=sqrt(1.0*(tree[i].x-ants[j].x)*(tree[i].x-ants[j].x)+
                    (tree[i].y-ants[j].y)*(tree[i].y-ants[j].y));
            }
        }
        km();
        for(int i=1;i<=n;i++)
        {
            cout<<match[i]<<endl;
        }
    }
    return 0;
}
