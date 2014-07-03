#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<vector>
#define C    240
#define TIME 10
#define inf 1<<25
#define LL long long
using namespace std;
vector<int>edge[105];
int mat[105][105];
int low[105],dfa[105];
int s[105],top;
bool instack[105];
bool vis[105];
void Tarjan(int u,int pre,int depth){
    low[u]=dfa[u]=depth;
    s[top++]=u;
    instack[u]=true;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(v==pre&&mat[u][v]>1){
            if(mat[u][v]%2==0)
                vis[u]=true;
            continue;
        }
        if(!dfa[v]){
            Tarjan(v,u,depth+1);
            low[u]=min(low[u],low[v]);
        }
        else if(v!=pre&&instack[v])
            low[u]=min(low[u],dfa[v]);
    }
    if(dfa[u]==low[u]){
        int cnt=1;
        top--;
        while(s[top]!=u){
            vis[s[top--]]=true;
            cnt++;
        }
        if(cnt&&(cnt&1))
            vis[s[top+1]]=false;
    }
}
int get_sg(int u,int pre){
    int ret=0;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i];
        if(!vis[v]&&v!=pre)
            ret^=(1+get_sg(v,u));
    }
    return ret;
}
int main(){
    int k,n,m;
    while(scanf("%d",&k)!=EOF){
        int ret=0;
        while(k--){
            scanf("%d%d",&n,&m);
            for(int i=1;i<=n;i++)
                edge[i].clear();
            memset(mat,0,sizeof(mat));
            memset(low,0,sizeof(low));
            memset(dfa,0,sizeof(dfa));
            memset(instack,false,sizeof(instack));
            memset(vis,false,sizeof(vis));
            top=0;
            while(m--){
                int u,v;
                scanf("%d%d",&u,&v);
                mat[u][v]++;
                mat[v][u]++;
                edge[u].push_back(v);
                edge[v].push_back(u);
            }
            Tarjan(1,-1,1);
            ret^=get_sg(1,-1);
        }
        puts(ret?"Sally":"Harry");
    }
    return 0;
}









