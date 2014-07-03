#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define LL unsigned long long
using namespace std;
int n,m;
int way[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char str[25][25];
bool flag[25][25];
struct Node{
    int x,y,step;
    bool check(){
        if(x>=0&&x<n&&y>=0&&y<m)
            return true;
        return false;
    }
    bool operator<(const Node n1)const{
        return step>n1.step;
    }
}s,e,u,v;
int bfs(){
    priority_queue<Node>que;
    que.push(s);
    memset(flag,false,sizeof(flag));
    flag[s.x][s.y]=true;
    while(!que.empty()){
        u=que.top();
        que.pop();
        for(int i=0;i<4;i++){
            v=u;
            v.x+=way[i][0];
            v.y+=way[i][1];
            v.step++;
            if(v.check()&&flag[v.x][v.y]==false&&str[v.x][v.y]!='*'){
                
                if(str[v.x][v.y]=='|'){
                    if(i>1&&(u.step%2)==1){
                        v.x+=way[i][0];
                        v.y+=way[i][1];
                        if(v.check()&&flag[v.x][v.y]==false&&str[v.x][v.y]!='*'){
                            flag[v.x][v.y]=true;
                            que.push(v);
                        }
                    }
                    else if(i<2&&(u.step%2)==0){
                        v.x+=way[i][0];
                        v.y+=way[i][1];
                        if(v.check()&&flag[v.x][v.y]==false&&str[v.x][v.y]!='*'){
                            flag[v.x][v.y]=true;
                            que.push(v);
                        }
                    }
                    else{
                        v.x+=way[i][0];
                        v.y+=way[i][1];
                        v.step++;
                        if(v.check()&&flag[v.x][v.y]==false&&str[v.x][v.y]!='*'){
                            flag[v.x][v.y]=true;
                            que.push(v);
                        }
                    }
                }
                else if(str[v.x][v.y]=='-'){
                    if(i>1&&(u.step%2)==0){
                        v.x+=way[i][0];
                        v.y+=way[i][1];
                        if(v.check()&&flag[v.x][v.y]==false&&str[v.x][v.y]!='*'){
                            flag[v.x][v.y]=true;
                            que.push(v);
                        }
                    }
                    else if(i<2&&(u.step%2)==1){
                        v.x+=way[i][0];
                        v.y+=way[i][1];
                        if(v.check()&&flag[v.x][v.y]==false&&str[v.x][v.y]!='*'){
                            flag[v.x][v.y]=true;
                            que.push(v);
                        }
                    }
                    else{
                        v.x+=way[i][0];
                        v.y+=way[i][1];
                        v.step++;
                        if(v.check()&&flag[v.x][v.y]==false&&str[v.x][v.y]!='*'){
                            flag[v.x][v.y]=true;
                            que.push(v);
                        }
                    }
                }
                else{
                     flag[v.x][v.y]=true;
                    que.push(v);
                }
                if(str[v.x][v.y]=='T')
                    return v.step;
            }
        }
    }
    return -1;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            for(int j=0;j<m;j++)
                if(str[i][j]=='S'){
                    s.x=i;
                    s.y=j;
                    s.step=0;
                }
        }
        printf("%d\n",bfs());
    }
    return 0;
}




