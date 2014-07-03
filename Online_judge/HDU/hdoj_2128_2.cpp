#include <iostream>
#include <queue>
#include <set>
#include <utility>
using namespace std;

typedef struct
{
    int x,y,step;
    pair<int,unsigned long long> status;
}position;

bool operator<(const position& a, const position& b)
{
    return a.step > b.step;
}

char map[10][10];
set< pair<int,unsigned long long> > s[10][10];
int r,c;
unsigned long long map2[8][8];
int dir[4][2] = {0,-1,0,1,1,0,-1,0};

int bfs(int startx, int starty)
{
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            s[i][j].clear();
    position begin;
    begin.x = startx;
    begin.y = starty;
    begin.step = 0;
    begin.status = pair<int,unsigned long long>(0,0);
    priority_queue<position> q;
    q.push(begin);
    while(!q.empty())
    {
        begin = q.top();
        q.pop();
        if(s[begin.x][begin.y].find(begin.status)!=s[begin.x][begin.y].end())
            continue;
        s[begin.x][begin.y].insert(begin.status);
        if(map[begin.x][begin.y]=='D')
            return begin.step;
        for(int i=0;i<4;i++)
        {
            position next = begin;
            next.x += dir[i][0];
            next.y += dir[i][1];
            next.step ++;
            if(next.x < 0 || next.y < 0 || next.x >= r || next.y >= c)
                continue;
            if(map[next.x][next.y]=='.'||map[next.x][next.y]=='S'||map[next.x][next.y]=='D')
            {
                q.push(next);
            }
            else if(map[next.x][next.y]>='0'&&map[next.x][next.y]<='9')
            {
                if((next.status.second & map2[next.x][next.y]) == 0)
                {
                    next.status.first += map[next.x][next.y] - '0';
                    next.status.second |= map2[next.x][next.y];
                }
                q.push(next);
            }
            else if(map[next.x][next.y]=='X')
            {
                if((next.status.second & map2[next.x][next.y]) == 0)
                {
                    if(next.status.first == 0)
                        continue;
                    next.status.first --;
                    next.status.second |= map2[next.x][next.y];
                    next.step++;
                }
                q.push(next);
            }
        }
    }
    return -1;
}

void pre()
{
    unsigned long long temp = 1;
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            map2[i][j] = temp;
            temp <<= 1;
        }
    }
}

int main()
{
    pre();
    while(cin >> r >> c && r+c)
    {
        int startx,starty;
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
            {
                cin >> map[i][j];
                if(map[i][j] == 'S')
                {
                    startx = i;
                    starty = j;
                }
            }
        int k = bfs(startx,starty);
        cout << k << endl;
    }
}