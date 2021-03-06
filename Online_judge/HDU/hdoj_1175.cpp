#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
struct Node{
    int x,y,dir,cnt;
}s,e,u,v;
int n,m,mmap[1001][1001];
int way[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
bool flag[1001][1001][4];
bool bfs(){
    queue<Node>que;
    while(!que.empty())
        que.pop();
    que.push(s);
    memset(flag,false,sizeof(flag));
    flag[s.x][s.y][0]=flag[s.x][s.y][1]=flag[s.x][s.y][2]=flag[s.x][s.y][3]=true;
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            v.x=u.x+way[i][0];
            v.y=u.y+way[i][1];
            if(u.dir==-1)
                v.cnt=0;
            else if(u.dir==i)
                v.cnt=u.cnt;
            else
                v.cnt=u.cnt+1;
            v.dir=i;
            for(int k=1;;k++){
                v.x=u.x+way[i][0]*k;
                v.y=u.y+way[i][1]*k;
                if(v.x>0&&v.y>0&&v.x<=n&&v.y<=m&&v.cnt<=2&&flag[v.x][v.y][i]==0&&(mmap[v.x][v.y]==0||(v.x==e.x&&v.y==e.y))){
                    flag[v.x][v.y][i]=true;
                    if(v.x==e.x&&v.y==e.y)
                        return true;
                    que.push(v);
                }
                else
                break;
            }
        }
    }
    return false;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&mmap[i][j]);
        int q;
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d%d",&s.x,&s.y,&e.x,&e.y);
            s.cnt=0;
            s.dir=-1;
            if(mmap[s.x][s.y]!=mmap[e.x][e.y]||!mmap[s.x][s.y]||!mmap[e.x][e.y])
                printf("NO\n");
            else if(bfs())
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}

