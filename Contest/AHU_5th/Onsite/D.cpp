#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<ctime>
#include<iostream>
#define N 1005
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
using namespace std;
int n,ret,pre[N];
vector<pair<int,int> >edge[N];
int find(int x){return pre[x]=(x==pre[x]?x:find(pre[x]));}
void Union(int a,int b){
    int ra=find(a),rb=find(b);
    if(ra!=rb) pre[ra]=rb;
}
void dfs(int pre,int u){
    if(u==1) return ;
    for(int i=0;i<edge[u].size();i++){
        int v=edge[u][i].first;
        int w=edge[u][i].second;
        if(v==pre) continue;
        ret+=w;
        dfs(u,v);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) pre[i]=i,edge[i].clear();
        for(int i=0;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            Union(u,v);
            edge[u].pb(mp(v,0));
            edge[v].pb(mp(u,w));
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(pre[i]==i)
                cnt++;
        if(cnt>1){
            puts("-1");
            continue;
        }
        int ans=0x3f3f3f3f;
        for(int i=0;i<edge[1].size();i++){
            int v=edge[1][i].first;
            ret=edge[1][i].second;
            dfs(1,v);
            ans=min(ans,ret);
        }
        printf("%d\n",ans);
    }
    //printf("%.6lf",(double)clock()/CLOCKS_PER_SEC);
    return 0;
}