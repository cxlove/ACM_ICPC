#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
struct Node{
    int x,y,step;
}s,e,u,v;
int n,m,k;
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char str[105][105];
bool flag[105][105][15];
int bfs(){
    queue<Node>que;
    que.push(s);
    memset(flag,false,sizeof(flag));
    flag[s.x][s.y][0]=true;
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            v.x=u.x+way[i][0];
            v.y=u.y+way[i][1];
            if(v.x>=0&&v.y>=0&&v.x<n&&v.y<m&&flag[v.x][v.y][(u.step+1)%k]==false&&(str[v.x][v.y]!='#'||(u.step+1)%k==0)){
                v.step=u.step+1;
                flag[v.x][v.y][v.step%k]=true;
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
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            for(int j=0;j<m;j++)
                if(str[i][j]=='Y'){
                    s.x=i;
                    s.y=j;
                    s.step=0;
                }
                else if(str[i][j]=='G'){
                    e.x=i;
                    e.y=j;
                }
        }
        int ans=bfs();
        if(ans==-1)
            printf("Please give me another chance!\n");
        else
            printf("%d\n",bfs());
    }
    return 0;
}


