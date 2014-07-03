#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define LL unsigned long long
using namespace std;
int n,m,q;
int way[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};
char str[15][15][15];
bool flag[15][15][15];
struct Node{
    int x,y,z,step;
    bool check(){
        if(x>=0&&y>=0&&z>=0&&x<n&&y<n&&z<n)
            return true;
        return false;
    }
}s,e,u,v;
int bfs(){
    if(s.x==e.x&&s.y==e.y&&s.z==e.z)
        return 0;
    queue<Node>que;
    memset(flag,false,sizeof(flag));
    s.step=0;
    que.push(s);
    flag[s.x][s.y][s.z]=true;
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<6;i++){
            v=u;
            v.x+=way[i][0];
            v.y+=way[i][1];
            v.z+=way[i][2];
            v.step++;
            if(v.check()&&flag[v.x][v.y][v.z]==false){             
                flag[v.x][v.y][v.z]=true;
                if(v.x==e.x&&v.y==e.y&&v.z==e.z)
                    return v.step;
                if(str[v.x][v.y][v.z]=='X')
                    continue;
                que.push(v);
            }
        }
    }
    return -1;
}
char ch[100];
int main(){
    while(scanf("%s%d",ch,&n)!=EOF){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                    scanf("%s",str[i][j]);
        while(scanf("%s",ch)){
            if(strcmp(ch,"END")==0)
                break;
            sscanf(ch,"%d",&s.x);
            scanf("%d%d%d%d%d",&s.y,&s.z,&e.x,&e.y,&e.z);
            int ans=bfs();
            if(ans==-1)
                printf("NO ROUTE\n");
            else
                printf("%d %d\n",n,ans);
        }

    }
    return 0;
}
