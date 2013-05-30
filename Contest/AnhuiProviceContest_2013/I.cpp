#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m,a[55][55];
int dist[55][55];
bool vis[55][55];
int way[4][2]={0,1,0,-1,1,0,-1,0};
void spfa(){
    memset(vis,false,sizeof(vis));
    queue<pair<int,int> >que;
    que.push(mp(n,m));
    memset(dist,0x11,sizeof(dist));
    dist[n][m]=a[n][m]; 
    while(!que.empty()){
        pair<int,int>u=que.front(),v;
        que.pop();
        vis[u.first][u.second]=false;
        for(int i=0;i<4;i++){
            v.first=u.first+way[i][0];
            v.second=u.second+way[i][1];
            if(v.first>=1&&v.second>=1&&v.first<=n&&v.second<=m){
                if(dist[v.first][v.second]>dist[u.first][u.second]+a[v.first][v.second]){
                    dist[v.first][v.second]=dist[u.first][u.second]+a[v.first][v.second];
                    if(vis[v.first][v.second]==false){
                        vis[v.first][v.second]=true;
                        que.push(v);
                    }
                }
            }
        }
    }
}
long long dp[55][55];
long long DP(int x,int y){
    if(dp[x][y]!=-1) return dp[x][y];
    dp[x][y]=0;
    for(int i=0;i<4;i++){
        int xx=x+way[i][0],yy=y+way[i][1];
        if(xx>=1&&yy>=1&&xx<=n&&yy<=m&&dist[xx][yy]>dist[x][y]){
            dp[x][y]+=DP(xx,yy);
        }
    }
    return dp[x][y];
}
int main(){
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        memset(dp,-1,sizeof(dp));
        spfa();
        dp[1][1]=1LL;
        printf("%I64d\n",DP(n,m));
    }
    return 0;
}