#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
char str[2][15][15];
int n,m,flag[2][15][15],T;
int way[6][3]={{0,1,0},{0,-1,0},{0,0,1},{0,0,-1},{1,0,0},{-1,0,0}};
struct Node{
    int x,y,z,step;
    bool check(){
        if(x>=0&&x<2&&y>=0&&y<n&&z>=0&&z<m)
            return true;
        return false;
    }
    bool operator<(const Node n1)const{
        return step>n1.step;
    }
}s,e,u,v;
bool bfs(){
    priority_queue<Node>que;
    memset(flag,0,sizeof(flag));
    flag[s.x][s.y][s.y]=1;
    que.push(s);
    while(!que.empty()){
        u=que.top();
        que.pop();
        if(u.step>T)
            continue;
        for(int i=0;i<6;i++){
            v=u;
            if(i>=4&&str[u.x][u.y][u.z]!='#')
                continue;
            if(str[u.x][u.y][u.z]=='#'&&i<4)
                continue;
            v.x+=way[i][0];
            v.y+=way[i][1];
            v.z+=way[i][2];
            if(v.check()&&flag[v.x][v.y][v.z]==0&&str[v.x][v.y][v.z]!='*'){
                flag[v.x][v.y][v.z]=1;
                if(i>=4&&str[v.x][v.y][v.z]=='#')
                    continue;
                if(i<4)
                    v.step++;
                if(str[v.x][v.y][v.z]=='P'&&v.step<=T)
                    return true;
                que.push(v);
            }
        }
    }
    return false;
}                
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&T);
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                scanf("%s",str[i][j]);
                for(int k=0;k<m;k++)
                    if(str[i][j][k]=='S'){
                        s.x=i;
                        s.y=j;
                        s.z=k;
                        s.step=0;
                    }
            }
        }
        if(bfs())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

