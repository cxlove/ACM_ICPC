#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
struct Node{
    int x,y,step;
    bool operator<(const Node &n1)const{
        return step>n1.step;
    }
}s,e,u,v;
struct Point{
    int x,y;
}pre[105][105];
int n,m;
char str[105][105];
bool flag[105][105];
int way[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int bfs(){
    priority_queue<Node>que;
    que.push(s);
    memset(flag,false,sizeof(flag));
    flag[s.x][s.y]=true;
    while(!que.empty()){
        u=que.top();
        que.pop();
        for(int i=0;i<4;i++){
            v.x=u.x+way[i][0];
            v.y=u.y+way[i][1];
            if(v.x>=0&&v.x<n&&v.y>=0&&v.y<m&&flag[v.x][v.y]==false&&str[v.x][v.y]!='X'){
                flag[v.x][v.y]=true;
                if(str[v.x][v.y]=='.')
                    v.step=u.step+1;
                else
                    v.step=u.step+1+str[v.x][v.y]-'0';
                pre[v.x][v.y].x=u.x;
                pre[v.x][v.y].y=u.y;
                if(v.x==e.x&&v.y==e.y)
                    return v.step;
                que.push(v);
            }
        }
    }
    return -1;
}
void out(int t,int x,int y){    
    if(t<1)
       return;
    int tt=t-1;
    if(str[pre[x][y].x][pre[x][y].y]!='.')
        tt=tt-(str[pre[x][y].x][pre[x][y].y]-'0');
    out(tt,pre[x][y].x,pre[x][y].y);
    printf("%ds:(%d,%d)->(%d,%d)\n",t,pre[x][y].x,pre[x][y].y,x,y);
    if(str[x][y]!='.'){
        for(int i=t+1;i<=t+str[x][y]-'0';i++)
            printf("%ds:FIGHT AT (%d,%d)\n",i,x,y);
    }
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        s.x=s.y=s.step=0;
        e.x=n-1;e.y=m-1;
        int ans=bfs();
        if(ans==-1)
            printf("God please help our poor hero.\n");
        else{
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",ans);
            if(str[n-1][m-1]!='.')
                ans=ans-(str[n-1][m-1]-'0');
            out(ans,n-1,m-1);
        }
        printf("FINISH\n");
    }
    return 0;
}
