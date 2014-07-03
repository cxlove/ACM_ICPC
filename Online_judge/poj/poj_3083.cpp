#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <algorithm>
#include <cstdio>
#include <climits>
#define H 1000000007
#define MOD 1217767
using namespace std;
struct Node{
    int x,y,step;
}s,e;
int n,m,way[4][2]={-1,0,0,1,1,0,0,-1};
char str[50][50];
int bfs(){
    s.step=1;
    queue<Node>que;
    que.push(s);
    bool vis[50][50];
    memset(vis,false,sizeof(vis));
    vis[s.x][s.y]=1;
    while(!que.empty()){
        Node u=que.front(),v;
        que.pop();
        for(int i=0;i<4;i++){
            v=u;
            v.x+=way[i][0];
            v.y+=way[i][1];
            v.step++;
            if(vis[v.x][v.y]==false&&str[v.x][v.y]!='#'){
                vis[v.x][v.y]=true;
                que.push(v);
                if(v.x==e.x&&v.y==e.y)
                    return v.step;
            }
        }
    }
    return -1;
}
int Left(){
    int dir;
    for(int i=0;i<4;i++){
        int x=s.x+way[i][0];
        int y=s.y+way[i][1];
        if(str[x][y]!='#')
            dir=i;
    }
    int cnt=1;
    Node now=s;
    while(now.x!=e.x||now.y!=e.y){
        int x=now.x+way[dir][0],y=now.y+way[dir][1];
        if(str[x][y]=='#'){
            dir=(dir+1)%4;
        }
        else{
            int xx=x+way[(dir+3)%4][0],yy=y+way[(dir+3)%4][1];
            if(str[xx][yy]!='#')
                dir=(dir+3)%4;
            cnt++;
            now.x=x;now.y=y;
        }
    }

    return cnt;
}
int Right(){
    int dir;
    for(int i=0;i<4;i++){
        int x=s.x+way[i][0];
        int y=s.y+way[i][1];
        if(str[x][y]!='#')
            dir=i;
    }
    int cnt=1;
    Node now=s;
    while(now.x!=e.x||now.y!=e.y){
        int x=now.x+way[dir][0],y=now.y+way[dir][1];
        if(str[x][y]=='#'){
            dir=(dir+3)%4;
        }
        else{
            int xx=x+way[(dir+1)%4][0],yy=y+way[(dir+1)%4][1];
            if(str[xx][yy]!='#')
                dir=(dir+1)%4;
            cnt++;
            now.x=x;now.y=y;
        }
    }
    return cnt;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        memset(str,'#',sizeof(str));
        scanf("%d%d",&m,&n);
        for(int i=1;i<=n;i++){
            scanf("%s",str[i]+1);
            for(int j=1;j<=m;j++)
                if(str[i][j]=='S') s.x=i,s.y=j;
                else if(str[i][j]=='E') e.x=i,e.y=j;
        }
        printf("%d %d %d\n",Left(),Right(),bfs());
    }
    return 0;
}