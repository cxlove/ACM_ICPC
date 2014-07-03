#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
struct NODE
{
    int x,y;
}a[50005];
int s[50005];
int p = 0;
int top;

int cmp(const struct NODE &a, const struct NODE &b ){
    if( a.y < b.y )
       return 1;
    else
       if( a.y == b.y ){
          if( a.x < b.x )
             return 1;
          else
             return 0;
        }
    else
        return 0;
}

int dir(int now,int p1,int p2)
{
   return ((a[p1].x - a[now].x)*(a[p2].y - a[now].y) - (a[p2].x - a[now].x)*(a[p1].y - a[now].y));
}

int dis(int i,int j)
{
    return (a[i].x - a[j].x)*(a[i].x - a[j].x) + (a[i].y - a[j].y)*(a[i].y - a[j].y);
}

void create()
{
    bool used[50005];
    memset(used,false,sizeof(used));
    s[++p] = 1;
    s[++p] = 2;
    for(int i = 3; i <= n; ++i)
    {
        while(p > 1 && dir(s[p - 1],s[p],i) <= 0)
        {
            used[s[p]] = false;
            p--;
        }
        s[++p] = i;
        used[s[p]] = true;
    }
    top = p;

    int i = n - 1;
    while(used[i] == true) i--;
    s[++p] = i;
    for(i = i - 1; i >= 1; i--)
    {
        if(!used[i])
        {
            while(p > top && dir(s[p - 1],s[p],i) <= 0)
                p--;
            s[++p] = i;
        }
    }
}

void RC()
{
    int x = 1;// 对点
    for(int i = 1; i < p; ++i)
    {
        while(dir(s[i],s[i + 1],s[x + 1]) < dir(s[i],s[i + 1],s[x + 2]))
        {
            x++;
            if(x == p) x = 1;
        }
        m = max(m,max(dis(s[i],s[x + 1]),dis(s[i + 1],s[x + 2])));
    }


}

int main()
{

    scanf("%d", &n);
    m = 0;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    if(n == 2)
    {
        printf("%d\n",dis(1,2));
    }else
    {
        sort(a + 1,a + 1 + n,cmp);
        create();
        RC();
        printf("%d\n",m);
    }
    return 0;
}

