#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define inf 1<<29
#define LL long long
#define N 1000000000
#define pb(a) push_back(a)
#define MOD 10007
using namespace std;
int n,m;
struct Node{
    int x,y,t;
    bool check(){
        if(x>=0&&x<n&&y>=0&&y<m)
           return true;
        return false;
    }
    bool operator<(const Node n1)const{
        return t>n1.t;
    }
}s,u,v;
int sx,sy,tx,ty;
int vp,vs,vt;
int way[4][2]={-1,0,1,0,0,1,0,-1};
char str[100][100];
bool flag[100][100];
int bfs(){
    if(s.x==tx&&s.y==ty) return 0;
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
            if(v.check()&&!flag[v.x][v.y]&&str[v.x][v.y]!='@'){
                 if(str[v.x][v.y]=='T')  v.t+=vt;
                else if(str[v.x][v.y]=='.') v.t+=vs;
                else v.t+=vp;
                if(v.x==tx&&v.y==ty)  return v.t;
                flag[v.x][v.y]=true;
                que.push(v);
            }

        }
    }
    return -1;
}
int main(){
    int cas=0;
    while(scanf("%d%d",&n,&m)!=EOF){
        scanf("%d%d%d",&vp,&vs,&vt);
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        scanf("%d%d%d%d",&s.x,&s.y,&tx,&ty);
        s.t=0;
        printf("Case %d: %d\n",++cas,bfs());
    }
    return 0;
}

