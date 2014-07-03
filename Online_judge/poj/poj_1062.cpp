#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <climits>
#include <vector>
#include <queue>
#define LL long long 
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define pii pair<int,int>
using namespace std;
const int N = 105;
int limit,n;
vector<pii >a[N];
int cost[N],k[N],level[N];
int spfa(int l,int r){
    int dist[N],in[N];
    memset(in,0,sizeof(in));
    queue<int>que;
    for(int i=1;i<=n;i++){
        dist[i]=cost[i];
        que.push(i);
        in[i]=true;
    }
    while(!que.empty()){
        int u=que.front();
        que.pop();
        if(level[u]<l||level[u]>r) continue;
        in[u]=false;
        for(int i=0;i<a[u].size();i++){
            int v=a[u][i].first,w=a[u][i].second;
            if(level[v]<l||level[v]>r) continue;
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                if(!in[v]){
                    in[v]=true;
                    que.push(v);
                }
            }
        }
    }
    return dist[1];
}
int main(){
    while(scanf("%d%d",&limit,&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&cost[i],&level[i],&k[i]);
            for(int j=0;j<k[i];j++){
                int idx,money;
                scanf("%d%d",&idx,&money);
                a[idx].pb(mp(i,money));
            }
        }
        int ans=cost[1];
        for(int i=1;i<=n;i++){
            int l=level[i],r=level[i]+limit;
            if(l<=level[i]&&level[i]<=r){
                ans=min(ans,spfa(l,r));
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}