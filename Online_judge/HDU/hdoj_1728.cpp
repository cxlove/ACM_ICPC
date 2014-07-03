#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define LL unsigned long long
using namespace std;
int n,m,k;
int way[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char str[105][105];
bool flag[105][105];
struct Node{
    int x,y,dir,cnt;
    bool check(){
        if(x>=0&&x<n&&y>=0&&y<m)
            return true;
        return false;
    }
}s,e,u,v;
int bfs(){
    queue<Node>que;
    que.push(s);
    memset(flag,false,sizeof(flag));
    flag[s.x][s.y]=true;
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            v.cnt=u.cnt;
            if(u.dir!=-1&&u.dir!=i)
                v.cnt++;
            if(v.cnt>k)
                continue;    
            v.dir=i;
            for(int j=1;;j++){
                v.x=u.x+way[i][0]*j;
                v.y=u.y+way[i][1]*j;
                if(v.check()&&str[v.x][v.y]!='*'){
                    if(flag[v.x][v.y])
                        continue;
                    flag[v.x][v.y]=true;
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
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        scanf("%d%d%d%d%d",&k,&s.y,&s.x,&e.y,&e.x);
        s.x--;s.y--;e.x--;e.y--;
        s.cnt=0;s.dir=-1;
        if((s.x==e.x&&s.y==e.y)||bfs())
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}