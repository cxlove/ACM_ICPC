#include<iostream>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<vector>
#include<cstring>
#define N 50005
#define pb(a) push_back(a)
using namespace std;
int n,r1,r2,tt;
int pre[N];
vector<int>t[N];
vector<int>edge[N];
void dfs_1(int u){
    for(int i=0;i<t[u].size();i++){
        int v=t[u][i];
        edge[u].pb(v);
        edge[v].pb(u);
        dfs_1(v);
    }
}
void dfs_2(int fa,int u){
    pre[u]=fa;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(v==fa) continue;
        dfs_2(u,v);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d",&tt);
    while(tt--){
        scanf("%d%d%d",&n,&r1,&r2);
        for(int i=1;i<=n;i++){
            t[i].clear();
            edge[i].clear();
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&pre[i]);
            t[pre[i]].pb(i);
        }
        dfs_1(r1);
        dfs_2(-1,r2);
        for(int i=1;i<=n;i++){
            printf("%d%c",pre[i],i<n?' ':'\n');
        }
    }
    //printf("%.6lf",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}