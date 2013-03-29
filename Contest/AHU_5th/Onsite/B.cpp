#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-10
#define LL long long
#define LD long double
#define pi acos(-1.0)
using namespace std;
struct Node{
    int x,y;
}s,u,v,tt;
int n,m,t;
int way[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool flag[1505][1505];
int vis[1505][1505][2];
char str[1505][1505];
bool bfs(){
    queue<Node>que;
    que.push(s);
    memset(flag,false,sizeof(flag));
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            v=u;
            v.x+=way[i][0];
            v.y+=way[i][1];
            tt.x=((v.x%n)+n)%n;
            tt.y=((v.y%m)+m)%m;
            if(str[tt.x][tt.y]=='#')
                continue;
            if(flag[tt.x][tt.y]){
                if(v.x!=vis[tt.x][tt.y][0]||v.y!=vis[tt.x][tt.y][1])
                    return true;
            }
            else{
                flag[tt.x][tt.y]=true;
                vis[tt.x][tt.y][0]=v.x;
                vis[tt.x][tt.y][1]=v.y;
                que.push(v);
            }
        }
    }
    return false;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++){
            scanf("%s",str[i]);
            for(int j=0;j<m;j++)
                if(str[i][j]=='S'){
                    s.x=i;
                    s.y=j;
                }
        }
        printf("%s\n",bfs()?"YES":"NO");
    }
    return 0;
}