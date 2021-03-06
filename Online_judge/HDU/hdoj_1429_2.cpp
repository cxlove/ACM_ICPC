#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define LL unsigned long long
using namespace std;
int n,m,T;
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char str[21][21];
bool flag[21][21][1024];
struct Node{
    short x,y,step;
    short key;
    bool check(){
        if(x>=0&&x<n&&y>=0&&y<m)
            return true;
        return false;
    }
}s,e,u,v;
queue<Node>que;
int bfs(){
    if(!que.empty())
        que.pop();
    que.push(s);
    memset(flag,false,sizeof(flag));
    while(!que.empty()){
        u=que.front();
        que.pop();
       
        for(int i=0;i<4;i++){
            v=u;
            v.step++;
            v.x+=way[i][0];
            v.y+=way[i][1]; 
            
              if(v.step>=T)
                break;
            if(v.check()&&str[v.x][v.y]!='*'){
                  if(str[v.x][v.y]=='^')
                    return v.step;
                if(str[v.x][v.y]>='A'&&str[v.x][v.y]<='J'){
                    if(((1<<(str[v.x][v.y]-'A'))&v.key)&&flag[v.x][v.y][v.key]==false){
                        que.push(v);
                        flag[v.x][v.y][v.key]=true;
                    }
                }
                else if(str[v.x][v.y]>='a'&&str[v.x][v.y]<='j'){
                    v.key|=(1<<(str[v.x][v.y]-'a'));
                    if(flag[v.x][v.y][v.key]==false){            
                        que.push(v);
                        flag[v.x][v.y][v.key]=true;
                    }
                }
                else{  //相当于空地
                    if(!flag[v.x][v.y][v.key]){
                        flag[v.x][v.y][v.key]=true;
                        que.push(v);
                    }
                }
            }

        }
    }
    return -1;
}
int main(){
    while(scanf("%d%d%d",&n,&m,&T)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            for(int j=0;j<m;j++){
                if(str[i][j]=='@'){
                    s.x=i;
                    s.y=j;
                    s.step=0;
                    s.key=0;
                }
            }
        }
        printf("%d\n",bfs());
    }
    return 0;
}
