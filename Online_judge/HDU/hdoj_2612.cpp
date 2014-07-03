#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#define inf 1<<30
using namespace std;
struct Node{
    int x,y,step;
}s[2],u,v;
int n,m;
int way[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char str[205][205];
int cost[2][205][205];
void bfs(int idx){
    queue<Node>que;
    bool flag[205][205];
    memset(flag,false,sizeof(flag));
    flag[s[idx].x][s[idx].y]=true;
    que.push(s[idx]);
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            v.x=u.x+way[i][0];
            v.y=u.y+way[i][1];
            if(v.x>=0&&v.y>=0&&v.x<n&&v.y<m&&flag[v.x][v.y]==false&&str[v.x][v.y]!='#'){
                flag[v.x][v.y]=true;
                v.step=u.step+1;
                cost[idx][v.x][v.y]=v.step;
                que.push(v);
            }
        }
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            for(int j=0;j<m;j++)
                if(str[i][j]=='Y'){
                    s[0].x=i;
                    s[0].y=j;
                    s[0].step=0;
                }
                else if(str[i][j]=='M'){
                    s[1].x=i;
                    s[1].y=j;
                    s[1].step=0;
                }
        }
        for(int i=0;i<2;i++)
            bfs(i);
        int ans=inf;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(str[i][j]=='@')
                    ans=min(ans,cost[0][i][j]+cost[1][i][j]);
        printf("%d\n",ans*11);
    }
    return 0;
}