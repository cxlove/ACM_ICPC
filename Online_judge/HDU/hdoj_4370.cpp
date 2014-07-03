#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#define inf 1<<27
#define N 105
#define Min(a,b) ((a)<(b)?(a):(b))
#define Max(a,b) ((a)>(b)?(a):(b))
#define pb(a) push_back(a)
#define LL long long
using namespace std;
int n,path[305][305];
int dist[305],vis[305];
void Spfa(int s){
    queue<int>que;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        if(i==s) dist[i]=inf;
        else{
            dist[i]=path[s][i];
            que.push(i);
            vis[i]=1;
        }
    }
    while(!que.empty()){
        int u=que.front();
        que.pop();
        vis[u]=0;
        for(int i=0;i<n;i++){
            if(dist[i]>dist[u]+path[u][i]){
                dist[i]=dist[u]+path[u][i];
                if(!vis[i]){
                    vis[i]=1;
                    que.push(i);
                }
            }
        }
    }
}
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&path[i][j]);
        int ans,c1,c2;
        Spfa(0);
        ans=dist[n-1];
        c1=dist[0];
        Spfa(n-1);
        c2=dist[n-1];
        printf("%d\n",min(ans,c1+c2));
    }
    return 0;
}