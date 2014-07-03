#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
struct Node{
    int x,y;
}s,u,v;
int way[4][2]={0,1,0,-1,1,0,-1,0};
int n,m,sum,ans;
int a[305][305];
int flag[305][305];
bool ok;
void bfs(int k){
    flag[s.x][s.y]=2;
    queue<Node>que;
    que.push(s);
    while(!que.empty()){
        u=que.front();
        que.pop();
        for(int i=0;i<4;i++){
            v.x=u.x+way[i][0];
            v.y=u.y+way[i][1];
            if(v.x<1||v.y<1||v.x>n||v.y>m){
                if(k==0) {ok=true;return ;}
                else continue;
            }
            if(k==0){
                if(flag[v.x][v.y]) continue;
                if(a[v.x][v.y]==0) que.push(v);
                flag[v.x][v.y]=1;
            }
            else{
                if(flag[v.x][v.y]==2) continue;
                if(flag[v.x][v.y]==0) {que.push(v);ans+=a[v.x][v.y];}
                else if(a[v.x][v.y]) ans+=a[v.x][v.y]-1;
                flag[v.x][v.y]=2;
                
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF){
        ans=0;ok=false;
        memset(flag,0,sizeof(flag));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                scanf("%d",&a[i][j]);
                sum+=a[i][j];
                if(a[i][j]==-1)
                    s.x=i,s.y=j;
            }
        bfs(0);
        if(ok) {puts("Ali Win");continue;}
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=m+1;j++)
                if(i==0||j==0||i==n+1||j==m+1){
                    s.x=i;s.y=j;
                    bfs(1);
                }
        }
        puts(ans&1?"Ali Win":"Baba Win");
    }
    return 0;
}