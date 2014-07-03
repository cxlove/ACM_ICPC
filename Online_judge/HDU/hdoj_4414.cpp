#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 52;
const int move[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
char map[maxn][maxn];
int n;

void read()
{
    for(int i=0;i<n;i++)
    {
        scanf("%s",map[i]);
    }
    return;
}

bool judge(int x,int y)
{
    if(x >= 0 && y >= 0 && x < n && y < n && map[x][y] == '#')
    {
        return true;
    }
    return false;
}

bool check(int x,int y)
{
    int i = 1;
    for(;;i++)
    {
        bool flag = true;
        for(int j=0;j<4;j++)
        {
            int tx = x + i * move[j][0];
            int ty = y + i * move[j][1];
            if(judge(tx , ty) == false)
            {
                flag = false;
            }
            else
            {
                int pos = (j + 1) % 4;
                int xx = tx + move[pos][0];
                int yy = ty + move[pos][1];
                if(judge(xx,yy)) return false;

                pos = (j + 3) % 4;
                xx = tx + move[pos][0];
                yy = ty + move[pos][1];
                if(judge(xx,yy)) return false;
            }
        }
        if(flag == false) break;
    }
    if(i == 1) return false;
    for(int j=0;j<4;j++)
    {
        int tx = x + i * move[j][0];
        int ty = y + i * move[j][1];
        if(judge(tx , ty)) return false;
    }
    return true;
}

void solve()
{
    int cnt = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(map[i][j] == '#')
            {
                if(check(i,j)) cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return;
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
        read();
        solve();
    }
    return 0;
}