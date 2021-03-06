#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
struct Node{
    int x,y,step,cnt;
}s,e,u,v;
int n,m,mmap[1001][1001];
int way[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
bool flag[10][10][10];
int bfs(){
    queue<Node>que;
    while(!que.empty())
        que.pop();
    que.push(s);
    memset(flag,false,sizeof(flag));
    flag[s.x][s.y][6]=1;
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            v.x=u.x+way[i][0];
            v.y=u.y+way[i][1];
            v.cnt=u.cnt-1;
            v.step=u.step+1;
            if(v.cnt>=1&&v.x>=0&&v.y>=0&&v.x<n&&v.y<m&&flag[v.x][v.y][v.cnt]==false&&mmap[v.x][v.y]!=0){
                flag[v.x][v.y][v.cnt]=true;
                if(mmap[v.x][v.y]==4)
                    v.cnt=6;
                if(v.x==e.x&&v.y==e.y)
                    return v.step;
                que.push(v);
            }
        }
    }
    return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d",&mmap[i][j]);
                if(mmap[i][j]==2){
                    s.x=i;
                    s.y=j;
                    s.cnt=6;
                    s.step=0;
                }
                else if(mmap[i][j]==3){
                    e.x=i;
                    e.y=j;
                }
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}
