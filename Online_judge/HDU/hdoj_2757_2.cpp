#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define inf 1<<30
using namespace std;
struct Node{
    int x,y,d;
    bool operator<(const Node t) const{    
        return d>t.d;        
    }
}u,v;
int way[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int n,m;
char str[1001][1001];
bool flag[1001][1001];
int step[1001][1001];
int main(){
    int q;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        scanf("%d",&q);
        while(q--){
            int sx,sy,ex,ey;
            scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
            sx--;sy--;ex--;ey--;
            u.x=sx;u.y=sy;u.d=0;
            priority_queue<Node> que;
            memset(flag,false,sizeof(flag));
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    step[i][j]=inf;
            step[u.x][u.y]=0;
            while(!que.empty())
                que.pop();
            que.push(u);
            flag[u.x][u.y]=true;
            while(!que.empty()){
                u=que.top();
                que.pop();
                if(u.x==ex&&u.y==ey){
                    printf("%d\n",step[ex][ey]);
                    break;
                }
                for(int i=0;i<8;i++){
                    v.x=u.x+way[i][0];
                    v.y=u.y+way[i][1];
                    if(v.x>=0&&v.x<n&&v.y>=0&&v.y<m&&!flag[v.x][v.y]){
                    //    flag[v.x][v.y]=true;
                        if(str[u.x][u.y]==i+'0')
                            v.d=u.d;
                        else
                            v.d=u.d+1;
                        if(step[v.x][v.y]>v.d){
                            que.push(v);
                            step[v.x][v.y]=v.d;
                        }
                    }                
                }
            }
        }
    }
    return 0;
}





