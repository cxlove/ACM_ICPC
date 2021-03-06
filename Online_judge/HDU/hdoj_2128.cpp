#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define LL unsigned long long
using namespace std;
int n,m;
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char mmap[10][10];
int wallcnt,wallmap[10][10];
int bombcnt,bombmap[10][10];
struct Node{
    int x,y,step,bomb;
    LL vis;
    LL wall;
    //bool vis[8][8];
    //bool wall[8][8];
    bool check(){
        if(x>=0&&y>=0&&x<n&&y<m)
            return true;
        return false;
    }
    bool operator<(const Node n1) const{
        return step>n1.step;
    }
}s,e,u,v;
vector<Node>flag[8][8][8*8*9+1];
//bool ok(Node n1,Node n2){
//    for(int i=0;i<n;i++)
//        for(int j=0;j<m;j++)
//            if(n1.wall[i][j]!=n2.wall[i][j])
//                return false;
//    return true;
//}
bool check(Node tmp){
    for(int i=0;i<flag[tmp.x][tmp.y][tmp.bomb].size();i++)
        if(tmp.wall==flag[tmp.x][tmp.y][tmp.bomb][i].wall&&tmp.vis==flag[tmp.x][tmp.y][tmp.bomb][i].vis)
            return false;
    return true;
}
int bfs(){
    priority_queue<Node>que;
    que.push(s);
    while(!que.empty()){
        u=que.top();
        que.pop();
        for(int i=0;i<4;i++){
            v=u;
            v.step++;
            v.x=u.x+way[i][0];
            v.y=u.y+way[i][1];
            if(v.check()){
                if(mmap[v.x][v.y]=='D')
                    return v.step;
                if(mmap[v.x][v.y]=='X'&&((1LL<<wallmap[v.x][v.y])&v.wall)){
                    if(v.bomb>0){
                           
                        v.bomb--;
                        v.step++;
                        v.wall^=(1LL<<wallmap[v.x][v.y]);
                        que.push(v);
                        flag[v.x][v.y][v.bomb].push_back(v);
                    }    
                }
                else if(mmap[v.x][v.y]>='1'&&mmap[v.x][v.y]<='9'&&(v.vis&(1LL<<bombmap[v.x][v.y]))==0){
                    v.bomb+=mmap[v.x][v.y]-'0';
                    v.vis|=(1LL<<bombmap[v.x][v.y]);
                    que.push(v);
                    flag[v.x][v.y][v.bomb].push_back(v);
                }
                else{
                    if(flag[v.x][v.y][v.bomb].empty()||check(v)){
                        flag[v.x][v.y][v.bomb].push_back(v);
                        que.push(v);
                    }
                }        
                //        cout<<v.x<<" "<<v.y<<" "<<v.step<<" "<<v.bomb<<endl;
            }

        }
    }
    return -1;
}
int main(){
    while(scanf("%d%d",&n,&m)!=EOF&&n+m){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                for(int k=0;k<=(n*m*9);k++)
                    if(!flag[i][j][k].empty())
                        flag[i][j][k].clear();
        bombcnt=wallcnt=0;
        memset(wallmap,-1,sizeof(wallmap));
        memset(bombmap,-1,sizeof(bombmap));
        for(int i=0;i<n;i++){
            scanf("%s",mmap[i]);
            for(int j=0;j<m;j++)
                if(mmap[i][j]=='S'){
                    s.x=i;
                    s.y=j;
                    s.step=0;
                    s.bomb=0;
                }
                else if(mmap[i][j]=='D'){
                    e.x=i;
                    e.y=j;
                }
                else if(mmap[i][j]=='X')
                    wallmap[i][j]=wallcnt++;
                else if(mmap[i][j]>='1'&&mmap[i][j]<='9')
                    bombmap[i][j]=bombcnt++;
        }
        //    cout<<bombcnt<<" "<<wallcnt<<endl;
        s.wall=(1LL<<wallcnt)-1;
        s.vis=0;
        printf("%d\n",bfs());
    }
    return 0;
}




