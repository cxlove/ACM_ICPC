#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define mp(a,b) make_pair(a,b)
using namespace std;
const int N = 105;
const int M = 10005;
struct Edge{
    int v,w,next,c;
}e[M];
int k,n,r;
int in[N],start[N],tot,dp[N][M];
void add(int u,int v,int w,int c){
    e[tot].v=v;e[tot].w=w;e[tot].c=c;
    e[tot].next=start[u];start[u]=tot++;
}
int spfa(){
    memset(in,0,sizeof(in));
    memset(dp,0x11,sizeof(dp));
    queue<int>que;
    que.push(1);
    dp[1][0]=0;
    in[1]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        in[u]=0;
        for(int i=start[u];i!=-1;i=e[i].next){
            int w=e[i].w,v=e[i].v,c=e[i].c;
            for(int j=c;j<=k;j++){
                if(dp[v][j]>dp[u][j-c]+w){
                    dp[v][j]=dp[u][j-c]+w;
                    if(!in[v]){
                        in[v]=1;
                        que.push(v);
                    }
                }
            }
        }
    }
    int ans=0x11111111;
    for(int i=0;i<=k;i++)
        ans=min(ans,dp[n][i]);
    return ans==0x11111111?-1:ans;
}
int main(){
    while(scanf("%d%d%d",&k,&n,&r)!=EOF){
        tot=0;memset(start,-1,sizeof(start));
        for(int i=0;i<r;i++){
            int u,v,w,c;
            scanf("%d%d%d%d",&u,&v,&w,&c);
            add(u,v,w,c);
        }
        printf("%d\n",spfa());
    }
    return 0;
}